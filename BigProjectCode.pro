#Author Alexander Vong
#Description: Pro File that makes the code run, it has all files needed to run

QT += widgets
TARGET = fitnesstracker
TEMPLATE = app

SOURCES += main.cpp
SOURCES += loginscreen.cpp
SOURCES += workoutgui.cpp
SOURCES += Exercise.cpp
SOURCES += FitnessPlanner.cpp

HEADERS += loginscreen.h
HEADERS += FitnessPlanner.h
HEADERS += workoutgui.h
HEADERS += Exercise.h
