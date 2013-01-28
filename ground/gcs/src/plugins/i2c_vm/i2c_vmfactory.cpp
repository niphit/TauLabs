/**
 ******************************************************************************
 *
 * @file       i2c_vmfactory.cpp
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
#include "i2c_vmfactory.h"
#include "i2c_vmwidget.h"
#include "i2c_vm.h"
#include <coreplugin/iuavgadget.h>

I2C_VMFactory::I2C_VMFactory(QObject *parent) :
    IUAVGadgetFactory(QString("I2C_VM"),
                      tr("I2C virtual machine compiler"),
                      parent)
{
}

I2C_VMFactory::~I2C_VMFactory()
{

}

IUAVGadget* I2C_VMFactory::createGadget(QWidget *parent) {
    I2C_VMWidget* gadgetWidget = new I2C_VMWidget(parent);
    return new I2C_VM(QString("I2C_VM"), gadgetWidget, parent);
}
