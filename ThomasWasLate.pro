TEMPLATE = app
CONFIG += console c++11
CONFIG -= qt

QMAKE_MACOSX_DEPLOYMENT_TARGET = 11.0

exists($$OUT_PWD/conanbuildinfo.pri) {
    CONFIG += conan_basic_setup
    include ($$OUT_PWD/conanbuildinfo.pri)
} else {
   LIBS += -lsfml-audio -lsfml-graphics -lsfml-network -lsfml-system -lsfml-window
}

macx {
    CONFIG += app_bundle
    LIBS += -ObjC
}

SOURCES += \
        bob.cpp \
        detectcollisions.cpp \
        draw.cpp \
        engine.cpp \
        input.cpp \
        levelmanager.cpp \
        loadlevel.cpp \
        main.cpp \
        playablecharacter.cpp \
        textureholder.cpp \
        thomas.cpp \
        update.cpp

DISTFILES += \
    conanfile.txt \
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
    sound/reachgoal.wav \
    levels/level1.txt

HEADERS += \
    bob.h \
    engine.h \
    levelmanager.h \
    playablecharacter.h \
    textureholder.h \
    thomas.h
