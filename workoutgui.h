#ifndef WORKOUTGUI_H
#define WORKOUTGUI_H

#include <QWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include <QLabel>
#include <QStackedWidget>
#include "FitnessPlanner.h"
#include <QLineEdit>
#include <QTimer>
#include <QTime>

/**
 * @class WorkoutGUI
 * @brief The WorkoutGUI class provides the graphical interface for workout planner.
 *
 * Displays the workout categories, workout routines,
 * and exercises. It allows the user to interact with the fitness planner, view workout details,
 * and track workout durations using a timer.
 *
 * @author Kibi Paskaran & Alex Vong
 */
class WorkoutGUI : public QWidget {
    Q_OBJECT

public:
    /**
     * @brief Initialize the WorkoutGUI.
     *
     * Initializes the graphical interface, including the layout,
     * and sets up the required connections.
     *
     * @param parent The parent QWidget.
     */
    explicit WorkoutGUI(QWidget *parent = nullptr);

private slots:
    /**
     * @brief Creates and adds buttons for each workout category.
     *
     * @param categoryLayout The layout the buttons will be added.
     */
    void addCategoryButtons(QVBoxLayout *categoryLayout);

    /**
     * @brief Displays the workout types.
     *
     * @param category The name of the category.
     */
    void displayWorkoutTypes(const QString &category);

    /**
     * @brief Displays the exercises.
     *
     * @param category The name of the workout category.
     * @param workoutName The name of the workout.
     */
    void displayExercises(const QString &category, const QString &workoutName);

    /**
     * @brief Shows the details of exercises.
     *
     * @param exercise The exercise that details need to be displayed.
     */
    void showExerciseDetails(const Exercise &exercise);

    /**
     * @brief Selects a workout routine to display.
     *
     * @param workoutName The name of the workout routine.
     */
    void selectWorkoutRoutine(const QString &workoutName);

    /**
     * @brief Timer to track the workout duration.
     *
     * @param timerLabel The label to display the time.
     */
    void startTimer(QLabel *timerLabel);

private:
    FitnessPlanner *planner; /**< The FitnessPlanner instance for managing workouts. */
    QStackedWidget *stackedWidget; /**< The widget that displaying workout views. */
    QString currentCategory; /**< The category being displayed. */
    QString currentWorkout; /**< The workout being displayed. */
    QTimer *timer; /**< The timer. */
    int timeElapsed; /**< The amount of time in seconds. */

    /**
     * @brief Displays the workout.
     *
     * Shows the selected workout routine with its exercises.
     *
     * @param category The category of the workout.
     * @param workoutName The name of the workout.
     */
    void displaySelectedWorkout(const QString &category, const QString &workoutName);
};

#endif
