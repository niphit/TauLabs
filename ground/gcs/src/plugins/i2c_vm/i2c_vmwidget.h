/**
 ******************************************************************************
 *
 * @file       i2c_vmwidget.h
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

#ifndef I2C_VMWIDGET_H
#define I2C_VMWIDGET_H

#include "ui_i2c_vm.h"
#include "vminstructionform.h"

#include <QtGui/QLabel>
#include <QStringList>
#include <vector>


class QRegExpValidator;

class HexSpinBox : public QSpinBox
{
    Q_OBJECT
public:
    HexSpinBox(QWidget *parent = 0);

protected:
    virtual QValidator::State validate(QString &text, int &pos) const;
    virtual int valueFromText(const QString &text) const;
    virtual QString textFromValue(int value) const;

private:
    QRegExpValidator *validator;

};


class I2C_VMWidget : public QLabel
{
    Q_OBJECT

public:
    I2C_VMWidget(QWidget *parent = 0);
   ~I2C_VMWidget();

private:
    Ui_I2C_VMWidget	*m_widget;
    std::vector<VMInstructionForm*> formList;
    int instrctIdx;
    HexSpinBox *i2cHexAddressSpinBox;

private slots:
    void addAdditionalCompilerLine();
    void applyCompiler();
    void setHexDecRepresentation(QString);
};





#endif /* I2C_VMWIDGET_H */
