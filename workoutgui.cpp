/**
 * @file workoutgui.cpp
 * @brief WorkoutGUI class for handling workout selection and display
 * @author Alexander Vong and Kibi Paskaran
*/
#include "workoutgui.h"
#include "FitnessPlanner.h"
#include <QVBoxLayout>
#include <QPushButton>
#include <QLabel>
#include <QMessageBox>
#include <QStackedWidget>
#include <QLineEdit>
#include <QTimer>
#include <QTime>

/**
 * @brief Constructor for WorkoutGUI.
 * @param parent; Pointer to parent widget
*/
WorkoutGUI::WorkoutGUI(QWidget *parent) : QWidget(parent) {
    QVBoxLayout *layout = new QVBoxLayout(this);

    setFixedSize(375, 667);

    QLabel *profileLabel = new QLabel("User Profile: John Doe", this);
    profileLabel->setStyleSheet("font-size: 18px; font-weight: bold;");
    profileLabel->setAlignment(Qt::AlignCenter);
    layout->addWidget(profileLabel);

    QLabel *myWorkoutsLabel = new QLabel("Select a Workout:", this);
    myWorkoutsLabel->setStyleSheet("font-size: 16px; font-weight: bold;");
    myWorkoutsLabel->setAlignment(Qt::AlignCenter);
    layout->addWidget(myWorkoutsLabel);

    setLayout(layout);
    setWindowTitle("PeakStrength Workout Planner");

    planner = new FitnessPlanner();

    stackedWidget = new QStackedWidget(this);

    QWidget *categoryScreen = new QWidget(this);
    QVBoxLayout *categoryLayout = new QVBoxLayout(categoryScreen);
    addCategoryButtons(categoryLayout);
    stackedWidget->addWidget(categoryScreen);

    layout->addWidget(stackedWidget);
}

/** 
 * @brief Adds button for workout categories
 * @param categoryLayout; Layout to add buttons to.
*/
void WorkoutGUI::addCategoryButtons(QVBoxLayout *categoryLayout) {
    QPushButton *cardioBtn = new QPushButton("Cardio Workouts", this);
    QPushButton *equipmentFreeBtn = new QPushButton("Equipment Free Workouts", this);
    QPushButton *weightTrainingBtn = new QPushButton("Weight Training Workouts", this);

    connect(cardioBtn, &QPushButton::clicked, this, [this]() {
        displayWorkoutTypes("Cardio");
    });
    connect(equipmentFreeBtn, &QPushButton::clicked, this, [this]() {
        displayWorkoutTypes("Equipment Free");
    });
    connect(weightTrainingBtn, &QPushButton::clicked, this, [this]() {
        displayWorkoutTypes("Weight Training");
    });

    categoryLayout->addWidget(cardioBtn);
    categoryLayout->addWidget(equipmentFreeBtn);
    categoryLayout->addWidget(weightTrainingBtn);
}

/** 
 * @brief Displays workout types for a category.
 * @param category; The selected workout category.
*/
void WorkoutGUI::displayWorkoutTypes(const QString &category) {
    this->currentCategory = category;

    QWidget *workoutScreen = new QWidget(this);
    QVBoxLayout *workoutLayout = new QVBoxLayout(workoutScreen);

    QPushButton *backButton = new QPushButton("Back to Categories", this);
    backButton->setStyleSheet("background-color: blue; color: white;");
    connect(backButton, &QPushButton::clicked, this, [this]() {
        stackedWidget->setCurrentIndex(0);
    });
    workoutLayout->addWidget(backButton);

    QVector<QString> workoutOrder;
    if (category == "Weight Training") {
        workoutOrder = {"Push", "Pull", "Legs", "Full Body 1", "Full Body 2", "Full Body 3", "Upper", "Lower"};
    } else if (category == "Equipment Free") {
        workoutOrder = {"Full Body 1", "Full Body 2", "Full Body 3"};
    } else if (category == "Cardio") {
        workoutOrder = {"Core and Cardio", "High-Intensity Blast", "Full Body Burn", "Explosive HIIT Workout"};
    }

    for (const QString &workoutName : workoutOrder) {
        QPushButton *workoutButton = new QPushButton(workoutName, this);
        connect(workoutButton, &QPushButton::clicked, this, [this, category, workoutName]() {
            displayExercises(category, workoutName);
        });
        workoutLayout->addWidget(workoutButton);
    }

    stackedWidget->addWidget(workoutScreen);
    stackedWidget->setCurrentWidget(workoutScreen);
}

