//
// Created by Subigya Parajuli on 5/22/25.
//

#ifndef SWIMMING_H
#define SWIMMING_H

#include "WorkOut.h"
#include <string>
#include <iostream>
#include <iomanip>

using namespace std;

class Swimming : public Workout {
public:
    // constructor
    Swimming(const string& name, const string& date, int duration);

    // show workout info
    void show() const override;

    // calculate calories burned
    double calculateCalories(double weight) const override;
};

#endif