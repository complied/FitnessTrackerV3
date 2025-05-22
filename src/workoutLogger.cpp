#include "workoutLogger.h"
#include <iomanip>      // for formatting output
#include <limits>       // for input stream validation
#include <stdexcept>    // for standard exceptions like invalid_argument

using namespace std;

// Constructor
WorkoutLog::WorkoutLog() = default;

// Validates the date string is in YYYY-MM-DD format
bool WorkoutLog::isValidDate(const string& date) const {
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

    // Reject future years and invalid calendar values
    if (y >= 2026 || m < 1 || m > 12 || d < 1 || d > 31) return false;

    return true;
}

// Handles user interaction for logging workouts
void WorkoutLog::logWorkout() {
    char choice = 'y';

    while ((choice == 'y' || choice == 'Y') && workouts.size() < MAX_WORKOUTS) {
        try {
            // Handles the entire input and object creation process
            shared_ptr<Workout> w = createWorkoutFromInput();
            workouts.push_back(w);
        } catch (const exception& e) {
            // Catches any thrown errors and displays the message
            cout << setw(10) << "" << "Error: " << e.what() << "\n";
            continue;
        }

        // Ask user if they want to log another workout
        cout << setw(10) << "" << "Log another workout? (y/n): ";
        cin >> choice;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    // Show leaderboard at the end
    printLeaderboard();
}

// Collects user input and creates a specific workout object
shared_ptr<Workout> WorkoutLog::createWorkoutFromInput() {
    string type, name, date;
    int duration = 0;

    // Prompt until valid type is selected
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

    // Auto-label the workout name for consistency
    name = type + " Session";

    // Validate date format
    cout << setw(10) << "" << "Enter date (YYYY-MM-DD): ";
    getline(cin, date);

    if (!isValidDate(date)) {
        throw invalid_argument("Date must be in YYYY-MM-DD format and within valid ranges.");
    }

    // Validate duration input
    cout << setw(10) << "" << "Enter duration in minutes: ";
    cin >> duration;

    if (cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        throw invalid_argument("Please enter a valid number for duration.");
    }

    if (duration <= 0) {
        throw out_of_range("Workout duration must be a positive number.");
    }

    // Clear input buffer
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    // Create the correct type of workout object
    if (type == "Running") {
        return make_shared<Running>(name, date, duration);
    } else if (type == "Swimming") {
        return make_shared<Swimming>(name, date, duration);
    } else {
        return make_shared<Biking>(name, date, duration);
    }
}

// Displays workouts sorted by calories burned (descending)
void WorkoutLog::printLeaderboard() const {
    if (workouts.empty()) {
        cout << setw(10) << "" << "No workouts to display.\n";
        return;
    }

    // Create a copy of the vector to sort without altering original data
    vector<shared_ptr<Workout>> sorted = workouts;

    // Sort workouts by calories burned using a lambda expression
    // comparing new sorting - a vs b
    sort(sorted.begin(), sorted.end(), [](const shared_ptr<Workout>& a, const shared_ptr<Workout>& b) {
        return a->calculateCalories(60) > b->calculateCalories(60); // defaulted weight to 60 kgs
    });

    // Display formatted leaderboard
    cout << setw(10) << "" << setfill('-') << setw(45) << "-" << setfill(' ') << endl;
    cout << setw(10) << "" << "Workout Leaderboard (60kg user):" << endl;

    for (const auto& w : sorted) {
        cout << setw(10) << "";
        w->show(); // Polymorphic display method from the derived class
        cout << setw(10) << "" << "Calories burned: "
             << fixed << setprecision(2) << w->calculateCalories(60) << " KCal\n\n";
    }

    cout << setw(10) << "" << setfill('-') << setw(45) << "-" << setfill(' ') << endl;
}
