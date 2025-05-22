# V2 STARTED FROM VERSION 0.5

# Fitness Tracker

## Overview
A simple C++ program that helps users log workouts, get workout recommendations, assign routines, and calculate calories burned based on activity type.

## Features
+ Log workout activity, date, and duration
    - Full input validation (activity name, date format YYYY-MM-DD, duration > 0)
    - Uses unordered_map and multimap to organize data and sort leaderboard by duration

+ Get personalized workout recommendations based on fitness level
    - Beginner (3-day), Moderate (4-day), Intermediate (6-day)
    - Mapped with structured plans using enums, maps, and vectors

+ Assign logged workouts to days of the week
    - Integrates with workoutLogger
    - Uses shared_ptr and map<string, vector<shared_ptr<workout>>> for clean assignment
    - Limit: Max 5 workouts per day

+ Calculate calories burned
    - Based on MET values for Running, Swimming, and Biking
    - Requires weight and duration inputs
    - Accurate calculations with formatted output

+ Emergency session logging
    - Save workouts into .csv and binary files
    - Supports urgent calorie tracking use case

+ View emergency session logs
    - Displays all logged binary sessions in formatted output
    - Error handling for file read/write issues

+ Organized modular structure
    - Each component in its own namespace and file
    - Uses enums, structs, STL containers

+ Unit Tested with GoogleTest
    - Core functions like parseWorkout and isValidDate tested
    - Compile and run via CMake or CLion

+ Formatted UI
    - setfill, setw, and spacing used to align terminal output

+ Bug Fixes with visual proof:
    - Before (Workout skipped, input broken): https://imgur.com/a/4EvP0jg
    - After (Clean input, structured logging): https://imgur.com/a/vvwaKLP

---

## Version History

### V - 0.1
+ Added a Display function with error handling
+ Proper display with `<iomanip>` library implementation

### V - 0.2
+ New Feature: Calorie Calculator to estimate calories burned based on weight, workout type, and duration
+ Supports Running, Swimming, Biking with specific MET values
+ User-friendly formatted output with input error handling
+ Updated Menu for better flexibility

### V - 0.3
+ Enhanced CalorieChecker with strong input validation (cin.fail, cin.ignore)
+ Removed old Fitness.cpp/Fitness.hpp files
+ Separated functionality into modular .cpp and .hpp files
+ New Feature: WorkoutRecommendation (Beginner/Moderate/Intermediate plans)

### V - 0.4
+ Created WorkoutLogger
    - Logs up to 15 workouts using arrays (activity + duration)
    - Added support for y/n inputs to continue or stop logging
+ Improved input handling with getline and cin.ignore
+ Updated main loop to prevent accidental exits
+ Added menu option 4 to exit cleanly

### V - 0.5.5
+ Implemented AssignWorkoutDay function
    - Connects to global arrays from WorkoutLogger
    - Assigns workouts to days using shared_ptr in a map
    - Limit: Max 5 workouts per day
+ Fixed white space bug
    - Missing break in switch-case fixed
    - cin.ignore adjusted only when workoutCount == 0

### V - 0.6
+ Rebuilt WorkoutRecommendation
    - Replaced 2D arrays with maps and vectors
    - Structured using enums and structs
    - Added user-selectable difficulty levels

### V - 0.7
+ Rebuilt WorkoutLogger
    - Replaced arrays with vectors and unordered_map
    - Leaderboard logic switched from std::sort to multimap
+ Improved validation for activity, duration, and date
    - Ensures input is valid and date is pre-2026

### V - 0.8
+ Connected Workout Assign with Workout Logger
    - Assign workouts with date/duration to specific weekdays
    - Used shared_ptr and safe memory handling
+ Cleaned up main logic and whitespace bugs

### V - 0.9
+ Fixed File Manager
    - Now reads binary logs saved from WorkoutLogger
    - Clean session display on terminal
    - Struct alignment fixed for read/write consistency
    - Added file error handling for robustness

### V - 10.0
+ Added GoogleTest support for unit testing

  How to run?
    1. Build the test target:
       `$ cmake --build . --target test_main`
    2. Run the tests:
       `$ ./test_main`
    3. View results in terminal (pass/fail)

---

## Demo Links

+ YouTube Video (V1): https://www.youtube.com/watch?v=IcDLU2BOBRM
+ Link to V1 GitHub Repo: https://github.com/complied/FitnessTracker
+ V2 Demo (Google Drive): https://drive.google.com/drive/u/0/folders/1oEat0s--AFmA0revnO6Cva3JIh2uH4mm

---

## Some Sources Used to Complete This Project

+ https://www.geeksforgeeks.org/
+ https://stackoverflow.com/
+ https://cplusplus.com/doc/
+ https://devdocs.io/cpp/
+ https://en.cppreference.com/w/
+ https://www.learncpp.com/
+ https://www.instituteoflifestylemedicine.org/wp-content/uploads/2015/04/METValues.pdf  (MET PDF)
