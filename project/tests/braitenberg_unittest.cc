/*
 * Copyright 2019 John Strobel
 */

#ifndef TESTS_BRAITENBERG_UNITTEST_CC
#define TESTS_BRAITENBERG_UNITTEST_CC

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <gtest/gtest.h>
#include "src/factory.h"
#include "src/entity_type.h"
#include "src/params.h"
#include "src/braitenberg_vehicle.h"
#include "src/food.h"

using namespace csci3081;

 /******************************************************
* TEST FEATURE SetUp
*******************************************************/
class BraitenbergTest : public ::testing::Test {
 protected:
  virtual void SetUp() {
    Ken = new BraitenbergVehicle();
  }
  virtual void TearDown() {
    if(Ken) delete Ken;
  }

  BraitenbergVehicle * Ken;
};

/*******************************************************************************
 * Test Cases
 ******************************************************************************/

TEST_F(BraitenbergTest, Constructor) {
  EXPECT_EQ(Ken->get_light_behavior(),kNone)
    << "Constructor: Light Behavior incorrect";
  EXPECT_EQ(Ken->get_food_behavior(),kNone)
    << "Constructor: Food Behavior incorrect";
}

TEST_F(BraitenbergTest, TimeStepUpdate) {
  Pose current = Ken->get_pose();
  //behavior needs to be something other than kNone for this test to be meaningful
  Ken->set_light_behavior(kExplore);

  Ken->TimestepUpdate(1);
  EXPECT_NE(Ken->get_pose(),current) << "TimestepUpdate(1)";  // NOT EQUAL!!!
  Ken->TimestepUpdate(0);
  EXPECT_EQ(Ken->get_pose(),current) << "TimestepUpdate(0)";
  Ken->TimestepUpdate(-1);
  EXPECT_EQ(Ken->get_pose(),current) << "TimestepUpdate(-1)";
}

TEST_F(BraitenbergTest, Update) {
  EXPECT_EQ(1,2) << "TODO";
// void Update() override;
}

TEST_F(BraitenbergTest, HandleCollision) {
  EXPECT_EQ(1,2) << "TODO";
// void HandleCollision(EntityType ent_type,
                     // ArenaEntity * object = NULL) override;
}

TEST_F(BraitenbergTest, SenseEntity) {
  EXPECT_EQ(1,2) << "TODO";
// void SenseEntity(const ArenaEntity& entity);
}

TEST_F(BraitenbergTest, GetLightSensorsConst) {
  EXPECT_EQ(1,2) << "TODO";
// std::vector<Pose> get_light_sensors_const() const;
}

TEST_F(BraitenbergTest, LightSensors) {
  EXPECT_EQ(1,2) << "TODO";
// std::vector<Pose> get_light_sensors();

// void UpdateLightSensors();

}

TEST_F(BraitenbergTest, LoadFromObject) {
  EXPECT_EQ(1,2) << "TODO";
// void LoadFromObject(json_object& entity_config) override;
}

TEST_F(BraitenbergTest, LightBehavior) {
  EXPECT_EQ(1,2) << "TODO";
// Behavior get_light_behavior() { return light_behavior_; }
// void set_light_behavior(Behavior behavior) { light_behavior_ = behavior; }
}

TEST_F(BraitenbergTest, FoodBehavior) {
  EXPECT_EQ(1,2) << "TODO";
// Behavior get_food_behavior() { return food_behavior_; }
// void set_food_behavior(Behavior behavior) { food_behavior_ = behavior; }
}

TEST_F(BraitenbergTest, SensorReadings) {
  EXPECT_EQ(1,2) << "TODO";
// double get_sensor_reading_left(const ArenaEntity* entity);
// double get_sensor_reading_right(const ArenaEntity* entity);
}

#endif  // TESTS_BRAITENBERG_UNITTEST_CC
