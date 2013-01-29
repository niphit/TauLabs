/**
 ******************************************************************************
 *
 * @file       i2c_vm.cpp
 * @author     Tau Labs, http://www.taulabs.org, Copyright (C) 2013
 * @addtogroup GCSPlugins GCS Plugins
 * @{
 * @addtogroup I2C_VMPlugin
 * @{
 * @brief
 *****************************************************************************/

/*
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
 * or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License
 * for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, write to the Free Software Foundation, Inc.,
 * 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
 */
#include "i2c_vm.h"
#include "i2c_vmwidget.h"
#include "../../../../../shared/lib/gen_i2c_vm.h" //<------ICK, UGLY

#include "extensionsystem/pluginmanager.h"
//#include "uavobjectmanager.h"
//#include "uavobject.h"
//#include "uavobjectfield.h"
//#include "uavobjectutilmanager.h"

#include "i2cvmuserprogram.h"
#include <QDebug>

using namespace std;


I2C_VM::I2C_VM(QString classId, I2C_VMWidget *widget, QWidget *parent) :
    IUAVGadget(classId, parent),
    m_widget(widget)
{
}

I2C_VM::~I2C_VM()
{
    delete m_widget;
}

void generateVmCode(int i2c_addr, vector<VMInstructionForm*> formList)
{

    qDebug() << "Loading UAVO for I2C compiler";

    //Get UAVO
    ExtensionSystem::PluginManager* pm = ExtensionSystem::PluginManager::instance();
    UAVObjectManager* objManager = pm->getObject<UAVObjectManager>();

    I2CVMUserProgram *i2c_vmSensorSettings = I2CVMUserProgram::GetInstance(objManager);
    Q_ASSERT(i2c_vmSensorSettings);
    I2CVMUserProgram::DataFields i2c_vmSensorSettingsData = i2c_vmSensorSettings->getData();

    UAVObjectField *programField=i2c_vmSensorSettings->getField("Program");

    //Compile virtual machine program
    qDebug() << "Processing " << formList.size() << " instructions.";

    //Determine program length
    int programLength=formList.size();

    vector<uint32_t> i2cAddrProgram;
    vector<uint32_t> i2cReadProgram;
    vector<uint32_t> i2cWriteProgram;
    vector<uint32_t> i2cJumpProgram;
    vector<uint32_t> i2cSendUAVOProgram;
    vector<uint32_t> i2cDelayProgram;
    vector<uint32_t> i2cNoneProgram;

    vector< vector < uint32_t > > programComponents;
    vector<uint8_t> programComponentsIdx;

    //Add setting I2C address as first operation
    i2cAddrProgram.push_back(I2C_VM_ASM_SET_DEV_ADDR(i2c_addr));
    programComponents.push_back(i2cAddrProgram);
    programComponentsIdx.push_back(I2C_VM_OP_SET_DEV_ADDR);

    for (int i=0; i<programLength; i++){
//        qDebug() << "Instruction to I2C virtual machine compiler: " << formList[i]->getInstructionType();
        if(formList[i]->getInstructionType()=="None"){
            qDebug() << "'None' instruction";
            programComponentsIdx.push_back(I2C_VM_OP_NOP);
            i2cNoneProgram.clear();
            i2cNoneProgram.push_back(I2C_VM_ASM_NOP());
            programComponents.push_back(i2cNoneProgram);
        }
        if(formList[i]->getInstructionType()=="Delay [ms]"){
            i2cDelayProgram.clear();
            programComponentsIdx.push_back(I2C_VM_OP_DELAY);

            qDebug() << "Wait " << formList[i]->getDelayInstruction() << " ms.";
            i2cDelayProgram.push_back(I2C_VM_ASM_DELAY(formList[i]->getDelayInstruction()));
            programComponents.push_back(i2cDelayProgram);
        }
        else if(formList[i]->getInstructionType()=="Read"){
            i2cReadProgram.clear();
            programComponentsIdx.push_back(I2C_VM_OP_READ);

            int numReadBytes;
            vector<int> outputFormatInt;
            vector<QString> outputFormatStr;
            formList[i]->getReadInstruction(&numReadBytes);
            formList[i]->getOutputInstruction(&outputFormatInt, &outputFormatStr);

            qDebug() << "Reading " << numReadBytes << " bytes.";

            i2cReadProgram.push_back(I2C_VM_ASM_READ_I2C(numReadBytes));   //Read bytes

            for (unsigned int j=0; j< outputFormatInt.size()/2; j++){
                uint8_t reg;
                if(outputFormatStr[2*j]=="r0")
                    reg=VM_R0;
                else if (outputFormatStr[2*j]=="r1")
                    reg=VM_R1;
                else if (outputFormatStr[2*j]=="r2")
                    reg=VM_R2;
                else if (outputFormatStr[2*j]=="r3")
                    reg=VM_R3;
                if(outputFormatStr[2*j]=="f0")
                    reg=VM_F0;
                else if (outputFormatStr[2*j]=="f1")
                    reg=VM_F1;
                else if (outputFormatStr[2*j]=="f2")
                    reg=VM_F2;
                else if (outputFormatStr[2*j]=="f3")
                    reg=VM_F3;

                if(outputFormatStr[2*j+1]=="Little endian"){
//                    qDebug()<< "LE, Reg" << reg << ", " << outputFormatInt[2*j] <<":"<< outputFormatInt[2*j+1]-outputFormatInt[2*j];
                    i2cReadProgram.push_back(I2C_VM_ASM_LOAD_LE(outputFormatInt[2*j], outputFormatInt[2*j+1]-outputFormatInt[2*j], reg)); //Load formatted bytes into first output register
                }
                else{
//                    qDebug()<< "BE, Reg" << reg << ", " << outputFormatInt[2*j] <<":"<< outputFormatInt[2*j+1]-outputFormatInt[2*j];
                    i2cReadProgram.push_back(I2C_VM_ASM_LOAD_BE(outputFormatInt[2*j], outputFormatInt[2*j+1]-outputFormatInt[2*j], reg)); //Load formatted bytes into first output register
                }
            }
            programComponents.push_back(i2cReadProgram);
        }
        else if(formList[i]->getInstructionType()=="Write"){
            i2cWriteProgram.clear();
            programComponentsIdx.push_back(I2C_VM_OP_WRITE);

            vector<int> val;
            formList[i]->getWriteInstruction(&val);

            qDebug() << "Writing " << val.size() << " bytes.";

            for (unsigned int j=0; j< val.size(); j++){
                qDebug()<< val[j];
                i2cWriteProgram.push_back(I2C_VM_ASM_STORE(val[j], j)); //Store register address
            }
            i2cWriteProgram.push_back(I2C_VM_ASM_WRITE_I2C(val.size())); //Write bytes
            programComponents.push_back(i2cWriteProgram);
        }
        else if(formList[i]->getInstructionType()=="Jump to line"){
            i2cJumpProgram.clear();
            programComponentsIdx.push_back(I2C_VM_OP_JUMP);

            int relativeJump;
            int numJumps;
            formList[i]->getJumpInstruction(&relativeJump, &numJumps);

            qDebug() << "Relative jump of " << relativeJump << " instructions, " << numJumps << " times.";

            i2cJumpProgram.push_back(numJumps); //This code must remain pseudo-code until the entire program is done, otherwise the jumps will point to the wrong space
            i2cJumpProgram.push_back(relativeJump);
            programComponents.push_back(i2cJumpProgram);
        }
        else if(formList[i]->getInstructionType()=="Send UAVO"){
            i2cSendUAVOProgram.clear();
            programComponentsIdx.push_back(I2C_VM_OP_SEND_UAVO);

            i2cSendUAVOProgram.push_back(I2C_VM_ASM_SEND_UAVO());
            programComponents.push_back(i2cSendUAVOProgram);
        }
    }


//    vector<uint8_t>::iterator it1;

//    for (it1=programComponentsIdx.begin(); it1<programComponentsIdx.end(); it1++)
//      qDebug() << " " << *it1;

//    qDebug() << " size " << programComponentsIdx.size();

    vector<uint32_t> program;
    vector<uint8_t> programIdx;

    for (unsigned int i=0; i<programComponentsIdx.size(); i++){
        programIdx.push_back(program.size()); //Save the location of each element
        int relJump, numJumps;

        switch(programComponentsIdx[i]){
        case I2C_VM_OP_NOP:
            program.insert(program.end(), programComponents[i].begin(), programComponents[i].end());
            break;
        case I2C_VM_OP_SET_DEV_ADDR:
            program.insert(program.end(), programComponents[i].begin(), programComponents[i].end());
            break;
        case I2C_VM_OP_DELAY:
            program.insert(program.end(), programComponents[i].begin(), programComponents[i].end());
            break;
        case I2C_VM_OP_READ:
            program.insert(program.end(), programComponents[i].begin(), programComponents[i].end());
            break;
        case I2C_VM_OP_WRITE:
            program.insert(program.end(), programComponents[i].begin(), programComponents[i].end());
            break;
        case I2C_VM_OP_JUMP:
            relJump=programIdx[i+programComponents[i].at(1)]-programIdx[i];
            numJumps=programComponents[i].at(0);
            if (numJumps==-1){
                program.insert(program.end(), I2C_VM_ASM_JUMP(relJump));
            }
            else{
                program.insert(program.end()+relJump, I2C_VM_ASM_SET_CTR(numJumps));
                program.insert(program.end(), I2C_VM_ASM_DEC_CTR());
                program.insert(program.end(), I2C_VM_ASM_BNZ(relJump-1));
            }
            break;
        case I2C_VM_OP_SEND_UAVO:
            program.insert(program.end(), programComponents[i].begin(), programComponents[i].end());
            break;
        default:
            //HUH??? HOW DID WE GET HERE? WHAT DO WE DO NOW? CRASH THE PROGRAM?
            qDebug()<< "Default?!! How did we get here?";
            break;
        }
    }

//    vector<uint32_t>::iterator it;

//    for (it=program.begin(); it<program.end(); it++)
//      qDebug() << " " << *it;
//    qDebug() << " size " << program.size();


    if (program.size() > programField->getNumElements()){
        //THROW ERROR OF SOME KIND
        qDebug() << "Program too long!";
        return;
    }
    else{
        //Reset all usused bytes in program to HALT
        for (unsigned int i=program.size(); i<programField->getNumElements(); i++){
            program.push_back(I2C_VM_ASM_HALT());
        }
    }

    qDebug() << "Saving I2C compiler to UAVO";
    for (unsigned int i=0; i<program.size(); i++){
        i2c_vmSensorSettingsData.Program[i]=program[i];
    }
    i2c_vmSensorSettings->setData(i2c_vmSensorSettingsData);
}

