/**
 ******************************************************************************
 *
 * @file       i2c_vm.h
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
#ifndef I2C_VM_H_
#define I2C_VM_H_

#include "vminstructionform.h"

#include <coreplugin/iuavgadget.h>
#include <vector>

namespace Core {
class IUAVGadget;
}

class I2C_VMWidget;

using namespace Core;

void generateVmCode(int, std::vector<VMInstructionForm*>);

class I2C_VM : public Core::IUAVGadget
{
    Q_OBJECT
public:
    I2C_VM(QString classId, I2C_VMWidget *widget, QWidget *parent = 0);
    ~I2C_VM();

    QList<int> context() const { return m_context; }
    QWidget *widget() { return m_widget; }
    QString contextHelpId() const { return QString(); }

private:
    QWidget *m_widget;
    QList<int> m_context;
};


#endif // I2C_VM_H_
