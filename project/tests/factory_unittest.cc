/*
 *
 */

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <gtest/gtest.h>
#include "src/arena.h"
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

TEST_F(FactoryTest, Constructor){}

TEST_F(FactoryTest, ConstructRobot){
  // test each robot type
  // test no robot type (default robot constuct)
}

TEST_F(FactoryTest, ConstructFood){
  // test inside boundaries
  // test outside boundaries
}

TEST_F(FactoryTest, ConstructLight){
}



TEST_F(ArenaTest, Constructor) {
  EXPECT_EQ(arena->get_x_dim(), X_DIM);
  EXPECT_EQ(arena->get_y_dim(), Y_DIM);
  EXPECT_GE((int)arena->get_entities().size(), 3) << "FAIL: Arena:Constructor - There should be at least 3 entities";
};
