QT += core
QT -= gui

TARGET = GUILibrary
CONFIG += console
CONFIG -= app_bundle
CONFIG += c++14
TEMPLATE = app
LIBS += -lSDL2 -lSDL2_image -lSDL2_ttf
TEMPLATE = app

SOURCES += main.cpp \
    src/CRender.cpp \
    Vector/Rect.inl \
    Vector/Vector2.inl \
    Vector/Vector3.inl \
    src/ResourceGui.cpp \
    src/ResourceManager.cpp \
    src/Widget.cpp \
    src/Gui.cpp \
    src/Button.cpp

HEADERS += \
    include/CRender.hpp \
    Vector/Rect.hpp \
    Vector/Vector2.h \
    Vector/Vector3.h \
    include/ResourceGui.hpp \
    include/ResourceManager.hpp \
    include/Widget.hpp \
    include/Gui.hpp \
    include/Button.hpp

DISTFILES +=

