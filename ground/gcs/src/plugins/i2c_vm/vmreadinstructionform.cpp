/**
 ******************************************************************************
 *
 * @file       vmreadinstructionform.h
 * @author     The OpenPilot Team, http://www.openpilot.org Copyright (C) 2012.
 * @addtogroup GCSPlugins GCS Plugins
 * @{
 * @addtogroup VMReadInstructionForm
 * @{
 * @brief I2C_VM virtual machine instruction form
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

//#include "vminstructionform.h"
#include "vmreadinstructionform.h"
//#include "i2c_vmwidget.h"
#include "i2cvm.h"
#include "extensionsystem/pluginmanager.h"

#include <QDebug>
#include <QHBoxLayout>
#include <QSpacerItem>

VMReadInstructionForm::VMReadInstructionForm(const int index, QWidget *parent) :
    QWidget(parent),
    ui(),
    m_index(index)
{
    //--------------------------//
    // Setup widget environment //
    //--------------------------//
    //Setup GUI
    ui.setupUi(this);

    //Get UAVO
    ExtensionSystem::PluginManager* pm = ExtensionSystem::PluginManager::instance();
    UAVObjectManager* objManager = pm->getObject<UAVObjectManager>();

    I2CVM *i2c_vmSensor = I2CVM::GetInstance(objManager);
    Q_ASSERT(i2c_vmSensor);

    QStringList outputRegisterList;
    QList<UAVObjectField*> i2c_vmSensorFields=i2c_vmSensor->getFields();
    foreach(UAVObjectField* sensorField, i2c_vmSensorFields){
        outputRegisterList << sensorField->getName();
    }
    ui.outputRegisterComboBox->addItems(outputRegisterList);
    ui.outputRegisterComboBox->setCurrentIndex(0);
}

VMReadInstructionForm::~VMReadInstructionForm()
{
    // Do nothing
}


/**
 * @brief VMReadInstructionForm::setNumReadBytes
 * @param numBytes
 */
void VMReadInstructionForm::setNumReadBytes(int numBytes){
    QStringList bytesList;
    for (int i=0; i<numBytes; i++)
        bytesList.append(QString("%1").arg(i));

    QString tmpValLow=ui.outputRangeLowComboBox->currentText();
    QString tmpValHigh=ui.outputRangeHighComboBox->currentText();
    ui.outputRangeLowComboBox->clear();
    ui.outputRangeHighComboBox->clear();
    ui.outputRangeLowComboBox->addItems(bytesList);
    ui.outputRangeHighComboBox->addItems(bytesList);
    ui.outputRangeLowComboBox->setCurrentIndex(ui.outputRangeLowComboBox->findText(tmpValLow));
    ui.outputRangeHighComboBox->setCurrentIndex(ui.outputRangeHighComboBox->findText(tmpValHigh));

}


/**
 * @brief VMReadInstructionForm::getReadOutputInstructions
 * @param valInt
 * @param valStr
 */
void VMReadInstructionForm::getReadOutputInstructions(vector<int> *valInt, vector<QString> *valStr){
    valInt->clear();
    valStr->clear();

    valInt->push_back(ui.outputRangeLowComboBox->currentText().toInt());
    valInt->push_back(ui.outputRangeHighComboBox->currentText().toInt());
    valStr->push_back(ui.outputRegisterComboBox->currentText());
    valStr->push_back(ui.outputRegisterEndianessComboBox->currentText());
}
