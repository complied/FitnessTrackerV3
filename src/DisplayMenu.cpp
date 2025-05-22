#include "DisplayMenu.h"
#include <iostream>
#include <iomanip>

using namespace std;

void DisplayMenu::showMainMenu() const {
    const int width = 50;

    cout << setfill('=') << setw(width) << "=" << endl;
    cout << setfill(' ') << setw((width + 28) / 2) << "Welcome to the Fitness Tracker" << endl;
    cout << setfill('=') << setw(width) << "=" << endl << endl;

    cout << setw((width + 32) / 2) << "Please choose an option below:" << endl;
    cout << setfill('-') << setw(width) << "-" << endl;

    cout << setw(5) << "" << "1) Calorie Checker" << endl;
    cout << setw(5) << "" << "2) Workout Recommendation" << endl;
    cout << setw(5) << "" << "3) Log Workout" << endl;
    cout << setw(5) << "" << "4) Routine Assigner" << endl;
    cout << setw(5) << "" << "5) Save and Read Workout Data" << endl;
    cout << setw(5) << "" << "6) Exit" << endl;

    cout << setfill('-') << setw(width) << "-" << endl << endl;
    cout << setw((width + 8) / 2) << ">> ";
}
