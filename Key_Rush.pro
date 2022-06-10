TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        character.cpp \
        coin.cpp \
        door.cpp \
        main.cpp \
        monster.cpp \
        switch.cpp


INCLUDEPATH += "C:/Users/Adharsh/Documents/SFML-2.5.1/include"

LIBS += -L"C:/Users/Adharsh/Documents/SFML-2.5.1/lib"
CONFIG(debug, debug|release){
    LIBS += -lsfml-audio-d -lsfml-graphics-d -lsfml-network-d -lsfml-system-d -lsfml-window-d
} else {
    LIBS += -lsfml-audio -lsfml-graphics -lsfml-network -lsfml-system -lsfml-window
}

HEADERS += \
    character.h \
    coin.h \
    door.h \
    monster.h \
    switch.h
