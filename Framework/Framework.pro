TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt
CONFIG += c++11

QMAKE_CXXFLAGS += -std=c++11

LIBS += -lGL \
    -lGLU \
    -lSDL2

SOURCES += main.cpp \
    Data/texture.cpp \
    Data/sound.cpp \
    Draw_Queue.cpp \
    Drawable_Object.cpp \
    Engine.cpp \
    Point.cpp \
    Renderer.cpp \
    RM.cpp \
    Shape.cpp \
    INI_Parser.cpp \
    INI_Data.cpp

HEADERS += \
    Data/texture.h \
    Data/sound.h \
    Drawable_Object.h \
    Engine.h \
    Point.h \
    RM.h \
    Shape.h \
    INI_Parser.h \
    Draw_Queue.h \
    Renderer.h \
    INI_Data.h

