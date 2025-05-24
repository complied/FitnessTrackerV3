# V3 STARTED FROM VERSION 0.11

# Fitness Tracker

## Overview
A terminal-based C++ program that helps users track workouts, calculate calories, assign routines, receive weekly fitness plans, and now build a personal music playlist. Version 3 is a complete Object-Oriented Programming (OOP) upgrade, transforming the procedural code of Project 2 into a modular and extensible system using classes, abstraction, encapsulation, inheritance, and polymorphism.

## Features

+ **Log workout activity with calorie calculation**
  - Merged functionality: User logs activity + calculates calories in one flow
  - Includes date, workout name, and duration
  - Uses virtual functions via base class `Workout` with derived classes: `Running`, `Swimming`, and `Biking`
  - MET-based calorie calculation with formatted output
  - Clean memory management using `shared_ptr`

+ **Get OOP-Based Workout Recommendations**
  - User chooses Beginner (3-day), Moderate (4-day), or Intermediate (6-day) plan
  - Uses `enum class` for difficulty levels and maps each to a full week plan
  - Fully refactored to class-based design with modular suggestions

+ **Assign Weekly Routines**
  - Users assign their own custom workouts to weekdays
  - Internally uses a class `workoutAssign` with private data map
  - Follows single-class architecture (removed use structs)
  - Validates and stores each entry (day, workout name, date, duration)
  - Demonstrates encapsulation and clean map-based printing

+ **Playlist Creator (NEW in V3)**
  - Lets users add songs (title and author)
  - Saves data to CSV and Binary files: `../data/songLibrary.csv` and `../data/songLibrary.dat`
  - Appends rather than overwrites files
  - Uses `ofstream` and `ifstream` streams to store and read playlist data
  - Reads back entries and shows them in terminal after writing
  - Encapsulated within `SongManager` and `Song` classes

+ **Formatted UI + Modular Design**
  - `setw`, `setfill`, and terminal padding used for clean output
  - Each logical unit split into separate `.cpp` and `.hpp` files
  - Adheres to clean modular design principles

+ **GoogleTest Integration**
  - GoogleTest integrated via `CMakeLists.txt` using `gtest_discover_tests()`
  - Tests key features like calorie calculations, workout construction, and song metadata
  - Uses assertions like `EXPECT_EQ`, `EXPECT_TRUE`, and `EXPECT_NEAR`
  - All tests pass and are organized in a single modular test file

+ **Bug Fixes + Clean Refactors**
  - Fixed constructor call logic for Workout-derived classes
  - Addressed input validation (especially duration, dates)
  - Fixed scope jump bugs in `main.cpp` by wrapping block-scoped variables
  - Removed legacy calorieChecker.cpp (now fully handled by WorkoutLog)
  - Cleaned up whitespace, switched to clear formatting

## Version History

### V - 0.11
+ Refactored `WorkoutLogger` and calorie calculator into a single class `WorkoutLog`
+ Combined logging and MET-based calorie burn into one cohesive feature
+ Added class hierarchy: abstract base class `Workout` and derived types `Running`, `Swimming`, `Biking`

### V - 0.12
+ Refactored WorkoutRecommendation module using enum class `Difficulty`
+ Used `unordered_map<string, vector<string>>` to structure daily plans
+ Ensured plan integrity, consistent output formatting, and clean logic

### V - 0.13
+ Rebuilt RoutineAssigner using OOP design (no struct, no tuple, no 2-class split)
+ Assigns workouts to weekdays with name, date, and duration
+ Demonstrated encapsulation by using internal class to manage all data
+ Displays final schedule after all inputs

### V - 0.14
+ Added input validation and exception handling to RoutineAssigner
+ Implemented `isValidDate()` function for verifying YYYY-MM-DD format
+ Used try/catch blocks to handle incorrect date inputs

### V - 0.15
+ Introduced Playlist Creator feature (`SongManager.cpp`, `Song.cpp`)
+ Allows users to store song name + author
+ Stores song data in both `.csv` and `.dat` formats
+ Uses binary serialization with raw byte writing and reading

### V - 0.16
+ Added user interaction and storage logic to `SongManager::run()`
+ Automatically saves files under `data/songLibrary.csv` and `data/songLibrary.dat`
+ Fixed issues with file handling and default constructor errors
+ Fully integrated playlist option into main menu flow (case 4)

---

## Demo Links

+ YouTube Video (V1): https://www.youtube.com/watch?v=IcDLU2BOBRM
+ GitHub V1 Repo: https://github.com/complied/FitnessTracker
+ V2 Demo (Google Drive): https://drive.google.com/drive/u/0/folders/1oEat0s--AFmA0revnO6Cva3JIh2uH4mm
+ V3 Demo (Google Drive): https://drive.google.com/drive/u/0/folders/1udJk_Lcdud6wR-DeXRxGr1ro0jXRwJOS

---

## Running Tests

This project uses GoogleTest for unit testing. To build and run the tests:

```bash
# From the project root
cmake -S . -B build
cmake --build build
./build/FitnessTrackerTests


## Some Sources Used to Complete This Project

+ https://www.geeksforgeeks.org/
+ https://cplusplus.com/doc/
+ https://en.cppreference.com/
+ https://www.learncpp.com/
+ https://www.instituteoflifestylemedicine.org/wp-content/uploads/2015/04/METValues.pdf  (MET PDF)
