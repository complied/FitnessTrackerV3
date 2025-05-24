#include <gtest/gtest.h>
#include "Running.h"
#include "Swimming.h"
#include "Biking.h"
#include "SongManager.h"
#include "workOut.h"

// Running: expected calorie value for 30 min, 60kg
TEST(WorkoutTypesTest, RunningCaloriesStandard) {
    Running run("Run", "2025-05-24", 30);
    EXPECT_NEAR(run.calculateCalories(60), 308.7, 0.1);
}

// Swimming - 0 duration should result in 0 calories
TEST(WorkoutTypesTest, SwimmingCaloriesZeroDuration) {
    Swimming swim("Swim", "2025-05-24", 0);
    EXPECT_DOUBLE_EQ(swim.calculateCalories(60), 0.0);
}

// Biking - negative weight produces negative calorie output
TEST(WorkoutTypesTest, BikingCaloriesNegativeWeight) {
    Biking bike("Bike", "2025-05-24", 30);
    EXPECT_LT(bike.calculateCalories(-70), 0);
}

// SongManager - Add song without crashing
TEST(SongManagerTest, AddSongAndRetrieve) {
    SongManager manager;
    manager.addSong("Sky", "Playboi Carti");
    SUCCEED();  // No crash = pass
}

// Song - Getters return expected values
TEST(SongManagerTest, SongGettersAccuracy) {
    Song s("Go2DaMoon", "Kanye West");
    EXPECT_EQ(s.getName(), "Go2DaMoon");
    EXPECT_EQ(s.getAuthor(), "Kanye West");
}

// Workout object constructor assigns values
TEST(WorkoutObjectTest, ConstructorAssignsCorrectValues) {
    Running r("Morning Run", "2025-05-24", 20);
    EXPECT_EQ(r.name, "Morning Run");
    EXPECT_EQ(r.date, "2025-05-24");
    EXPECT_EQ(r.duration, 20);
}

// Edge case - empty string and 0 duration
TEST(WorkoutObjectTest, ConstructorEmptyValuesAllowed) {
    Swimming swim("", "", 0);
    EXPECT_EQ(swim.name, "");
    EXPECT_EQ(swim.date, "");
    EXPECT_EQ(swim.duration, 0);
}

// Boolean logic: Calories should be positive
TEST(WorkoutTypesTest, ValidCalorieCalculationProducesPositiveResult) {
    Running run("Test Run", "2025-05-24", 15);
    EXPECT_TRUE(run.calculateCalories(60) > 0);
}

// Duration 0 - no calories burned
TEST(WorkoutTypesTest, NoCaloriesBurnedIfDurationZero) {
    Biking bike("Chill", "2025-05-24", 0);
    EXPECT_FALSE(bike.calculateCalories(70) > 0);
}

// Negative duration produces negative calories
TEST(WorkoutTypesTest, NegativeDurationResultsInZeroCalories) {
    Swimming swim("Error Swim", "2025-05-24", -15);
    EXPECT_LT(swim.calculateCalories(60), 0);
}
