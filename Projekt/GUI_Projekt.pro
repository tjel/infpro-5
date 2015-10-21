QT += core
QT -= gui

TARGET = GUI_Projekt
CONFIG += console
CONFIG -= app_bundle
CONFIG += c++11
TEMPLATE = app
SOURCES += main.cpp \
    resource_manager.cpp
LIBS += -L/usr/local/lib -lSDL2 -ldl -lpthread
INCLUDES += /usr/local/include

HEADERS += \
    resource_manager.h

