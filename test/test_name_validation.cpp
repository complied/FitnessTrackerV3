/*
#include <gtest/gtest.h>
#include "../include/calorieChecker.h"
#include "../include/workoutLogger.h"
#include "../include/workoutAssign.h"

using namespace calorieChecker;
using namespace logWorkout;



TEST(CalorieCheckerTests, ParseWorkout_ValidInputs) {
    EXPECT_EQ(parseWorkout("Running"), WorkoutType::Running);
    EXPECT_EQ(parseWorkout("Swimming"), WorkoutType::Swimming);
    EXPECT_EQ(parseWorkout("Biking"), WorkoutType::Biking);
}

TEST(CalorieCheckerTests, ParseWorkout_InvalidDefaultsToBiking) {
    EXPECT_EQ(parseWorkout("Walking"), WorkoutType::Biking);
    EXPECT_EQ(parseWorkout("Yoga"), WorkoutType::Biking);
    EXPECT_EQ(parseWorkout(""), WorkoutType::Biking);
}


TEST(WorkoutLoggerTests, IsValidDate_ValidDates) {
    EXPECT_TRUE(isValidDate("2024-05-02"));
    EXPECT_TRUE(isValidDate("2025-12-31"));
}

TEST(WorkoutLoggerTests, IsValidDate_InvalidFormat) {
    EXPECT_FALSE(isValidDate("2025/12/31"));
    EXPECT_FALSE(isValidDate("20251231"));
    EXPECT_FALSE(isValidDate("20-12-2025"));
    EXPECT_FALSE(isValidDate("abcd-ef-gh"));
}

TEST(WorkoutLoggerTests, IsValidDate_InvalidValues) {
    EXPECT_FALSE(isValidDate("2026-01-01")); // future year
    EXPECT_FALSE(isValidDate("2025-13-01")); // invalid month
    EXPECT_FALSE(isValidDate("2025-00-10")); // invalid month
    EXPECT_FALSE(isValidDate("2025-10-32")); // invalid day
    EXPECT_FALSE(isValidDate("2025-02-00")); // invalid day
}


double computeCalories(WorkoutType type, double weight, double duration) {
    if (type == WorkoutType::Running) return weight * 0.0175 * 9.8 * duration;
    if (type == WorkoutType::Swimming) return weight * 0.0175 * 7.0 * duration;
    return weight * 0.0175 * 8.0 * duration;
}

TEST(CalorieCheckerTests, CalorieCalculation_Correctness) {
    EXPECT_DOUBLE_EQ(computeCalories(WorkoutType::Running, 60, 30), 308.7);
    EXPECT_DOUBLE_EQ(computeCalories(WorkoutType::Swimming, 70, 45), 385.875);
    EXPECT_DOUBLE_EQ(computeCalories(WorkoutType::Biking, 55, 40), 308.0);
}


TEST(CalorieCheckerTests, CalorieSession_UsingSmartPointer) {
    auto session = std::make_unique<CalorieSession>();
    session->type = WorkoutType::Running;
    session->weight = 65;
    session->duration = 20;
    session->calories = computeCalories(session->type, session->weight, session->duration);

    EXPECT_GT(session->calories, 0.0);
    EXPECT_EQ(session->type, WorkoutType::Running);
}


TEST(WorkoutAssignTests, LimitPerDay) {
    std::string testDay = "Monday";
    for (int i = 0; i < 5; i++) {
        std::shared_ptr<workoutManager::workout> w = std::make_shared<workoutManager::workout>("Pushups", 20);
        workoutManager::workoutManager[testDay].push_back(w);
    }
    EXPECT_EQ(workoutManager::workoutManager[testDay].size(), 5);
}
*/ 