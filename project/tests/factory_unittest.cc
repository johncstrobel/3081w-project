/*
 *
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

TEST_F(FactoryTest, Constructor){}

TEST_F(FactoryTest, ConstructRobot){
  // test each robot type
  // test no robot type (default robot constuct)
}

TEST_F(FactoryTest, ConstructFoodDefault){
  Food food = factory.ConstructFood();

  EXPECT_EQ(food.get_color(), FOOD_COLOR) << "food constructor doesn't match default food color";
  EXPECT_EQ(food.get_pose(), FOOD_INIT_POS)  << "food constructor doesn't match default food position";
  EXPECT_EQ(food.get_radius(), FOOD_RADIUS)  << "food constructor doesn't match default food radius";
  EXPECT_EQ(food.get_type(), kFood)  << "food constructor doesn't match food type";
}

TEST_F(FactoryTest, ConstructLightDefault){
  Light light = factory.ConstructLight();

  EXPECT_EQ(light.get_pose(), LIGHT_POSITION) << "light constructor doesn't match default light position";
  EXPECT_EQ(light.get_color(), LIGHT_COLOR) << "light constructor doesn't match default light color";
  EXPECT_EQ(light.get_radius(), LIGHT_RADIUS) << "light constructor doesn't match default light radius";
  EXPECT_EQ(light.get_type(), kLight) << "light constructor doesn't match light type";
  EXPECT_EQ(light.get_speed(), 3) << "light constructor doesn't match default light speed";
}



TEST_F(ArenaTest, Constructor) {
  EXPECT_EQ(arena->get_x_dim(), X_DIM);
  EXPECT_EQ(arena->get_y_dim(), Y_DIM);
  EXPECT_GE((int)arena->get_entities().size(), 3) << "FAIL: Arena:Constructor - There should be at least 3 entities";
};
