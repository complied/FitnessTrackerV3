//
// Created by Subigya Parajuli on 5/22/25.
//

#ifndef RUNNING_H
#define RUNNING_H

#include "Workout.h"
#include <string>
#include <iostream>
#include <iomanip>

using namespace std;

class Running : public Workout {
public:
    // created a constructor for running
    Running(const string& name, const string& date, int duration);

    // showing the workout based on the whats being updated
    void show() const override;

    // calculating the calories
    double calculateCalories(double weight) const override;
};

#endif
