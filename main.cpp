// main.cpp
//  Fitness Tracker
//  Created by Subigya Parajuli on 2/10/25.
//


#include <iostream>
#include <iomanip>
#include <limits>
#include "include/workoutLogger.h"

using namespace std;

int main() {
    int choice;

    while (true) {
        // display menu
        cout << setw(10) << "" << "====================" << endl;
        cout << setw(10) << "" << "  FITNESS TRACKER" << endl;
        cout << setw(10) << "" << "====================" << endl;
        cout << setw(10) << "" << "1. Log Workout" << endl;
        cout << setw(10) << "" << "Enter your choice: ";
        cin >> choice;

        // clear input if bad
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << setw(10) << "" << "Invalid input. Please try again.\n";
            continue;
        }

        // switch case
        switch (choice) {
            case 1: {
                // log workouts
                WorkoutLog log;
                log.logWorkout();
                break;
            }
            default:
                cout << setw(10) << "" << "Invalid choice. Try again.\n";
        }

        // pause
        cout << setw(10) << "" << "Press Enter to return to menu...";
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin.get();
    }

    return 0;
}
