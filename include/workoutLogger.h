#ifndef WORKOUTLOGGER_HPP
#define WORKOUTLOGGER_HPP

#include <iostream>
#include <vector>
#include <memory>
#include <string>
#include <map>
#include "Workout.h"  // Base abstract class for workouts

using namespace std;

// Class that manages a list of workouts
class WorkoutLog {
public:
    WorkoutLog(); // Constructor

    // Logs a workout from user input
    void logWorkout();

    // Shows workouts sorted by calories burned
    void printLeaderboard() const;

private:
    static const size_t MAX_WORKOUTS = 5; // Limit for number of workouts

    vector<shared_ptr<Workout>> workouts; //  workout list

    // Checks if date format is valid (YYYY-MM-DD)
    bool isValidDate(const string& date) const;
};

#endif // WORKOUTLOGGER_HPP
