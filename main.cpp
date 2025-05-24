// main.cpp
// Fitness Tracker – Entry Point
// Created by Subigya Parajuli

#include "DisplayMenu.h"
#include "workoutLogger.h"
#include "workoutReccomendation.h"  // updated workout reccomendator
#include "workoutAssign.h"
#include "SongManager.h"            //  song manager
#include <iostream>
#include <limits>
#include <iomanip>

using namespace std;

int main() {
    WorkoutLog log;
    int choice;

    while (true) {
        DisplayMenu menu;
        menu.showMainMenu();

        cin >> choice;

        // Validate user input
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << setw(10) << "" << "Invalid input. Please try again.\n\n";
            continue;
        }

        // Handle menu options
        switch (choice) {
            case 1:
                log.logWorkout();  // Logging workouts with calorie calculation
                break;
            case 2:
                workoutReccomendation();  // Show workout plan recommendation
                break;
            case 3: {
                workoutAssign assigner;   // Declare inside scope to avoid jump error
                assigner.assignWorkout(); // Let user assign their weekly routine
                break;
            }
            case 4: {
                SongManager songApp;      // SongManager integration
                songApp.run();            // User inputs song info and stores it
                break;
            }
            case 6:
                cout << setw(10) << "" << "Goodbye!\n";
                return 0;
            default:
                cout << setw(10) << "" << "Invalid option. Please try again.\n";
        }

        // Wait for user before looping again
        cout << setw(10) << "" << "Press Enter to return to main menu...";
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin.get();
    }

    return 0;
}
