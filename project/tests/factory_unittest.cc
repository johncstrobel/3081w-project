/*
 * Copyright 2019 John Strobel
 */

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <gtest/gtest.h>
#include "src/factory.h"
#include "src/entity_type.h"
#include "src/params.h"
// @TODO: include "src/factory.h"

 /******************************************************
* TEST FEATURE SetUp
*******************************************************/
class FactoryTest : public ::testing::Test {
 protected:
  virtual void SetUp() {
    factory = new csci3081::Factory();
  }
  virtual void TearDown() {
    delete factory;
  }

  csci3081::Factory * factory;
};

/*******************************************************************************
 * Test Cases
 ******************************************************************************/

TEST_F(FactoryTest, Constructor) {
  // I'm not sure how to test a class that has no
  // members, so... this.
  EXPECT_EQ(1, 2) << "factory constructor tests not yet setup"
}

TEST_F(FactoryTest, ConstructRobot) {
  BraitenbergVehicle robot = factory.ConstructRobot();

  EXPECT_EQ(robot.get_type(), kBraitenberg)
    << "constructed robot type incorrect";
  EXPECT_EQ(robot.get_color(), BRAITENBERG_COLOR)
    << "constructed robot color incorrect";
  EXPECT_EQ(robot.get_speed(), 5.0)  // default speed
    << "constructed robot speed incorrect";
  EXPECT_EQ(robot.get_radius(), DEFAULT_RADIUS)
    << "constructed robot radius incorrect";
  EXPECT_EQ(robot.get_pose(), ROBOT_INIT_POS)
    << "constructed robot initial position incorrect";

  delete robot;
}

TEST_F(FactoryTest, ConstructFoodDefault) {
  Food food = factory.ConstructFood();

  EXPECT_EQ(food.get_color(), FOOD_COLOR)
    << "food constructor doesn't match default food color";
  EXPECT_EQ(food.get_pose(), FOOD_INIT_POS)
    << "food constructor doesn't match default food position";
  EXPECT_EQ(food.get_radius(), FOOD_RADIUS)
    << "food constructor doesn't match default food radius";
  EXPECT_EQ(food.get_type(), kFood)
    << "food constructor doesn't match food type";

  delete food;
}

TEST_F(FactoryTest, ConstructLightDefault) {
  Light light = factory.ConstructLight();

  EXPECT_EQ(light.get_pose(), LIGHT_POSITION)
    << "light constructor doesn't match default light position";
  EXPECT_EQ(light.get_color(), LIGHT_COLOR)
    << "light constructor doesn't match default light color";
  EXPECT_EQ(light.get_radius(), LIGHT_RADIUS)
    << "light constructor doesn't match default light radius";
  EXPECT_EQ(light.get_type(), kLight)
    << "light constructor doesn't match light type";
  EXPECT_EQ(light.get_speed(), 3)
    << "light constructor doesn't match default light speed";

  delete light;
}
