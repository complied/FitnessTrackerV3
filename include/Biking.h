//
// Created by Subigya Parajuli on 5/22/25.
//

#ifndef BIKING_H
#define BIKING_H

#include "WorkOut.h"
#include <string>
#include <iostream>

using namespace std;

class Biking : public Workout {
public:
    // constructor
    Biking(const string& name, const string& date, int duration);

    // show workout info
    void show() const override;

    // calculate calories burned
    double calculateCalories(double weight) const override;
};

#endif
