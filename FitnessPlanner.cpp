#include "FitnessPlanner.h"
#include <iostream>

/**
 * @brief Constructor to initialize the workouts.
 *
 * Initializes a predefined set of workouts for different categories such as Weight Training,
 * Equipment Free Workouts, and Cardio. Each category has subcategories with exercises.
 *
 * @author Kibi Paskaran
 */
FitnessPlanner::FitnessPlanner() {
    workouts = {
        {"Weight Training", {
                                // Push workouts
                                {"Push", {Exercise("Bench Press", "Barbell", "Chest"), Exercise("Shoulder Press", "Dumbbell", "Shoulders"),
                                          Exercise("Butterfly", "Pec Deck", "Chest"), Exercise("Lateral Raise", "Dumbbell", "Shoulders"),
                                          Exercise("Tricep Rope Pushdown", "Cable", "Triceps")}},

                                // Pull workouts
                                {"Pull", {Exercise("Lat Pulldown", "Cable", "Back"), Exercise("Seated Cable Row", "Cable", "Back"),
                                          Exercise("Shrug", "Dumbbell", "Traps"), Exercise("Hammer Curl", "Dumbbell", "Biceps"),
                                          Exercise("Face Pull", "Cable", "Shoulders")}},

                                // Legs workouts
                                {"Legs", {Exercise("Leg Press", "Machine", "Legs"), Exercise("Lying Leg Curl", "Machine", "Hamstrings"),
                                          Exercise("Leg Extension", "Machine", "Quads"), Exercise("Standing Calf Raise", "Machine", "Calves")}},

                                // Full Body workout 1
                                {"Full Body 1", {Exercise("Leg Press", "Machine", "Legs"), Exercise("Chest Press", "Machine", "Chest"),
                                                 Exercise("Lat Pulldown", "Cable", "Back"), Exercise("Lying Leg Curl", "Machine", "Hamstrings")}},

                                // Full Body workout 2
                                {"Full Body 2", {Exercise("Seated Cable Row", "Cable", "Back"), Exercise("Leg Extension", "Machine", "Quads"),
                                                 Exercise("Butterfly", "Pec Deck", "Chest"), Exercise("Standing Calf Raise", "Machine", "Calves")}},

                                // Full Body workout 3
                                {"Full Body 3", {Exercise("Shoulder Press", "Dumbbell", "Shoulders"), Exercise("Bulgarian Split Squat", "Dumbbell", "Legs"),
                                                 Exercise("Shrug", "Dumbbell", "Traps"), Exercise("Glute Kickback", "Machine", "Glutes")}},

                                // Upper body workout
                                {"Upper", {Exercise("Bench Press", "Barbell", "Chest"), Exercise("Lat Pulldown", "Cable", "Back"),
                                           Exercise("Shoulder Press", "Dumbbell", "Shoulders"), Exercise("Seated Cable Row", "Cable", "Back"),
                                           Exercise("Butterfly", "Pec Deck", "Chest"), Exercise("Face Pull", "Cable", "Shoulders")}},

                                // Lower body workout
                                {"Lower", {Exercise("Leg Press", "Machine", "Legs"), Exercise("Lying Leg Curl", "Machine", "Hamstrings"),
                                           Exercise("Leg Extension", "Machine", "Quads"), Exercise("Glute Kickback", "Machine", "Glutes"),
                                           Exercise("Standing Calf Raise", "Machine", "Calves")}}
                            }},
        // Equipment Free Workouts
        {"Equipment Free", {
                               {"Full Body 1", {Exercise("Squat", "Body Weight", "Legs"), Exercise("Kneeling Push Up", "Body Weight", "Chest"),
                                                Exercise("Superman", "Body Weight", "Back"), Exercise("Glute Bridge", "Body Weight", "Glutes"),
                                                Exercise("Mountain Climber", "Cardio", "Full Body")}},

                               {"Full Body 2", {Exercise("Lunge", "Body Weight", "Legs"), Exercise("Bird Dog", "Body Weight", "Core"),
                                                Exercise("Standing Calf Raise", "Body Weight", "Calves"), Exercise("Plank", "Body Weight", "Core"),
                                                Exercise("Jumping Jack", "Cardio", "Full Body")}},

                               {"Full Body 3", {Exercise("Inverted Row", "Body Weight", "Back"), Exercise("Squat", "Body Weight", "Legs"),
                                                Exercise("Incline Push Ups", "Body Weight", "Chest"), Exercise("Fire Hydrants", "Body Weight", "Glutes"),
                                                Exercise("High Knees", "Cardio", "Legs")}}
                           }},
        // Cardio Workouts
        {"Cardio", {
                       {"Core & Cardio", {Exercise("Plank Pushup", "Cardio", "Core"), Exercise("Russian Twist", "Cardio", "Obliques"),
                                          Exercise("Mountain Climber", "Cardio", "Full Body"), Exercise("Superman", "Body Weight", "Back"),
                                          Exercise("High Knees", "Cardio", "Legs")}},

                       {"High-Intensity Blast", {Exercise("Jumping Jack", "Cardio", "Full Body"), Exercise("Flutter Kick", "Cardio", "Core"),
                                                 Exercise("Frog Jumps", "Cardio", "Legs"), Exercise("High Knee Skips", "Cardio", "Legs")}},

                       {"Full Body Burn", {Exercise("Burpee", "Cardio", "Full Body"), Exercise("High Knees", "Cardio", "Legs"),
                                           Exercise("Jump Squat", "Cardio", "Legs"), Exercise("Mountain Climber", "Cardio", "Full Body"),
                                           Exercise("Kneeling Push Up", "Body Weight", "Chest")}},

                       {"Explosive HIIT Workout", {Exercise("Box Jump", "Cardio", "Legs"), Exercise("Clap Push Ups", "Body Weight", "Chest"),
                                                   Exercise("Single Leg Glute Bridge", "Body Weight", "Glutes"), Exercise("Mountain Climber", "Cardio", "Full Body"),
                                                   Exercise("Jumping Lunge", "Cardio", "Legs")}}
                   }}
    };
}

