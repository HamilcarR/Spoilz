# HamilcarR #

TEMPLATE = app
TARGET = Spoilz
QT += widgets
CONFIG += debug \
	warn_on \
	console 
	



linux:{
QMAKE_CXXFLAGS += -std=c++17 -g -Wall -Wextra -pedantic -Wno-unused-function 
LIBS += -lncurses

}

# Input
HEADERS += includes/*.h
SOURCES += sources/*.cpp

