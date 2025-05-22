// workoutLogger.cpp
#include "../include/workoutLogger.h"
#include <limits>         // buffer
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <unordered_map>  // for seperating and comparing
#include <map>            // added for multimap sorting
using namespace std;

namespace logWorkout {

// Definitions for the externals declared in the header:
vector<string> activities;            // creating vector for each activity
vector<string> dates;                 //                          Date
vector<double> durations;             //                          durations
unordered_map<string, double> workoutMap; //                      leaderboard

// basic date check function
bool isValidDate(string date) {
    if (date.length() != 10 || date[4] != '-' || date[7] != '-') return false;

    string year = date.substr(0, 4);   //  year
    string month = date.substr(5, 2);  //  month
    string day = date.substr(8, 2);    //  day

    // checking that all characters are digits
    for (char ch : year + month + day) {
        if (!isdigit(ch)) return false;
    }
    int y = stoi(year);
    int m = stoi(month);
    int d = stoi(day);
    if (y >= 2026 || m < 1 || m > 12 || d < 1 || d > 31) return false;
    return true;
}

// for reacording workout
void logWorkout() {
    char choice = 'y';  //yes
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); //added for new line changes

    // Loop until user opts out or reaches the workout cap
    while ((choice == 'y' || choice == 'Y') && activities.size() < MAX_WORKOUTS) {
        cout << setw(10) << ""<< setfill('=') << setw(40) << "" << setfill(' ') << endl;

        // workout activity check
        string activity;
        do {
            cout << setw(10) << "" << "Enter workout activity: ";
            getline(cin, activity);   // used this for spaces
        } while (activity.empty());

        // date validation check
        string date;
        do {
            cout << setw(10) << "" << "Enter date (YYYY-MM-DD): ";
            getline(cin, date); // allows space here same thing

            if (!isValidDate(date)) {
                cout << setw(10) << "" << "Invalid format or value. Use YYYY-MM-DD and keep year before 2026.\n";
            }
        } while (!isValidDate(date));

        //checking time here
        double duration; // used double for better input
        while (true) {
            cout << setw(10) << "" << "Enter duration (min): ";
            cin >> duration;
            if (!cin.fail() && duration > 0) break;

            cin.clear(); // reset error flags
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // discard garbage input
            cout << setw(10) << "" << "Invalid duration. Try again.\n";
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard leftover newline

        // Store the inputs in the vector
        activities.push_back(activity);
        dates.push_back(date);
        durations.push_back(duration);
        workoutMap[date] = duration;  // Insert into map for sorting later

        cout << setw(10) << ""
             << setfill('=') << setw(40) << ""
             << setfill(' ') << endl;
        cout << setw(10) << "" << "Logged workout #" << activities.size() << "!" << endl;

        // If we've reached the maximum allowed workouts, break:
        if (activities.size() >= MAX_WORKOUTS) {
            cout << setw(10) << ""<< "Reached maximum of " << MAX_WORKOUTS << " workouts."
                 << endl;
            break;
        }

        //checking again if user wants to log another workout
        do {
            cout << setw(10) << "" << "Would you like to Log another workout? (y/n): ";
            cin >> choice;
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear newline
        } while (choice != 'y' && choice != 'Y' && choice != 'n' && choice != 'N');
    }

    displayLeaderboard();
}

// displayLeaderboard: sort by duration and print longest to shortest // just like the student project
void displayLeaderboard() {
    cout << setw(10) << "" << setfill('-') << setw(40) << "" << setfill(' ') << endl;
    cout << setw(10) << "" << "Here's your  Workout Leaderboard (longest to shortest):" << endl;

    multimap<double, string, greater<double>> sortedMap; // duration -> date (descending)
    for (const auto& entry : workoutMap) {
        sortedMap.insert({entry.second, entry.first});
    }

    for (const auto& p : sortedMap) {
        cout << setw(10) << ""
             << p.second << " : " << p.first << " min"
             << endl;
    }

    cout << setw(10) << "" << setfill('-') << setw(40) << "" << setfill(' ') << endl;
}

}
