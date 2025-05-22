/*#ifndef DAYWORKOUTMANAGER_HPP
#define DAYWORKOUTMANAGER_HPP

#include <iostream>
#include <map> // helpfull for grouping all 3 Vecotors, string , shared pointer
#include <vector> // space
#include <memory> // pointers
#include <string> // letters

using namespace std;


//creating namespace for better usage in cpp and main
namespace workoutManager {
    struct workout{ //creating struct for better object management
        string type; // workout type
        double duration; // creating a duration for the workout

        workout(const string &t, double d); // constructor - easier to use
    };

    // Map to organize workouts by day
    // Key = day name ("Monday", "Tuesday", etc.)
    // Value = list of workouts for that day using shared_ptr
    extern map<string, vector<shared_ptr<workout>>> workoutManager;


    // conneting existing workouts to days!
    void assignWorkoutToDay();
}




#endif
*/