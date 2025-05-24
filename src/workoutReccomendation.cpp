#include "workoutReccomendation.h"
#include <iostream>
#include <iomanip>
#include <stdexcept> // for std::invalid_argument

using namespace std;

// Default constructor creaakted - workday
WorkoutDay::WorkoutDay() : name("Untitled"), exercises({}) {}

// Creates a workout day with a name and list of exercises
WorkoutDay::WorkoutDay(const string& name, const vector<string>& exercises)
    : name(name), exercises(exercises) {}

// Display view of a single workout day
void WorkoutDay::display(int dayNumber) const {
    cout << setw(10) << "" << "Day " << dayNumber << ": " << name << "\n";
    for (const string& ex : exercises) {
        cout << setw(14) << "" << "- " << ex << "\n";
    }
    cout << "\n";
}

// Initializes workout plans for different difficulty levels
WorkoutRecommender::WorkoutRecommender() {
    // Updated new workout routines - beginner
    workoutPlans["Beginner"] = {
        WorkoutDay("Push Day",       {"Push-ups", "Bench Press", "Tricep Dips", "Overhead Press"}),
        WorkoutDay("Pull Day",       {"Pull-ups", "Lat Pulldown", "Bicep Curls", "Face Pulls"}),
        WorkoutDay("Cardio Day",     {"Running", "Jump Rope", "Cycling", "Burpees"}),
        WorkoutDay("Core Day",       {"Plank", "Russian Twists", "Leg Raises", "Mountain Climbers"}),
        WorkoutDay("Flexibility Day",{"Yoga Stretches", "Hamstring Stretch", "Quad Stretch", "Shoulder Stretch"})
    };

    // Updated new workout routines - intermediate
    workoutPlans["Intermediate"] = {
        WorkoutDay("Push Day", {"Incline Bench Press", "Dumbbell Shoulder Press", "Tricep Dips", "Lateral Raises"}),
        WorkoutDay("Pull Day", {"Deadlifts", "Chin-ups", "Bicep Curls", "Seated Row"}),
        WorkoutDay("Leg Day",  {"Squats", "Lunges", "Leg Press", "Calf Raises"}),
        WorkoutDay("Cardio Day",{"Treadmill Sprints", "Jump Rope", "Rowing Machine", "HIIT Workouts"}),
        WorkoutDay("Core Day", {"Hanging Leg Raises", "V-Ups", "Cable Woodchoppers", "Ab Rollout"}),
        WorkoutDay("HIIT Day", {"Burpee Downs", "Sprint Intervals", "Kettlebell Swings", "Battle Ropes"})
    };

    // Updated new workout routines - advanced
    workoutPlans["Advanced"] = {
        WorkoutDay("Push Day",       {"Barbell Bench Press", "Dips", "Overhead Press", "Incline Dumbbell Press"}),
        WorkoutDay("Pull Day",       {"Weighted Pull-ups", "Bent-over Rows", "Barbell Curls", "Face Pulls"}),
        WorkoutDay("Leg Day",        {"Front Squats", "Romanian Deadlifts", "Leg Curls", "Standing Calf Raises"}),
        WorkoutDay("Cardio Day",     {"Sprint Intervals", "Cycling", "Box Jumps", "Battle Ropes"}),
        WorkoutDay("Upper Body",     {"Dumbbell Shoulder Press", "Chest Flys", "Lat Pulldown", "Triceps Extensions"}),
        WorkoutDay("Full Body",      {"Power Cleans", "Deadlifts", "Kettlebell Swings", "Farmer's Walk"}),
        WorkoutDay("Plyometric Day", {"Jump Squats", "Depth Jumps", "Plyo Push-ups", "Tuck Jumps"}),
        WorkoutDay("Mobility Day",   {"Hip Openers", "Thoracic Rotations", "Ankle Mobility", "Band Pull-Aparts"})
    };
}

// displaying specific levels
void WorkoutRecommender::recommendPlan(const string& level) const {
    auto it = workoutPlans.find(level);

    // Exception handling: invalid level throws error instead of printing
    if (it == workoutPlans.end()) {
        throw invalid_argument("Invalid level. Please enter Beginner, Intermediate, or Advanced.");
    }

    cout << setw(10) << "" << "Workout Plan: " << level << "\n";
    cout << setw(10) << "" << setfill('-') << setw(40) << "-" << setfill(' ') << "\n";

    const vector<WorkoutDay>& plan = it->second;
    for (size_t i = 0; i < plan.size(); i++) {
        plan[i].display(static_cast<int>(i) + 1);
    }
}

// gives the user chance for a level and runs the recommendation logic
void workoutReccomendation() {
    WorkoutRecommender recommender;
    string level;

    cout << setw(10) << "" << "Enter level [Beginner / Intermediate / Advanced]: ";
    cin >> level;

    // clear input stream in case junk follows (e.g., "Beginner123")
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    try {
        // If user typed nothing or just a number, this will throw
        if (level.empty() || isdigit(level[0])) {
            throw invalid_argument("Invalid input. Please enter a valid level.");
        }

        // Try to recommend the workout plan
        recommender.recommendPlan(level);
    }
    catch (const invalid_argument& e) {
        cout << setw(10) << "" << "Error: " << e.what() << "\n";
    }
}