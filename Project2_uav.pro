#-------------------------------------------------
#
# Project created by QtCreator 2015-12-14T13:13:07
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Project2_uav
TEMPLATE = app


SOURCES += main.cpp\
    src/uavController/CombatControllerImpl.cpp \
    src/uavController/ReconControllerImpl.cpp \
    src/uavController/SupplyControllerImpl.cpp \
    src/uavData/uavDatabase.cpp \
    src/uavFactory/uavFactoryImpl.cpp \
    src/uavLogger/uavLogger.cpp \
    src/uavMath/myrect.cpp \
    src/uavMath/vector3d.cpp \
    src/uavOperator/uavAutomaticOperator.cpp \
    src/uavOperator/uavUserOperator.cpp \
    src/AOOD_Project2_Main.cpp \
    mainwindow.cpp \
    src/uavController/uavBaseController.cpp

HEADERS  += src/uavController/automaticDutiesProvider.h \
    src/uavController/CombatController.h \
    src/uavController/CombatControllerImpl.h \
    src/uavController/MissionModes.h \
    src/uavController/ReconController.h \
    src/uavController/ReconControllerImpl.h \
    src/uavController/SupplyController.h \
    src/uavController/SupplyControllerImpl.h \
    src/uavData/uavDataStruct.h \
    src/uavData/uavDatabase.h \
    src/uavFactory/uavFactory.h \
    src/uavFactory/uavFactoryImpl.h \
    src/uavLogger/uavLogger.h \
    src/uavMath/myrect.h \
    src/uavMath/vector3d.h \
    src/uavOperator/uavAutomaticOperator.h \
    src/uavOperator/uavUserOperator.h \
    src/uavOperator/userButtonActions.h \
    mainwindow.h \
    src/uavController/uavBaseController.h

FORMS += \
    mainwindow.ui
