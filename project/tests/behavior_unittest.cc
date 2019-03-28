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

NAMESPACE_BEGIN(csci3081)

 /******************************************************
* TEST FEATURE SetUp
*******************************************************/
class BehaviorTest : public ::testing::Test {
 protected:

  virtual void SetUp() {

  }

  virtual void TearDown() {

  }

};

/*******************************************************************************
 * Test Cases
 ******************************************************************************/

TEST_F(BehaviorTest, BehaviorAggressive){
  EXPECT_EQ(1,2) << "TODO";
}

TEST_F(BehaviorTest, BehaviorCoward){
  EXPECT_EQ(1,2) << "TODO";
}

TEST_F(BehaviorTest, BehaviorLove){
  EXPECT_EQ(1,2) << "TODO";
}

TEST_F(BehaviorTest, BehaviorExplore){
  EXPECT_EQ(1,2) << "TODO";
}

TEST_F(BehaviorTest, BehaviorNone){
  EXPECT_EQ(1,2) << "TODO";
}
// TEST_F(FactoryTest, Constructor) {
//   // I'm not sure how to test a class that has no
//   // members, so... this.
//   EXPECT_EQ(1, 2) << "factory constructor tests not yet setup";
// }

NAMESPACE_END(csci3081);

#endif  // TESTS_BEHAVIOR_UNITTEST_CC_
