/// @file FitnessPlanner.h
/// @brief Defines the FitnessPlanner class for managing workouts.
/// @author Kibi Paskaran

#ifndef FITNESSPLANNER_H
#define FITNESSPLANNER_H

#include "Exercise.h"
#include <unordered_map>
#include <vector>
#include <string>

/**
 * @class FitnessPlanner
 * @brief Managing workout categories, workouts, and exercises.
 *
 * The FitnessPlanner class has structured collection of workouts categorized by type.
 * It allows for geting workout categories, workout titles, and exercises within a workout.
 */
class FitnessPlanner {
private:
    /// Workouts categorized by type and workout name, containing a list of exercises.
    std::unordered_map<std::string, std::unordered_map<std::string, std::vector<Exercise>>> workouts;

public:
    /**
     * @brief Constructs a FitnessPlanner object.
     *
     * Initializes the workout structure with categories and exercises.
     */
    FitnessPlanner();

    /**
     * @brief Displays the workout categories.
     *
     * Provides a list of all workout categories.
     */
    void displayWorkoutCategories();

    /**
     * @brief Displays workout titles.
     * @param category The name of the workout category.
     *
     * Retrieves and prints the names of all workouts.
     */
    void displayWorkoutTitles(const std::string& category);

    /**
     * @brief Displays exercises.
     * @param category The category.
     * @param workoutName The name.
     *
     * Lists all exercises included in the workout.
     */
    void displayExercises(const std::string& category, const std::string& workoutName);

    /**
     * @brief Retrieves the workout structure.
     * @return A nested unordered map containing workouts and their exercises.
     *
     * This function returns data containing categories, workouts, and exercises.
     */
    std::unordered_map<std::string, std::unordered_map<std::string, std::vector<Exercise>>> getWorkouts() const;
};

#endif
