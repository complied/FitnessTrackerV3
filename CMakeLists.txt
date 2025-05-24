cmake_minimum_required(VERSION 3.20)
project(FitnessTrackerV3)

set(CMAKE_CXX_STANDARD 20)


# Main Executable

add_executable(FitnessTrackerV3
        main.cpp
        src/DisplayMenu.cpp
        src/calorieChecker.cpp
        src/songManager.cpp
        src/workoutAssign.cpp
        src/workoutLogger.cpp
        src/workoutReccomendation.cpp
        src/Running.cpp
        src/Biking.cpp
        src/Swimming.cpp
)

target_include_directories(FitnessTrackerV3 PRIVATE
        include
)


# GoogleTest

add_subdirectory(extern/googletest)


# Test Executable

add_executable(FitnessTrackerTests
        test/test_name_validation.cpp
        src/calorieChecker.cpp
        src/workoutLogger.cpp
        src/workoutAssign.cpp
        src/songManager.cpp
        src/Running.cpp
        src/Biking.cpp
        src/Swimming.cpp
)

target_include_directories(FitnessTrackerTests PRIVATE
        include
        extern/googletest/googletest/include
)

target_link_libraries(FitnessTrackerTests
        gtest
        gtest_main
        pthread
)

enable_testing()
include(GoogleTest)
gtest_discover_tests(FitnessTrackerTests)
