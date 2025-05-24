#ifndef EXERCISE_H
#define EXERCISE_H

#include <string>

/**
 * @brief Class representing a workout exercise.
 *
 * The Exercise class is used to store information about a workout exercise, including its
 * name, type, and the muscle group it targets. This class is primarily used for organizing
 * and retrieving details of exercises in a fitness tracking application.
 *
 * @author Kibi Paskaran
 */
class Exercise {
private:
    std::string name; ///< The name of the exercise.
    std::string type; ///< The type of exercise.
    std::string muscleGroup; ///< The muscle group of the exercise.

public:
    /**
     * @brief Constructs an Exercise object with name, type, and muscle group.
     *
     * Initializes the Exercise with the values for the exercise
     * name, type, and muscle group.
     *
     * @param name The name of the exercise.
     * @param type The type of the exercise.
     * @param muscleGroup The muscle group of the exercise.
     */
    Exercise(std::string name, std::string type, std::string muscleGroup);

    /**
     * @brief Gets the name of the exercise.
     *
     * Returns the name of the exercise stored in the object.
     *
     * @return The name of the exercise.
     */
    std::string getName() const;

    /**
     * @brief Gets the type of the exercise.
     *
     * This method returns the type of the exercise.
     *
     * @return The type of the exercise.
     */
    std::string getType() const;

    /**
     * @brief Gets the muscle group of the exercise.
     *
     * This method returns the muscle group of the exercise.
     *
     * @return The muscle group of the exercise.
     */
    std::string getMuscleGroup() const;
};

#endif
