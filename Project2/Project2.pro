TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    ReadIn.cpp \
    ParseNStore.cpp \
    Resize.cpp \
    Output.cpp

HEADERS += \
    ReadIn.h \
    ParseNStore.h \
    Resize.h \
    Output.h

