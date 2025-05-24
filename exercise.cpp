#include "exercise.h"

/**
 * @brief Constructs an Exercise object.
 * @param name The name of the exercise.
 * @param type The type of exercise.
 * @param muscleGroup The muscle group of the exercise.
 * @author Kibi Paskaran
 */
Exercise::Exercise(std::string name, std::string type, std::string muscleGroup)
    : name(name), type(type), muscleGroup(muscleGroup) {}

/**
 * @brief Gets the name of the exercise.
 * @return The name of the exercise.
 */
std::string Exercise::getName() const {
    return name;
}

/**
 * @brief Gets the type of the exercise.
 * @return The type of the exercise.
 */
std::string Exercise::getType() const {
    return type;
}

/**
 * @brief Gets the muscle group of the exercise.
 * @return The muscle group.
 */
std::string Exercise::getMuscleGroup() const {
    return muscleGroup;
}
