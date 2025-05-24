#include "workoutAssign.h"
#include <iostream>
#include <iomanip>
#include <limits>
#include <stdexcept> // For std::invalid_argument

using namespace std;

// Helper function to validate YYYY-MM-DD format
bool isValidDate(const string& date) {
    if (date.length() != 10 || date[4] != '-' || date[7] != '-') return false;

    string year = date.substr(0, 4);
    string month = date.substr(5, 2);
    string day = date.substr(8, 2);

    for (char ch : year + month + day) {
        if (!isdigit(ch)) return false;
    }

    int y = stoi(year);
    int m = stoi(month);
    int d = stoi(day);

    if (y > 2026 || m < 1 || m > 12 || d < 1 || d > 31) return false;

    return true;
}

// Handles full flow: collect workouts, then print schedule
void workoutAssign::assignWorkout() {
    char repeat = 'y';

    // Flush leftover newline from previous input (main menu selection)
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    while (tolower(repeat) == 'y') {
        string day, name, date;
        int duration;

        // Get user input for the assignment
        cout << setw(10) << "" << "Enter day (Eg: Monday): ";
        getline(cin, day);  // changed from cin >> day to getline to handle spaces

        cout << setw(10) << "" << "Enter workout name: ";
        getline(cin, name);

        // Handle date input with exception for invalid format
        while (true) {
            try {
                cout << setw(10) << "" << "Enter date (YYYY-MM-DD): ";
                getline(cin, date);
                if (!isValidDate(date)) {
                    throw invalid_argument("Date must be in format YYYY-MM-DD and realistic");
                }
                break;
            } catch (const invalid_argument& e) {
                cout << setw(10) << "" << "Error: " << e.what() << "\n";
            }
        }

        // Handle duration input and validate with exception
        while (true) {
            try {
                cout << setw(10) << "" << "Enter duration in minutes: ";
                cin >> duration;

                if (cin.fail() || duration <= 0) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    throw invalid_argument("Duration must be a positive number");
                }

                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                break;
            } catch (const invalid_argument& e) {
                cout << setw(10) << "" << "Error: " << e.what() << "\n";
            }
        }

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
