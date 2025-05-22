#include "../include/calorieChecker.h"
#include <fstream>
#include <limits>
#include <cstring>

using namespace std;

namespace calorieChecker {

    // Converts a workout name string into the corresponding enum value.
    WorkoutType parseWorkout(const string& s) {
        if (s == "Running")
            return WorkoutType::Running;  // mapping straight to enum
        if (s == "Swimming")
            return WorkoutType::Swimming;
        return WorkoutType::Biking;  // last option so default
    }

    void calorieCalculator() {
        // storing this at 0 for safety and clarity
        string workOuts;         // holds user input for workout type
        double weight = 0.0;     // holds user input for weight
        double duration = 0.0;   // holds user input for duration
        double burned = 0.0;     // will store computed calories

        // selecting the workouts now
        while (true) {
            cout << setfill(' ') << setw(10) << "" << setfill('=') << setw(40) << "" << endl;
            cout << setfill(' ') << setw(10) << "" << "[Running] - [Swimming] - [Biking]" << endl;
            cout << setfill(' ') << setw(10) << "" << "Choose one of the following: ";
            cin >> workOuts;

            if (workOuts == "Running" || workOuts == "Swimming" || workOuts == "Biking") {
                break;
            }
            cout << setfill(' ') << setw(10) << "" << "Invalid choice, try again." << endl;
        }

        // User entering weight with input validation
        while (true) {
            cout << setfill(' ') << setw(10) << "" << "Please Enter Your Weight In Kgs:\n";
            cout << setfill(' ') << setw(10) << "" << ">> ";
            cin >> weight;

            if (cin.fail() || weight <= 0) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << setfill(' ') << setw(10) << "" << "Invalid input. Please enter a valid number.\n";
            } else {
                break;
            }
        }

        // User entering duration with input validation
        while (true) {
            cout << setfill(' ') << setw(10) << "" << "Please Enter Your Duration In Minutes:\n";
            cout << setfill(' ') << setw(10) << "" << ">> ";
            cin >> duration;

            if (cin.fail() || duration <= 0) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << setfill(' ') << setw(10) << "" << "Invalid input. Please enter a valid number.\n";
            } else {
                break;
            }
        }

        // Total burnt calories
        WorkoutType wt = parseWorkout(workOuts);  // changing from STRING to ENUM
        if (wt == WorkoutType::Running) {
            burned = weight * 0.0175 * 9.8 * duration;
        }
        else if (wt == WorkoutType::Swimming) {
            burned = weight * 0.0175 * 7.0 * duration;
        }
        else {
            burned = weight * 0.0175 * 8.0 * duration;
        }

        cout << fixed << setprecision(2);
        cout << setfill(' ') << setw(10) << "" << "Your estimated calories burned are:\n";
        cout << setfill(' ') << setw(10) << "" << ">> " << burned << " KCal\n";
    }

    void emergencyTracker() {
        // Create a CalorieSession instance on the heap
        unique_ptr<CalorieSession> session = make_unique<CalorieSession>();

        string workOuts;
        while (true) {
            cout << setfill(' ') << setw(10) << "" << setfill('=') << setw(40) << "" << endl;
            cout << setfill(' ') << setw(10) << "" << "[Running] - [Swimming] - [Biking]" << endl;
            cout << setfill(' ') << setw(10) << "" << "Choose emergency workout: ";
            cin >> workOuts;

            if (workOuts == "Running" || workOuts == "Swimming" || workOuts == "Biking") {
                break;
            }
            cout << setfill(' ') << setw(10) << "" << "Invalid input. Try again." << endl;
        }

        session->type = parseWorkout(workOuts);

        // Validate weight input
        while (true) {
            cout << setfill(' ') << setw(10) << "" << "Enter weight (kg):\n";
            cout << setfill(' ') << setw(10) << "" << ">> ";
            cin >> session->weight;

            if (cin.fail() || session->weight <= 0) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << setfill(' ') << setw(10) << "" << "Invalid input. Please enter a number.\n";
            } else {
                break;
            }
        }

        // Validate duration input
        while (true) {
            cout << setfill(' ') << setw(10) << "" << "Enter duration (min):\n";
            cout << setfill(' ') << setw(10) << "" << ">> ";
            cin >> session->duration;

            if (cin.fail() || session->duration <= 0) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << setfill(' ') << setw(10) << "" << "Invalid input. Please enter a number.\n";
            } else {
                break;
            }
        }

        // Compute calories burned and store
        if (session->type == WorkoutType::Running) {
            session->calories = session->weight * 0.0175 * 9.8 * session->duration;
        }
        else if (session->type == WorkoutType::Swimming) {
            session->calories = session->weight * 0.0175 * 7.0 * session->duration;
        }
        else {
            session->calories = session->weight * 0.0175 * 8.0 * session->duration;
        }

        const string path = "/Users/subigyaparajuli/Desktop/FitnessTrackerV2/data/emergency_session.csv";
        ofstream outFile(path, ios::app);
        if (outFile.is_open()) {
            outFile << workOuts << ","
                    << session->weight << ","
                    << session->duration << ","
                    << session->calories << endl;
            outFile.close();
        } else {
            cerr << "Error: Could not open " << path << " for writing." << endl;
        }

        // Save to Binary
        struct BinarySession {
            char workout[30];
            double weight;
            double duration;
            double calories;
        };

        BinarySession binarySession;
        strncpy(binarySession.workout, workOuts.c_str(), sizeof(binarySession.workout));
        binarySession.weight = session->weight;
        binarySession.duration = session->duration;
        binarySession.calories = session->calories;

        ofstream binaryOut("/Users/subigyaparajuli/Desktop/FitnessTrackerV2/data/emergency_session.dat", ios::binary | ios::app);
        if (binaryOut.is_open()) {
            binaryOut.write(reinterpret_cast<char*>(&binarySession), sizeof(BinarySession));
            binaryOut.close();

            cout << setfill(' ') << setw(10) << "" << "Your total calories that have been burnt is:\n";
            cout << setfill(' ') << setw(10) << "" << ">> " << fixed << setprecision(2) << session->calories << " KCal\n";
            cout << setfill(' ') << setw(10) << "" << "Now it is being stored in your file." << endl;
        } else {
            cerr << "Error: Could not open binary file for writing.\n";
        }
    }

}
