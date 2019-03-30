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
#include "src/params.h"

NAMESPACE_BEGIN(csci3081)

 /******************************************************
* TEST FEATURE SetUp
*******************************************************/
class BehaviorTest : public ::testing::Test {
 protected:

  virtual void SetUp() {DS = 5;}
  virtual void TearDown() {}

  Behavior * behavior;
  WheelVelocity * velocity;
  WheelVelocity * velocity_neg;
  WheelVelocity * velocity_zero;
  WheelVelocity * velocity_large;

  double DS;  // defaultSpeed

};

/*******************************************************************************
 * Test Cases
 ******************************************************************************/

TEST_F(BehaviorTest, BehaviorCoward){
  behavior = new BehaviorCoward();
  velocity = new WheelVelocity(5,5,DS);
  velocity_neg = new WheelVelocity(MIN_DISTANCE,MIN_DISTANCE,DS);
  velocity_zero = new WheelVelocity(MIN_DISTANCE,3,DS);
  velocity_large = new WheelVelocity(3,500,DS);

  EXPECT_EQ(behavior->get_type(),kCoward)
    << "coward behavior type incorrect";
  EXPECT_EQ(*(behavior->CalculateVelocity(5,5,DS)), *velocity)
    << "coward behavior calculation incorrect (default)";
  EXPECT_EQ(*(behavior->CalculateVelocity(-5,-5, DS)), *velocity_neg)
    << "coward behavior calculation incorrect (negatives)";
  EXPECT_EQ(*(behavior->CalculateVelocity(0,3, DS)), *velocity_zero)
    << "constructed behavior calculation incorrect (zero)";
  EXPECT_EQ(*(behavior->CalculateVelocity(3,500,DS)), *velocity_large)
    << "coward behavior calculation incorrect (large numbers)";

  delete behavior;
}

TEST_F(BehaviorTest, BehaviorAggressive){
  behavior = new BehaviorAggressive();
  velocity = new WheelVelocity(5,8,DS);
  velocity_neg = new WheelVelocity(2,MIN_DISTANCE,DS);
  velocity_zero = new WheelVelocity(MIN_DISTANCE,3,DS);
  velocity_large = new WheelVelocity(3,500,DS);

  EXPECT_EQ(behavior->get_type(),kAggressive)
    << "aggressive behavior type incorrect";
  EXPECT_EQ(*(behavior->CalculateVelocity(8,5,DS)), *velocity)
    << "aggressive behavior calculation incorrect (default)";
  EXPECT_EQ(*(behavior->CalculateVelocity(-5,2, DS)), *velocity_neg)
    << "aggressive behavior calculation incorrect (negatives)";
  EXPECT_EQ(*(behavior->CalculateVelocity(3,0, DS)), *velocity_zero)
    << "aggressive behavior calculation incorrect (zero)";
  EXPECT_EQ(*(behavior->CalculateVelocity(500,3,DS)), *velocity_large)
    << "aggressive behavior calculation incorrect (large numbers)";

  delete behavior;
}

TEST_F(BehaviorTest, BehaviorLove){
  behavior = new BehaviorLove();
  velocity = new WheelVelocity(0.2,0.125,DS);
  velocity_neg = new WheelVelocity((1.0/MIN_DISTANCE),(1.0/MIN_DISTANCE),DS);
  velocity_zero = new WheelVelocity((1.0/MIN_DISTANCE),(1.0/3),DS);
  velocity_large = new WheelVelocity((1.0/3),0.002,DS);

  EXPECT_EQ(behavior->get_type(),kLove)
    << "love behavior type incorrect";
  EXPECT_EQ(*(behavior->CalculateVelocity(5,8,DS)), *velocity)
    << "love behavior calculation incorrect (default)";
  EXPECT_EQ(*(behavior->CalculateVelocity(-2,-5, DS)), *velocity_neg)
    << "love behavior calculation incorrect (negatives)";
  EXPECT_EQ(*(behavior->CalculateVelocity(0,3, DS)), *velocity_zero)
    << "love behavior calculation incorrect (zero)";
  EXPECT_EQ(*(behavior->CalculateVelocity(3,500,DS)), *velocity_large)
    << "love behavior calculation incorrect (large numbers)";

  delete behavior;
}

TEST_F(BehaviorTest, BehaviorExplore){
  behavior = new BehaviorExplore();
  velocity = new WheelVelocity(0.125,0.2,DS);
  velocity_neg = new WheelVelocity((1.0/MIN_DISTANCE),0.5,DS);
  velocity_zero = new WheelVelocity((1.0/3),(1.0/MIN_DISTANCE),DS);
  velocity_large = new WheelVelocity(0.002,(1.0/3),DS);

  EXPECT_EQ(behavior->get_type(),kExplore)
    << "constructed behavior type incorrect";
  EXPECT_EQ(*(behavior->CalculateVelocity(5,8,DS)), *velocity)
    << "love behavior calculation incorrect (default)";
  EXPECT_EQ(*(behavior->CalculateVelocity(2,-5, DS)), *velocity_neg)
    << "love behavior calculation incorrect (negatives)";
  EXPECT_EQ(*(behavior->CalculateVelocity(0,3, DS)), *velocity_zero)
    << "love behavior calculation incorrect (zero)";
  EXPECT_EQ(*(behavior->CalculateVelocity(3,500,DS)), *velocity_large)
    << "love behavior calculation incorrect (large numbers)";

  delete behavior;
}

TEST_F(BehaviorTest, BehaviorNone){
  behavior = new BehaviorNone();
  velocity = new WheelVelocity(0,0);

  EXPECT_EQ(behavior->get_type(),kNone)
    << "constructed behavior type incorrect";
  EXPECT_EQ(*(behavior->CalculateVelocity(-5,-5, DS)), *velocity)
    << "constructed behavior calculation incorrect";
  EXPECT_EQ(*(behavior->CalculateVelocity(300,2.876,DS)), *velocity)
    << "constructed behavior calculation incorrect";
  delete behavior;
}


NAMESPACE_END(csci3081);

#endif  // TESTS_BEHAVIOR_UNITTEST_CC_
