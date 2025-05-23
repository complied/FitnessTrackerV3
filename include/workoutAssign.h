#ifndef WORKOUT_ASSIGN_H
#define WORKOUT_ASSIGN_H

#include <string>
#include <map>

using namespace std;

// encapsulating for priacy
// Demonstrates: Classes & Objects, Encapsulation, and Composition
class workoutAssign {
private:
    // Inner class to hold workout information
    class WorkoutDetails {
    public: //stored inside a nested class
        string name;
        string date;
        int duration;

        WorkoutDetails() = default;
        WorkoutDetails(const string& name, const string& date, int duration)
            : name(name), date(date), duration(duration) {}
    };

    // Map day (e.g., "Monday") to a specific workout
    map<string, WorkoutDetails> schedule;

public:
    // Collects workout info from user and prints the full plan
    void assignWorkout();
};

#endif
