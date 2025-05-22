#ifndef Utils_calorieChecker
#define Utils_calorieChecker

// Included all the necesary libraries
#include <iostream>
#include <iomanip>
#include <string>
#include <memory>    // for unique_ptr

using namespace std;

namespace calorieChecker {

    // Enum to categorize workout types
    enum class WorkoutType { Running, Swimming, Biking };

    // Struct for calorie brun session
    struct CalorieSession {
        WorkoutType type;
        double weight;
        double duration;
        double calories;
    };

    // Original interactive calculator
    void calorieCalculator();

    // Emergency tracker: uses unique_ptr, stores to binary file
    void emergencyTracker();

    WorkoutType parseWorkout(const std::string& s);
} // namespace calorieChecker


#endif // CALORIE_CHECKER_H


