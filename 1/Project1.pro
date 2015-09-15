TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    player.cpp \
    encounter.cpp \
    runGame.cpp \
    inAndOut.cpp

HEADERS += \
    player.h \
    encounter.h \
    runGame.h \
    inAndOut.h

