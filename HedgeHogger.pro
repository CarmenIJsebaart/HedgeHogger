TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    truck.cpp \
    car.cpp \
    vehicle.cpp \
    hedgehog.cpp

QMAKE_CXXFLAGS += -std=c++14 -Wall -Wextra
LIBS += -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio

HEADERS += \
    truck.h \
    car.h \
    vehicle.h \
    hedgehog.h
