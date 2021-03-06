TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    vehicle.cpp \
    hedgehog.cpp \
    window.cpp \
    obstacle.cpp \
    game.cpp \
    gamestate.cpp

CONFIG += c++14
QMAKE_CXX = g++-5
QMAKE_LINK = g++-5
QMAKE_CC = gcc-5
QMAKE_CXXFLAGS += -std=c++14 -Wall -Wextra

LIBS += -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio

HEADERS += \
    vehicle.h \
    hedgehog.h \
    window.h \
    obstacle.h \
    game.h \
    gamestate.h


# Debug and release mode
CONFIG += debug_and_release
# Release mode 
CONFIG(release, debug|release) {
  DEFINES += NDEBUG

  QMAKE_CXXFLAGS += -Wno-unused-parameter
}
# Debug mode
CONFIG(debug, debug|release) {

  # gcov
  QMAKE_CXXFLAGS += -fprofile-arcs -ftest-coverage
  LIBS += -lgcov

  # UBSAN
  QMAKE_CXXFLAGS += -fsanitize=undefined
  QMAKE_LFLAGS += -fsanitize=undefined
  LIBS += -lubsan
}
