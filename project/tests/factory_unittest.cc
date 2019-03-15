/*
 * Copyright 2019 John Strobel
 */

#ifndef TESTS_FACTORY_UNITTEST_CC
#define TESTS_FACTORY_UNITTEST_CC

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <gtest/gtest.h>
#include <fstream>
#include <streambuf>
#include <string>

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
    json_value * json_robot_raw = new json_value();
    json_value * json_light_raw = new json_value();
    json_value *  json_food_raw  = new json_value();

    std::string file_r = "scenes/myJsonRobot.json";
    std::string file_l = "scenes/myJsonLight.json";
    std::string file_f = "scenes/myJsonFood.json";

    std::ifstream t(std::string(file_r).c_str());
    std::string json_r((std::istreambuf_iterator<char>(t)),
                   std::istreambuf_iterator<char>());
    std::ifstream u(std::string(file_l).c_str());
    std::string json_l((std::istreambuf_iterator<char>(u)),
                   std::istreambuf_iterator<char>());
    std::ifstream v(std::string(file_f).c_str());
    std::string json_f((std::istreambuf_iterator<char>(v)),
                   std::istreambuf_iterator<char>());

    std::string err_r = parse_json(json_robot_raw, json_r);
    std::string err_l = parse_json(json_light_raw, json_l);
    std::string err_f = parse_json(json_food_raw,  json_f);

    if (!err_r.empty()) {
      std::cerr << "Parse error: " << err_r << std::endl;
      delete json_robot_raw;
      json_robot_raw = NULL;
    }
    if (!err_f.empty()) {
      std::cerr << "Parse error: " << err_f << std::endl;
      delete json_food_raw;
      json_food_raw = NULL;
    }
    if (!err_l.empty()) {
      std::cerr << "Parse error: " << err_l << std::endl;
      delete json_light_raw;
      json_light_raw = NULL;
    }

    json_robot = &(json_robot_raw->get<json_object>());
    json_light = &(json_light_raw->get<json_object>());
    json_food = &(json_food_raw->get<json_object>());

    factory = new Factory();
  }

  virtual void TearDown() {
    delete factory;
  }

  json_object* json_robot;
  json_object* json_light;
  json_object* json_food;

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

TEST_F(FactoryTest, ConstructRobotJson) {
  // {"type": "Braitenberg", "x":270, "y":270, "r":15, "theta": 215,
  //  "light_behavior": "None", "food_behavior": "Explore" }
  BraitenbergVehicle* robot = factory->ConstructRobot(json_robot);
  RgbColor color = BRAITENBERG_MAROON;
  Pose pose = {270,270};

  EXPECT_EQ(robot->get_type(), kBraitenberg) << "constructed robot type incorrect";
  EXPECT_EQ(robot->get_color(), color) << "constructed robot color incorrect";
  EXPECT_EQ(robot->get_radius(), 15) << "constructed robot radius incorrect";
  EXPECT_EQ(robot->get_pose(), pose) << "constructed robot initial position incorrect";

  delete robot;
}

TEST_F(FactoryTest, ConstructFoodJson) {
  // tests and values initialized below are based on "myJsonFood.json"
  Food* food = factory->ConstructFood(json_food);
  RgbColor color = FOOD_COLOR;
  Pose pose = {200,200};

  EXPECT_EQ(food->get_color(), color) << "food constructor doesn't match default food color";
  EXPECT_EQ(food->get_pose(), pose) << "food constructor doesn't match default food position";
  EXPECT_EQ(food->get_radius(), 20) << "food constructor doesn't match default food radius";
  EXPECT_EQ(food->get_type(), kFood) << "food constructor doesn't match food type";

  delete food;
}

TEST_F(FactoryTest, ConstructLightJson) {
  // tests and values initialized below are based on "myJsonLight.json"
  Light* light = factory->ConstructLight(json_light);
  Pose pose = {150,300};
  RgbColor color = LIGHT_COLOR;

  EXPECT_EQ(light->get_pose(), pose) << "light constructor doesn't match default light position";
  EXPECT_EQ(light->get_color(), color) << "light constructor doesn't match default light color";
  EXPECT_EQ(light->get_radius(), 25) << "light constructor doesn't match default light radius";
  EXPECT_EQ(light->get_type(), kLight) << "light constructor doesn't match light type";
  EXPECT_EQ(light->get_speed(), 3) << "light constructor doesn't match default light speed";

  delete light;
}

#endif  // TESTS_FACTORY_UNITTEST_CC
