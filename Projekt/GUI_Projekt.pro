QT += core
QT -= gui

TARGET = GUI_Projekt
CONFIG += console
CONFIG -= app_bundle
CONFIG += c++11
TEMPLATE = app
SOURCES += main.cpp \
    vector.inl \
    include/vector.inl \
    src/resource_manager.cpp
LIBS += -L/usr/local/lib -lSDL2 -ldl -lpthread
INCLUDES += /usr/local/include

HEADERS += \
    resource_manager.h \
    vector3.h \
    include/resource_manager.h \
    include/vector3.h

DISTFILES +=

