TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main_test.cpp \
    game.cpp \
    hedgehog.cpp \
    hedgehog_test.cpp \
    obstacle.cpp \
    vehicle.cpp \
    vehicle_test.cpp \
    window.cpp \
    window_test.cpp \
    obstacle_test.cpp \
    game_test.cpp

HEADERS += \
    game.h \
    hedgehog.h \
    obstacle.h \
    vehicle.h \
    window.h

# C++14
CONFIG += c++14
QMAKE_CXX = g++-5
QMAKE_LINK = g++-5
QMAKE_CC = gcc-5
QMAKE_CXXFLAGS += -Wall -Wextra -Werror -std=c++14

# Debug and release build
CONFIG += debug_and_release
# In release mode, define NDEBUG
CONFIG(release, debug|release) {
  DEFINES += NDEBUG
}
# In debug mode, enable gcov and UBSAN
CONFIG(debug, debug|release) {

  # gcov
  QMAKE_CXXFLAGS += -fprofile-arcs -ftest-coverage
  LIBS += -lgcov

  # UBSAN
  QMAKE_CXXFLAGS += -fsanitize=undefined
  QMAKE_LFLAGS += -fsanitize=undefined
  LIBS += -lubsan
}

# SFML
LIBS += -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio

# Boost.Test
LIBS += -lboost_unit_test_framework

