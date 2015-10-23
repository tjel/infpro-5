QT += core
QT -= gui

TARGET = GUI_Projekt1
CONFIG += console
CONFIG -= app_bundle
CONFIG += c++11
TEMPLATE = app

SOURCES += main.cpp \
    src/resource_manager.cpp \
    src/vector3.inl \
    src/vector4.inl

HEADERS += \
    include/resource_manager.h \
    include/vector3.h \
    include/vector4.h

