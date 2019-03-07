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

TEST_F(BraitenbergTest, HandleCollision) {
  EXPECT_EQ(1,2) << "TODO";
// void HandleCollision(EntityType ent_type,
                     // ArenaEntity * object = NULL) override;
}

TEST_F(BraitenbergTest, LoadFromObject) {
  EXPECT_EQ(1,2) << "TODO";
// void LoadFromObject(json_object& entity_config) override;
}

#endif  // TESTS_BRAITENBERG_UNITTEST_CC