/**
 * @brief Displays the workout categories.
 *
 * outputs list of workout categories.
 */
void FitnessPlanner::displayWorkoutCategories() {
    std::cout << "\nSelect a workout category:\n";
    std::cout << "1. Cardio Workouts\n";
    std::cout << "2. Equipment Free Workouts\n";
    std::cout << "3. Weight Training Workouts\n";
}

/**
 * @brief Displays workouts in the selected category.
 *
 * @param category The category the workouts need to be displayed.
 */
void FitnessPlanner::displayWorkoutTitles(const std::string& category) {
    if (workouts.find(category) == workouts.end()) {
        std::cout << "Invalid category!\n";
        return;
    }
    std::cout << "\nAvailable " << category << " Workouts:\n";
    for (const auto& workout : workouts[category]) {
        std::cout << "- " << workout.first << std::endl;
    }
}

/**
 * @brief Displays exercises for a workout.
 *
 * @param category The workout category.
 * @param workoutName The name of the selected workout.
 */
void FitnessPlanner::displayExercises(const std::string& category, const std::string& workoutName) {
    if (workouts.find(category) == workouts.end() || workouts[category].find(workoutName) == workouts[category].end()) {
        std::cout << "Invalid workout selection!\n";
        return;
    }

    std::cout << "\n" << workoutName << " Exercises:\n";
    for (const auto& exercise : workouts[category][workoutName]) {
        std::cout << "- " << exercise.getName() << " (" << exercise.getType() << ", " << exercise.getMuscleGroup() << ")\n";
    }
}

/**
 * @brief Getter function for workouts.
 *
 * @return The current workouts.
 */
std::unordered_map<std::string, std::unordered_map<std::string, std::vector<Exercise>>> FitnessPlanner::getWorkouts() const {
    return workouts;
}
