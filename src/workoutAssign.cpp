#include "../include/workoutAssign.h"  // allows the function
#include "../include/workoutLogger.h" // Including workoutLogger to access activities and durations

using namespace std;
using namespace logWorkout; // Access activities, durations globally

namespace workoutManager {
    map<string, vector<shared_ptr<workout>>> workoutManager;

    workout::workout(const string &t, double d) : type(t), duration(d) {} // workout constructor

    void assignWorkoutToDay() {
        for (int i = 0; i < activities.size(); i++) { // switching through each workout
            string day;

            // assigning workout activity to selected day
            cout << setw(10) << "" << "Please Enter a day you want to assign the workout: [ " << activities[i] << " ] ";
            cin >> day;

            if (workoutManager[day].size() >= 5) { // limiting maximum to 5
                cout << setw(10) << "" << "Day is full! Cannot assign more workouts to " << day << ".\n";
                continue;
            }

            // Creating a shared_ptr pointing to a new Workout object
            shared_ptr<workout> workoutPtr = make_shared<workout>(activities[i], durations[i]);

            // Add the workout pointer to the selected day's vector inside the map
            workoutManager[day].push_back(workoutPtr);

            cout << setw(10) << "" << "Perfect! Your Workout [" << activities[i] << "] has been assigned to: " << day << "\n";
        }

        // displaying the whole workout map
        cout << "\n" << setw(10) << "" << "Workout Assignment Schedule:\n";

        if (workoutManager.empty()) {
            cout << setw(10) << "" << "No workouts have been assigned yet.\n";
        } else {
            for (const auto& pair : workoutManager) {
                cout << setw(10) << "" << pair.first << ":\n";
                for (const auto& workoutPtr : pair.second) {
                    cout << setw(15) << "" << "- " << workoutPtr->type << " (" << workoutPtr->duration << " min)\n";
                }
            }
        }
    }

}
