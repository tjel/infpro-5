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
    src/ObjectGUI.cpp \
    src/CRenderer.cpp \
    src/MenagerResource.cpp

HEADERS += \
    include/ObjectGUI.h \
    include/Rect.h \
    include/Vector2.h \
    include/Vector3.h \
    src/CRenderer.h \
    include/CRenderer.h \
    include/MenagerResource.h

LIBS += -L/usr/lib -L/usr/local/lib/ -lSDL2 -lSDL2_image -lSDL2_ttf
