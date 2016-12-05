TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main_test.cpp \
    vehicle.cpp \
    hedgehog.cpp \
    hedgehog_test.cpp \
    vehicle_test.cpp

QMAKE_CXXFLAGS += -std=c++14 -Wall -Wextra
LIBS += -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio

HEADERS += \
    vehicle.h \
    hedgehog.h

LIBS += -lboost_unit_test_framework

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
