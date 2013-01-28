TEMPLATE = lib
TARGET = I2C_VM

#QT += svg
#QT += opengl

include(../../taulabsgcsplugin.pri)
include(../../plugins/coreplugin/coreplugin.pri)
include(../../plugins/uavobjects/uavobjects.pri)


HEADERS += i2c_vmplugin.h \
    i2c_vm.h \
    i2c_vmfactory.h \
    i2c_vmwidget.h \
    i2c_vmconfiguration.h \
    vminstructionform.h \
    vmreadinstructionform.h

SOURCES += i2c_vmplugin.cpp \
    i2c_vm.cpp \
    i2c_vmfactory.cpp \
    i2c_vmwidget.cpp \
    i2c_vmconfiguration.cpp \
    vminstructionform.cpp \
    vmreadinstructionform.cpp

FORMS += i2c_vm.ui \
    vminstructionform.ui \
    vmreadinstructionform.ui

OTHER_FILES += I2C_VM.pluginspec

