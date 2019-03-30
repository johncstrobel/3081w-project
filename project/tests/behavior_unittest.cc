/*
 * Copyright 2019 John Strobel
 */

#ifndef TESTS_BEHAVIOR_UNITTEST_CC_
#define TESTS_BEHAVIOR_UNITTEST_CC_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <gtest/gtest.h>
#include <fstream>
#include <streambuf>
#include <string>

#include "src/behavior.h"
#include "src/behavior_coward.h"
#include "src/behavior_love.h"
#include "src/behavior_aggressive.h"
#include "src/behavior_explore.h"
#include "src/behavior_none.h"

NAMESPACE_BEGIN(csci3081)

 /******************************************************
* TEST FEATURE SetUp
*******************************************************/
class BehaviorTest : public ::testing::Test {
 protected:

  virtual void SetUp() {}
  virtual void TearDown() {}
  Behavior * behavior;
  WheelVelocity * velocity;

};

/*******************************************************************************
 * Test Cases
 ******************************************************************************/

TEST_F(BehaviorTest, BehaviorAggressive){
  behavior = new BehaviorAggressive();
  EXPECT_EQ(behavior->get_type(),kAggressive) << "constructed behavior type incorrect";
EXPECT_EQ(1,2) << "TODO";

  delete behavior;
}

TEST_F(BehaviorTest, BehaviorCoward){
  behavior = new BehaviorCoward();
  EXPECT_EQ(behavior->get_type(),kCoward) << "constructed behavior type incorrect";
  EXPECT_EQ(1,2) << "TODO";

  delete behavior;
}

TEST_F(BehaviorTest, BehaviorLove){
  behavior = new BehaviorLove();
  EXPECT_EQ(behavior->get_type(),kLove) << "constructed behavior type incorrect";
  EXPECT_EQ(1,2) << "TODO";

  delete behavior;
}

TEST_F(BehaviorTest, BehaviorExplore){
  behavior = new BehaviorExplore();
  EXPECT_EQ(behavior->get_type(),kExplore) << "constructed behavior type incorrect";
  EXPECT_EQ(1,2) << "TODO";

  delete behavior;
}

TEST_F(BehaviorTest, BehaviorNone){
  behavior = new BehaviorNone();
  velocity = new WheelVelocity(0,0);

  EXPECT_EQ(behavior->get_type(),kNone)
    << "constructed behavior type incorrect";
  EXPECT_EQ(behavior->CalculateVelocity(-5,-5,-5), velocity)
    << "constructed behavior calculation incorrect";
  EXPECT_EQ(1,2) << "TODO";

  delete behavior;
}

NAMESPACE_END(csci3081);

#endif  // TESTS_BEHAVIOR_UNITTEST_CC_
