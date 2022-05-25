TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

LIBS += -lsfml-audio -lsfml-graphics -lsfml-network -lsfml-system -lsfml-window

SOURCES += \
        bob.cpp \
        draw.cpp \
        engine.cpp \
        input.cpp \
        main.cpp \
        playablecharacter.cpp \
        textureholder.cpp \
        thomas.cpp \
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
    bob.h \
    engine.h \
    playablecharacter.h \
    textureholder.h \
    thomas.h
