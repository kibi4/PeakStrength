/**
 * @file main.cpp
 * @brief Main Function that initializes the login screen and transitions to the workout GUI upon successful login
 * @author Alexander Vong
*/
#include <QApplication>
#include <QStackedWidget>
#include "loginscreen.h"
#include "workoutgui.h"

/**
 * @brief Main Function that starts the application
 * @param argc Argument count
 * @param argv Argument vector
 * @return Application execution status
*/


int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    QStackedWidget stackedWidget;

//Create loginScreen and workoutGUI
    LoginScreen *loginScreen = new LoginScreen();
    WorkoutGUI *workoutGUI = new WorkoutGUI();

//Add widgets
    stackedWidget.addWidget(loginScreen);
    stackedWidget.addWidget(workoutGUI);

//Connect login success signal to transition to WorkoutGUI
    QObject::connect(loginScreen, &LoginScreen::loginSuccess, [&]() {
        stackedWidget.setCurrentWidget(workoutGUI);
    });

    stackedWidget.setCurrentWidget(loginScreen);
    stackedWidget.show();

    return app.exec();
}
