//
// Created by Subigya Parajuli on 5/24/25.
//

#include "../include/workOut.h"

// Constructor implementation – initializes all values
Workout::Workout(const string& name, const string& date, int duration)
    : name(name), date(date), duration(duration) {}

// Destructor definition (even though it's defaulted)
Workout::~Workout() = default;
