#ifndef WORKOUT_H
#define WORKOUT_H

#include <string>
#include <iostream>

using namespace std;

// creating a class for all workout types now
class Workout {
public:

    Workout() = default; // setting a default constructor

    Workout(const string& name, const string& date, int duration)
        : name(name), date(date), duration(duration) {}

    // Virtual destructor - cleaner for pointers
    virtual ~Workout() = default;

    // Displays the workout info (based on the other sub classes though)
    virtual void show() const = 0;

    // Calculates calories burned
    virtual double calculateCalories(double weight) const = 0;

    // Accessible fields for now (we can encapsulate these later)
    string name;
    string date;
    int duration; // in minutes
};

#endif // WORKOUT_H
