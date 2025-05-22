//
// Created by Subigya Parajuli on 5/22/25.
//

#include "Swimming.h"

using namespace std;

// constructor
Swimming::Swimming(const string& name, const string& date, int duration)
    : Workout(name, date, duration) {}

// show workout info
void Swimming::show() const {
    cout << setw(10) << "" << "[Swimming] " << name << " | " << date << " | " << duration << " min" << endl;
}

// calculate calories burned
double Swimming::calculateCalories(double weight) const {
    double met = 5.8;
    return 0.0175 * met * weight * duration;
}
