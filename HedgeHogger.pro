TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    truck.cpp \
    car.cpp \
    vehicle.cpp \
    hedgehog.cpp

CONFIG += c++14
QMAKE_CXX = g++-5
QMAKE_LINK = g++-5
QMAKE_CC = gcc-5
QMAKE_CXXFLAGS += -std=c++14 -Wall -Wextra

LIBS += -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio

HEADERS += \
    truck.h \
    car.h \
    vehicle.h \
    hedgehog.h
