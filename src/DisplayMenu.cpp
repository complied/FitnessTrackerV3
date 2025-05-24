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

    cout << setw(5) << "" << "1) Log Workout + Calorie Calculator" << endl; // merged both functions for better personality
    cout << setw(5) << "" << "2) Workout Recommendation" << endl;
    cout << setw(5) << "" << "3) Routine Assigner" << endl;
    cout << setw(5) << "" << "4) Playlist Creator + File Saving" << endl;
    cout << setw(5) << "" << "5) Exit" << endl;

    cout << setfill('-') << setw(width) << "-" << endl << endl;
    cout << setw((width + 8) / 2) << ">> ";
}
