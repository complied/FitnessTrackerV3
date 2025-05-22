// Included all the necesary libraries

#include "../include/workoutReccomendation.h"

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;
namespace workoutReccomendation {
     void workoutReccomendation() {
          cout << setfill(' ') << setw(10) << ""
               << setfill('=') << setw(40) << "" << endl;
          cout << setfill(' ') << setw(10) << ""
               << "Welcome to the Workout Recommender" << endl;
          cout << setfill(' ') << setw(10) << ""
               << setfill('=') << setw(40) << "" << endl;

          cout << setfill(' ') << setw(10) << ""
               << "Select difficulty level:" << endl;
          cout << setfill(' ') << setw(10) << "" << "1) Beginner" << endl;
          cout << setfill(' ') << setw(10) << "" << "2) Moderate" << endl;
          cout << setfill(' ') << setw(10) << "" << "3) InterMediate" << endl;
          cout << setfill(' ') << setw(10) << ""
               << "Enter choice (1-3): ";

          int choice;
          cin >> choice;
          // keep prompting until we get an integer in [1,2,3]
          while (cin.fail() || choice < 1 || choice > 3) {
               cin.clear();
               cin.ignore(numeric_limits<streamsize>::max(), '\n');
               cout << setfill(' ') << setw(10) << ""
                    << "Invalid choice! Please enter a number between 1 and 3: ";
               cin >> choice;
          }
          cin.ignore(numeric_limits<streamsize>::max(), '\n'); // fixed the double enter issue.

          Difficulty diff = static_cast<Difficulty>(choice); // different choices based on enum

          static const map<Difficulty, vector<WorkoutDay>> workoutPlans = { // different workout with different vector
               { Difficulty::Beginner, {
                         { "Push Day",       {"Push-ups", "Bench Press", "Tricep Dips", "Overhead Press"} },
                         { "Pull Day",       {"Pull-ups", "Lat Pulldown", "Bicep Curls", "Face Pulls"} },
                         { "Cardio Day",     {"Running", "Jump Rope", "Cycling", "Burpees"} },
                         { "Core Day",       {"Plank", "Russian Twists", "Leg Raises", "Mountain Climbers"} },
                         { "Flexibility Day",{"Yoga Stretches", "Hamstring Stretch", "Quad Stretch", "Shoulder Stretch"} }
               } },
               { Difficulty::Moderate, {
                         { "Push Day", {"Incline Bench Press", "Dumbbell Shoulder Press", "Tricep Dips", "Lateral Raises"} },
                         { "Pull Day", {"Deadlifts", "Chin-ups", "Bicep Curls", "Seated Row"} },
                         { "Leg Day",  {"Squats", "Lunges", "Leg Press", "Calf Raises"} },
                         { "Cardio Day",{"Treadmill Sprints", "Jump Rope", "Rowing Machine", "HIIT Workouts"} },
                         { "Core Day", {"Hanging Leg Raises", "V-Ups", "Cable Woodchoppers", "Ab Rollout"} },
                         { "HIIT Day", {"Burpee Downs", "Sprint Intervals", "Kettlebell Swings", "Battle Ropes"} }
               } },
               { Difficulty::InterMediate, {
                         { "Push Day",       {"Barbell Bench Press", "Dips", "Overhead Press", "Incline Dumbbell Press"} },
                         { "Pull Day",       {"Weighted Pull-ups", "Bent-over Rows", "Barbell Curls", "Face Pulls"} },
                         { "Leg Day",        {"Front Squats", "Romanian Deadlifts", "Leg Curls", "Standing Calf Raises"} },
                         { "Cardio Day",     {"Sprint Intervals", "Cycling", "Box Jumps", "Battle Ropes"} },
                         { "Upper Body",     {"Dumbbell Shoulder Press", "Chest Flys", "Lat Pulldown", "Triceps Extensions"} },
                         { "Full Body",      {"Power Cleans", "Deadlifts", "Kettlebell Swings", "Farmer's Walk"} },
                         { "Plyometric Day", {"Jump Squats", "Depth Jumps", "Plyo Push-ups", "Tuck Jumps"} },
                         { "Mobility Day",   {"Hip Openers", "Thoracic Rotations", "Ankle Mobility", "Band Pull-Aparts"} }
               } }
          };

          cout << endl << setfill(' ') << setw(10) << "" << "Your Workout Plan:" << endl;
          cout << setfill(' ') << setw(10) << "" << setfill('=') << setw(40) << "" << endl;

          const auto& plan = workoutPlans.at(diff); // .at MAP based function - checks for each of the given difficulty
          int daysToShow = static_cast<int>(plan.size());
          if (daysToShow > 6) daysToShow = 6;

          for (int i = 0; i < daysToShow; i++) { // increments through each to print a day - 6 days max
               cout << setfill(' ') << setw(10) << ""
                    << "Day " << (i + 1) << " - " << plan[i].name << ":" << endl; // Print each exercise for this day specifically
               for (const auto& exercise : plan[i].exercises) {
                    cout << setfill(' ') << setw(15) << ""
                         << "- " << exercise << endl;
               }
               cout << setfill(' ') << setw(10) << ""
                    << setfill('=') << setw(40) << "" << endl;
          }

          // fixed the double enter issue by moving the pause here
          cout << setfill(' ') << setw(10) << "" << "Please Press Enter to return to the main menu.";
          cin.get();
     }
}
