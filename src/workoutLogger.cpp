#include "workoutLogger.h"
#include <iomanip>      // for formatting
#include <limits>       // for input validation

using namespace std;

// Constructor
WorkoutLog::WorkoutLog() = default;

// Validates YYYY-MM-DD format
bool WorkoutLog::isValidDate(const string& date) const {
    if (date.length() != 10 || date[4] != '-' || date[7] != '-') return false;

    string year = date.substr(0, 4);
    string month = date.substr(5, 2);
    string day = date.substr(8, 2);  //  FIXED TYPO here

    for (char ch : year + month + day) {
        if (!isdigit(ch)) return false;
    }

    int y = stoi(year);
    int m = stoi(month);
    int d = stoi(day);

    if (y >= 2026 || m < 1 || m > 12 || d < 1 || d > 31) return false;

    return true;
}

// Logs a single workout
void WorkoutLog::logWorkout() {
    char choice = 'y';

    while ((choice == 'y' || choice == 'Y') && workouts.size() < MAX_WORKOUTS) {
        shared_ptr<Workout> w = createWorkoutFromInput();
        workouts.push_back(w);

        cout << setw(10) << "" << "Log another workout? (y/n): ";
        cin >> choice;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    printLeaderboard();
}

// Dynamically create a specific type of workout based on user input
shared_ptr<Workout> WorkoutLog::createWorkoutFromInput() {
    string type, name, date;
    int duration = 0;

    while (true) {
        cout << setw(10) << "" << "Please choose workout type [Running / Swimming / Biking]: ";
        cin >> type;

        if (type == "Running" || type == "Swimming" || type == "Biking") {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            break;
        }
        cout << setw(10) << "" << "Invalid type. Try again.\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }


    name = type + " Session"; // replaced this - Now users can auto set baed on the deal


    do {
        cout << setw(10) << "" << "Enter date (YYYY-MM-DD): ";
        getline(cin, date);
        if (!isValidDate(date)) {
            cout << setw(10) << "" << "Invalid date format. Try again.\n";
        }
    } while (!isValidDate(date));

    while (true) {
        cout << setw(10) << "" << "Enter duration in minutes: ";
        cin >> duration;

        if (cin.fail() || duration <= 0) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << setw(10) << "" << "Invalid duration. Try again.\n";
        } else {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            break;
        }
    }

    if (type == "Running") {
        return make_shared<Running>(name, date, duration);
    } else if (type == "Swimming") {
        return make_shared<Swimming>(name, date, duration);
    } else {
        return make_shared<Biking>(name, date, duration);
    }
}

// Sort and display leaderboard
void WorkoutLog::printLeaderboard() const {
    if (workouts.empty()) {
        cout << setw(10) << "" << "No workouts to display.\n";
        return;
    }

    vector<shared_ptr<Workout>> sorted = workouts;
    sort(sorted.begin(), sorted.end(), [](const shared_ptr<Workout>& a, const shared_ptr<Workout>& b) {
        return a->calculateCalories(60) > b->calculateCalories(60);
    });

    cout << setw(10) << "" << setfill('-') << setw(45) << "-" << setfill(' ') << endl;
    cout << setw(10) << "" << "Workout Leaderboard (60kg user):" << endl;

    for (const auto& w : sorted) {
        cout << setw(10) << "";
        w->show();
        cout << setw(10) << "" << "Calories burned: "
             << fixed << setprecision(2) << w->calculateCalories(60) << " KCal\n\n";
    }

    cout << setw(10) << "" << setfill('-') << setw(45) << "-" << setfill(' ') << endl;
}
