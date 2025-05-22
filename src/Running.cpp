//
// Created by Subigya Parajuli on 5/22/25.
//

#include "Running.h"


using namespace std;

// constructor
Running::Running(const string& name, const string& date, int duration)
    : Workout(name, date, duration) {}

// show workout info
void Running::show() const {
    cout << setw(10) << "" << "[Running] " << name << " | " << date << " | " << duration << " min" << endl;
}

// calculate calories burned
double Running::calculateCalories(double weight) const {
    double met = 9.8;
    return 0.0175 * met * weight * duration;
}
