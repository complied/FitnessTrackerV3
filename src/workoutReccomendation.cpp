#include "workoutReccomendation.h"
#include <iostream>
#include <iomanip>

using namespace std;

// Constructor for WorkoutDay
WorkoutDay::WorkoutDay(const string& name, const vector<string>& exercises)
    : name(name), exercises(exercises) {}


// Diplaying the workout day and its exercises
void WorkoutDay::display(int dayNumber) const {
    cout << setw(10) << "" << "Day " << dayNumber << ": " << name << "\n";
    for (const string& ex : exercises) {
        cout << setw(14) << "" << "- " << ex << "\n";
    }
    cout << "\n";
}

// Initializes all plans in constructor
WorkoutRecommender::WorkoutRecommender() {
    workoutPlans["Beginner"] = {
        WorkoutDay("Full Body Intro", {"10 min walk", "10 squats", "5 pushups"}),
        WorkoutDay("Stretch + Core", {"15 min stretching", "10 crunches", "10 leg lifts"}),
        WorkoutDay("Cardio Light", {"15 min cycling", "5 min jog"})
    };

    workoutPlans["Intermediate"] = {
        WorkoutDay("Push Day", {"Bench Press", "Shoulder Press", "Push-ups"}),
        WorkoutDay("Pull Day", {"Deadlift", "Pull-ups", "Barbell Row"}),
        WorkoutDay("Leg Day", {"Squats", "Lunges", "Leg Press"})
    };

    workoutPlans["Advanced"] = {
        WorkoutDay("HIIT", {"Burpees", "Mountain Climbers", "Jump Squats"}),
        WorkoutDay("Strength Max", {"Deadlift (5x5)", "Bench (5x5)", "Squat (5x5)"}),
        WorkoutDay("Endurance Run", {"10K run", "Cooldown walk", "Stretching"})
    };
}

// Prints the plan for a given level (Beginner, etc.)
void WorkoutRecommender::recommendPlan(const string& level) const {
    auto it = workoutPlans.find(level);
    if (it == workoutPlans.end()) {
        cout << setw(10) << "" << "Invalid level. Please enter Beginner, Intermediate, or Advanced.\n";
        return;
    }

    cout << setw(10) << "" << "Workout Plan: " << level << "\n";
    cout << setw(10) << "" << setfill('-') << setw(35) << "-" << setfill(' ') << "\n";

    const vector<WorkoutDay>& plan = it->second;
    for (size_t i = 0; i < plan.size(); ++i) {
        plan[i].display(static_cast<int>(i) + 1);
    }
}

// Main entry point with user input prompt
void workoutReccomendation() {
    WorkoutRecommender recommender;
    string level;

    cout << setw(10) << "" << "Enter level [Beginner / Intermediate / Advanced]: ";
    cin >> level;

    recommender.recommendPlan(level);
}
