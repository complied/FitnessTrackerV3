
#ifndef Utils_wworkoutReccomendation
#define Utils_wworkoutReccomendation

// Included all the necesary libraries
#include <iostream>
#include <iomanip>
#include <string>
#include <vector> // swapped from ararys to vector for better usauge
#include <map> // using for .at - for picking difficulty

using namespace std;

namespace workoutReccomendation {

    // now creating enum workout class for different workouts

    enum class Difficulty{
        Beginner =1,
        Moderate = 2,
        InterMediate = 3

    };

    struct WorkoutDay {
        string name;               // Workout day label
        vector<string> exercises;  // Exercises for this day
    };

    void workoutReccomendation();

}


# endif


