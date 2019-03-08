/*
 * Copyright 2019 John Strobel
 */

#ifndef TESTS_FACTORY_UNITTEST_CC
#define TESTS_FACTORY_UNITTEST_CC

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
class FactoryTest : public ::testing::Test {
 protected:
  virtual void SetUp() {
    factory = new Factory();
  }
  virtual void TearDown() {
    delete factory;
  }

  Factory * factory;
};

/*******************************************************************************
 * Test Cases
 ******************************************************************************/

// TEST_F(FactoryTest, Constructor) {
//   // I'm not sure how to test a class that has no
//   // members, so... this.
//   EXPECT_EQ(1, 2) << "factory constructor tests not yet setup";
// }

TEST_F(FactoryTest, ConstructRobot) {
  BraitenbergVehicle* robot = new BraitenbergVehicle();  // factory->ConstructRobot("src/default.json");
  RgbColor color = DEFAULT_COLOR;
  Pose pose = ROBOT_INIT_POS;

  EXPECT_EQ(robot->get_type(), kBraitenberg) << "constructed robot type incorrect";
  EXPECT_EQ(robot->get_color(), color) << "constructed robot color incorrect";
  EXPECT_EQ(robot->get_speed(), 5.0) << "constructed robot speed incorrect";  // default speed
  EXPECT_EQ(robot->get_radius(), 20) << "constructed robot radius incorrect";
  EXPECT_EQ(robot->get_pose(), pose) << "constructed robot initial position incorrect";

  delete robot;
}

TEST_F(FactoryTest, ConstructFoodDefault) {
  Food* food = new Food();  // factory->ConstructFood();
  RgbColor color = FOOD_COLOR;
  Pose pose = FOOD_INIT_POS;

  EXPECT_EQ(food->get_color(), color) << "food constructor doesn't match default food color";
  EXPECT_EQ(food->get_pose(), pose) << "food constructor doesn't match default food position";
  EXPECT_EQ(food->get_radius(), 0) << "food constructor doesn't match default food radius";
  EXPECT_EQ(food->get_type(), kFood) << "food constructor doesn't match food type";

  delete food;
}

TEST_F(FactoryTest, ConstructLightDefault) {
  Light* light = new Light();  // factory->ConstructLight();
  Pose pose = LIGHT_POSITION;
  RgbColor color = LIGHT_COLOR;

  EXPECT_EQ(light->get_pose(), pose) << "light constructor doesn't match default light position";
  EXPECT_EQ(light->get_color(), color) << "light constructor doesn't match default light color";
  EXPECT_EQ(light->get_radius(), 30) << "light constructor doesn't match default light radius";
  EXPECT_EQ(light->get_type(), kLight) << "light constructor doesn't match light type";
  EXPECT_EQ(light->get_speed(), 3) << "light constructor doesn't match default light speed";

  delete light;
}

#endif  // TESTS_FACTORY_UNITTEST_CC