/**
 * @brief Displays exercises for a selected workout
 * @param category; category of the workout
 * @param workoutName; name of the workout
*/
void WorkoutGUI::displayExercises(const QString &category, const QString &workoutName) {
    this->currentWorkout = workoutName;

    QWidget *exerciseScreen = new QWidget(this);
    QVBoxLayout *exerciseLayout = new QVBoxLayout(exerciseScreen);

    QPushButton *backButton = new QPushButton("Back to Workouts", this);
    backButton->setStyleSheet("background-color: blue; color: white;");
    connect(backButton, &QPushButton::clicked, this, [this]() {
        displayWorkoutTypes(this->currentCategory);
    });
    exerciseLayout->addWidget(backButton);

    auto workouts = planner->getWorkouts();
    if (workouts.find(category.toStdString()) != workouts.end() &&
        workouts[category.toStdString()].find(workoutName.toStdString()) != workouts[category.toStdString()].end()) {

        QVector<QPushButton*> exerciseButtons;

        for (const auto &exercise : workouts[category.toStdString()][workoutName.toStdString()]) {
            QString exerciseName = QString::fromStdString(exercise.getName());
            QPushButton *exerciseButton = new QPushButton(exerciseName, this);

            connect(exerciseButton, &QPushButton::clicked, this, [this, exercise]() {
                showExerciseDetails(exercise);
            });

            exerciseButtons.append(exerciseButton);
            exerciseLayout->addWidget(exerciseButton);
        }

        if (!exerciseButtons.isEmpty()) {
            QPushButton *selectButton = new QPushButton("Select Workout", this);
            selectButton->setStyleSheet("background-color: blue; color: white;");
            connect(selectButton, &QPushButton::clicked, this, [this, workoutName]() {
                selectWorkoutRoutine(workoutName);
            });
            exerciseLayout->addWidget(selectButton);
        }
    } else {
        QLabel *noExerciseLabel = new QLabel("No exercises found.", this);
        exerciseLayout->addWidget(noExerciseLabel);
    }

    stackedWidget->addWidget(exerciseScreen);
    stackedWidget->setCurrentWidget(exerciseScreen);
}

/**
 * @brief Displays exercise details
 * @param exercise; The selected exercise
*/
void WorkoutGUI::showExerciseDetails(const Exercise &exercise) {
    QString details = QString("Exercise: %1\nType: %2\nMuscle Group: %3")
    .arg(QString::fromStdString(exercise.getName()))
        .arg(QString::fromStdString(exercise.getType()))
        .arg(QString::fromStdString(exercise.getMuscleGroup()));

    QMessageBox::information(this, "Exercise Details", details);
}

/**
 * @brief Select workout Routine
 * @param workoutname; The name of workout
*/
void WorkoutGUI::selectWorkoutRoutine(const QString &workoutName) {
    displaySelectedWorkout(currentCategory, workoutName);
}

/**
 * @brief Display workout details
 * @param workoutname; The name of workout
 * @param category; selected category
*/
void WorkoutGUI::displaySelectedWorkout(const QString &category, const QString &workoutName) {
    QWidget *workoutScreen = new QWidget(this);
    QVBoxLayout *workoutLayout = new QVBoxLayout(workoutScreen);

    QLabel *workoutTitle = new QLabel("Workout: " + workoutName, this);
    workoutTitle->setStyleSheet("font-size: 20px; font-weight: bold;");
    workoutLayout->addWidget(workoutTitle);

    QLabel *timerLabel = new QLabel("00:00", this);  // Timer display label
    timerLabel->setAlignment(Qt::AlignCenter);
    timerLabel->setStyleSheet("font-size: 18px; font-weight: bold;");
    workoutLayout->addWidget(timerLabel);

    auto workouts = planner->getWorkouts();
    if (workouts.find(category.toStdString()) != workouts.end() &&
        workouts[category.toStdString()].find(workoutName.toStdString()) != workouts[category.toStdString()].end()) {

        for (const auto &exercise : workouts[category.toStdString()][workoutName.toStdString()]) {
            QString exerciseName = QString::fromStdString(exercise.getName());
            QLabel *exerciseLabel = new QLabel(exerciseName, this);
            exerciseLabel->setStyleSheet("font-size: 16px; font-weight: bold;");
            workoutLayout->addWidget(exerciseLabel);

            for (int setNum = 1; setNum <= 3; ++setNum) {
                QHBoxLayout *setLayout = new QHBoxLayout();

                QLabel *setLabel = new QLabel("Set " + QString::number(setNum), this);
                setLayout->addWidget(setLabel);

                QLineEdit *repInput = new QLineEdit(this);
                repInput->setPlaceholderText("Rep");
                repInput->setStyleSheet("width: 80px;");
                setLayout->addWidget(repInput);

                QLineEdit *weightInput = new QLineEdit(this);
                weightInput->setPlaceholderText("Weight");
                weightInput->setStyleSheet("width: 80px;");
                setLayout->addWidget(weightInput);

                workoutLayout->addLayout(setLayout);
            }
        }
    }

    QPushButton *finishButton = new QPushButton("Finish", this);
    finishButton->setStyleSheet("background-color: blue; color: white;");
    connect(finishButton, &QPushButton::clicked, this, [this, timerLabel]() {
        timer->stop();
        QMessageBox::information(nullptr, "Finish", "Workout finished.");
    });
    workoutLayout->addWidget(finishButton);

    stackedWidget->addWidget(workoutScreen);
    stackedWidget->setCurrentWidget(workoutScreen);

    startTimer(timerLabel);
}

/**
 * @brief Timer used when starting workout
 * @param timerLabel; Timer
*/
void WorkoutGUI::startTimer(QLabel *timerLabel) {
    timeElapsed = 0;
    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, [this, timerLabel]() {
        timeElapsed++;
        QTime time(0, 0);
        time = time.addSecs(timeElapsed);
        timerLabel->setText(time.toString("mm:ss"));
    });
    timer->start(1000);
}

