QT += core
QT -= gui

TARGET = BibliotekiGUI
CONFIG += console
CONFIG -= app_bundle
QMAKE_CXXFLAGS += -std=c++11
TEMPLATE = app

SOURCES += main.cpp \
    include/Rect.inl \
    include/Vector2.inl \
    include/Vector3.inl \
    src/LoadGui.cpp \
    src/ObjectGUI.cpp

HEADERS += \
    include/LoadGui.h \
    include/ObjectGUI.h \
    include/Rect.h \
    include/Vector2.h \
    include/Vector3.h

