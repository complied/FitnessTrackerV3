// main.cpp
// Fitness Tracker – Entry Point
// Created by Subigya Parajuli

#include "DisplayMenu.h"
#include "workoutLogger.h"
#include "workOut.h"
#include <iostream>
#include <limits>
#include <iomanip>

using namespace std;

int main() {
    WorkoutLog log;  //updated logging system
    int choice;

    while (true) {

        DisplayMenu menu;
        menu.showMainMenu();
        cin >> choice;

        // User Handling
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << setw(10) << "" << "Invalid input. Please try again.\n\n";
            continue;
        }

        switch (choice) {
            case 1:
                log.logWorkout(); //testing logging system
                break;
            case 6:
                cout << setw(10) << "" << "Goodbye!\n";
                return 0;
            default:
                cout << setw(10) << "" << "Invalid option. Please try again.\n";
        }

        cout << setw(10) << "" << "Press Enter to return to main menu...";
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin.get();
    }

    return 0;
}
