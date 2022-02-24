TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

LIBS += -lsfml-audio -lsfml-graphics -lsfml-network -lsfml-system -lsfml-window

SOURCES += \
        draw.cpp \
        engine.cpp \
        input.cpp \
        main.cpp \
        textureholder.cpp \
        update.cpp

DISTFILES += \
    fonts/Roboto-Light.ttf \
    fonts/orange_juice.ttf \
    graphics/background.png \
    graphics/bob.png \
    graphics/thomas.png \
    graphics/tiles_sheet.png \
    sound/fallinfire.wav \
    sound/fallinwater.wav \
    sound/fire1.wav \
    sound/jump.wav \
    sound/reachgoal.wav

HEADERS += \
    engine.h \
    textureholder.h
