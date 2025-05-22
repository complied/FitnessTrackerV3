#ifndef Utils_workoutLogger
#define Utils_workoutLogger

// Included all the necesary libraries
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

namespace logWorkout {
    // Cap logging at 5 workouts per session
    const size_t MAX_WORKOUTS = 5;

    // Data containers
    extern vector<string> activities;   // e.g. "Running"
    extern vector<string> dates;        // e.g. "2025-05-02"
    extern vector<double> durations;    // minutes logged
    extern unordered_map<string, double> workoutMap; // date → duration

    // Record workouts (no validation yet)
    void logWorkout();

    // Show workouts sorted by duration (desc)
    void displayLeaderboard();

    //date validation used here
    bool isValidDate(string date);
}
# endif


