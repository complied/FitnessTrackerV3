
#ifndef UTILS_WORKOUTRECOMMENDATION_H
#define UTILS_WORKOUTRECOMMENDATION_H

#include <string>
#include <vector>
#include <map>

using namespace std;

// Represents a single workout day with a name and list of exercises
class WorkoutDay {
private:
    string name;
    vector<string> exercises;

public:
    WorkoutDay();
    WorkoutDay(const string& name, const vector<string>& exercises);
    void display(int dayNumber) const;
};

// Manages recommendation logic for workout plans
class WorkoutRecommender {
private:
    map<string, vector<WorkoutDay>> workoutPlans;

public:
    WorkoutRecommender(); // Initializes default plans
    void recommendPlan(const string& level) const;
};

// Entry point for user-driven recommendation flow
void workoutReccomendation();
#endif