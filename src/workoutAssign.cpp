#include "workoutAssign.h"
#include <iostream>
#include <iomanip>
#include <limits>

using namespace std;

// Handles full flow: collect workouts, then print schedule
void workoutAssign::assignWorkout() {
    char repeat = 'y';

    while (tolower(repeat) == 'y') {
        string day, name, date;
        int duration;

        // Get user input for the assignment
        cout << setw(10) << "" << "Enter day (Eg: Monday): ";
        cin >> day;
        cin.ignore();

        cout << setw(10) << "" << "Enter workout name: ";
        getline(cin, name);

        cout << setw(10) << "" << "Enter date (YYYY-MM-DD): ";
        getline(cin, date);

        cout << setw(10) << "" << "Enter duration in minutes: ";
        cin >> duration;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        // Prevent duplicate assignment
        if (schedule.find(day) != schedule.end()) {
            cout << setw(10) << "" << "Workout already assigned for " << day << ". Try another day.\n";
        } else {
            // Assign workout info to the map for that day
            WorkoutDetails details;
            details.name = name;
            details.date = date;
            details.duration = duration;
            schedule[day] = details;

            cout << setw(10) << "" << "Workout assigned to " << day << " successfully.\n";
        }

        cout << setw(10) << "" << "Assign another workout? (y/n): ";
        cin >> repeat;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    // Final schedule output
    cout << "\n" << setw(10) << "" << "--- Weekly Workout Plan ---\n";
    if (schedule.empty()) {
        cout << setw(10) << "" << "No workouts assigned.\n";
    } else {
        for (const auto& entry : schedule) {
            const string& day = entry.first;
            const WorkoutDetails& w = entry.second;
            cout << setw(10) << "" << day << ": "
                 << w.name << " | " << w.date << " | "
                 << w.duration << " min\n";
        }
    }
}