/*
I2C_VM_ASM_NOP(), //Do nothing

I2C_VM_ASM_SET_CTR(10), //Set counter to 10
I2C_VM_ASM_SET_DEV_ADDR(0x53), //Set I2C device address (in 7-bit)
I2C_VM_ASM_STORE(0x2D, 0), //Store register address
I2C_VM_ASM_STORE(0x08, 1), //Store register value
I2C_VM_ASM_WRITE_I2C(2), //Write two bytes
I2C_VM_ASM_DEC_CTR(), //Decrement counter
I2C_VM_ASM_BNZ(-4), //If the counter is not zero, go back four steps

I2C_VM_ASM_SET_DEV_ADDR(0x53), //Set I2C device address (in 7-bit)
I2C_VM_ASM_STORE(0x32, 0), //Store register address
I2C_VM_ASM_WRITE_I2C(1),  //Write one bytes
I2C_VM_ASM_DELAY(50), //Delay 50ms
I2C_VM_ASM_READ_I2C(6),   //Read six bytes
I2C_VM_ASM_LOAD_LE(0, 2, VM_R0), //Load formatted bytes into first output register
I2C_VM_ASM_LOAD_LE(2, 2, VM_R1), //Load formatted bytes into second output register

I2C_VM_ASM_SET_DEV_ADDR(0x27), //Set I2C device address (in 7-bit)

I2C_VM_ASM_SEND_UAVO(), //Set the UAVObjects
I2C_VM_ASM_JUMP(-9),    //Jump back 9 steps
*/
