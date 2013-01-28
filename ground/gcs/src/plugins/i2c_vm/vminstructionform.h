/**
 ******************************************************************************
 *
 * @file       vminstructionform.h
 * @author     Tau Labs, http://www.taulabs.org, Copyright (C) 2013
 * @addtogroup GCSPlugins GCS Plugins
 * @{
 * @addtogroup VMInstructionForm
 * @{
 * @brief I2C_VM virtual machine configuration form
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
#ifndef VMINSTRUCTIONFORM_H_
#define VMINSTRUCTIONFORM_H_

#include <QWidget>
#include <QLabel>
#include <QSpinBox>
#include <vector>

using namespace std;

#include "ui_vminstructionform.h"
#include "vmreadinstructionform.h"

class ConfigOnputWidget2;

class VMInstructionForm : public QWidget
{
    Q_OBJECT

public:
    explicit VMInstructionForm(const int index, QWidget *parent = NULL);
    ~VMInstructionForm();
    friend class ConfigOnputWidget2;

    void setNumInstructions(int val);
    QString getInstructionType();
    void getJumpInstruction(int *relativeJump, int *numJumps);
    void getReadInstruction(int*numReadBytes);
    void getWriteInstruction(vector<int> *val);
    int getDelayInstruction();
    void getOutputInstruction(vector<int> *valIntOut, vector<QString> *valStrOut);
    void setHexRepresentation(bool val);

public slots:
//    void max(int maximum);
//    int max() const;
//    void min(int minimum);
//    int min() const;
//    void minmax(int minimum, int maximum);
//    void neutral(int value);
//    int neutral() const;
//    void enableChannelTest(bool state);

signals:
    void channelChanged(int index, int value);

private:
    Ui::VMInstructionForm ui;

    int m_index; //Instruction index
    int unhideIdx; //Index of unhidden text fields
    int numInstructions;
    int readInstrctIdx;
    vector<VMReadInstructionForm*> readFormList;

    QSpinBox  *numReadBytesSpinBox;
    QSpinBox  *delayMsSpinBox;
    QComboBox *jumpToLineComboBox;
    QSpinBox *jumpXTimesSpinBox;
    QComboBox *jumpXTimesComboBox;
//    QPushButton *addReadOutputPushButton;
//    QPushButton *removeReadOutputPushButton;
//    QComboBox *outputRegisterEndianessComboBox;
//    QComboBox *outputRegisterComboBox;
//    QComboBox *outputRangeLowComboBox;
//    QComboBox *outputRangeHighComboBox;
//    QLabel *readText1Label;
//    QLabel *readText2Label;
//    QLabel *readText3Label;
//    QLabel *readText4Label;

    bool isHex;


private slots:
    void switchCompilerInst(QString instruction);
    void switchNumJumpTimes(QString jumpTimes);
    void addRegisterField();
    void removeRegisterField();
    void switchNumReadBytes(int);
    void addAdditionalReadInstructionLine();
    void removeAdditionalReadInstructionLine();
};

#endif // VMINSTRUCTIONFORM_H_
