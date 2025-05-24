#ifndef WORKOUTLOGGER_HPP
#define WORKOUTLOGGER_HPP


#include <iostream>
#include <vector>           // for storing workouts
#include <memory>           // for shared_ptr
#include <string>
#include <algorithm>        // for sorting

// Custom headers (needed for polymorphism and object creation)
#include "WorkOut.h"        // base abstract class
#include "Running.h"        // derived workout types
#include "Swimming.h"
#include "Biking.h"

using namespace std;

// Manages a collection of user-logged workouts
class WorkoutLog {
public:
    // Constructor
    WorkoutLog();

    // Log a workout by asking user for info
    void logWorkout();

    // Print all workouts sorted by calories burned
    void printLeaderboard() const;

private:
    static const size_t MAX_WORKOUTS = 5; // Hard limit on number of workouts to store

    // Polymorphic vector of all workouts (Running, Swimming, Biking)
    vector<shared_ptr<Workout>> workouts;

    // Helper to validate YYYY-MM-DD format
    bool isValidDate(const string& date) const;

    // Helper to create a Running/Swimming/Biking workout from user input
    shared_ptr<Workout> createWorkoutFromInput();
};

#endif // WORKOUTLOGGER_HPP