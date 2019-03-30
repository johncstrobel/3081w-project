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

TEST_F(BraitenbergTest, UpdateTest){
  //no longer necessary
  //test update function, specifically for the new behaviors
}

#endif  // TESTS_BRAITENBERG_UNITTEST_CC
