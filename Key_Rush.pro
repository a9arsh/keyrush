TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        bullet.cpp \
        character.cpp \
        coin.cpp \
        door.cpp \
        main.cpp \
        monster.cpp \
        movingspike.cpp \
        spike.cpp \
        stages.cpp \
        switch.cpp


INCLUDEPATH += "C:/SFML-2.5.1/include"
LIBS += -L"C:/SFML-2.5.1/lib"
CONFIG(debug, debug|release){
    LIBS += -lsfml-audio-d -lsfml-graphics-d -lsfml-network-d -lsfml-system-d -lsfml-window-d
} else {
    LIBS += -lsfml-audio -lsfml-graphics -lsfml-network -lsfml-system -lsfml-window
}

HEADERS += \
    bullet.h \
    character.h \
    coin.h \
    door.h \
    monster.h \
    movingspike.h \
    spike.h \
    switch.h
