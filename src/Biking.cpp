//
// Created by Subigya Parajuli on 5/22/25.
//

#include "Biking.h"
#include "workOut.h"
#include <iomanip>
using namespace std;

// constructor
Biking::Biking(const string& name, const string& date, int duration)
    : Workout(name, date, duration) {}

// show workout info
void Biking::show() const {
    cout << setw(10) << "" << "[Biking] " << name << " | " << date << " | " << duration << " min" << endl;
}

// calculate calories burned
double Biking::calculateCalories(double weight) const {
    double met = 7.5;
    return 0.0175 * met * weight * duration;
}
