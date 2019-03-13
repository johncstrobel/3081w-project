/*
 * @file factory.cc
 *
 * @copyright John Strobel 2019
*/

#ifndef SRC_FACTORY_CC_
#define SRC_FACTORY_CC_

#include <string>

#include "src/factory.h"

NAMESPACE_BEGIN(csci3081);

// parse json file, pass sub-json units into these functions (instead
// of the whole thing at once)

  Factory::Factory() {}


  BraitenbergVehicle* Factory::ConstructRobot(json_object& entity_config) {
     BraitenbergVehicle * Brandon = new BraitenbergVehicle();
     Brandon->LoadFromObject(entity_config);  // behaviors

     double xpos = stod(entity_config["x"].get<std::string>());
     double ypos = stod(entity_config["y"].get<std::string>());
     // radius: "r"
     // theta: "theta"

     Brandon->set_pose(Pose(xpos, ypos));
     return Brandon;
  }

  Food * Factory::ConstructFood(json_object& entity_config) {
     Food * Fred = new Food();
     double xpos = stod(entity_config["x"].get<std::string>());
     double ypos = stod(entity_config["y"].get<std::string>());

     Fred->set_pose(Pose(xpos, ypos));
     return Fred;
  }

  Light * Factory::ConstructLight(json_object& entity_config) {
     Light * Gavin = new Light();
     double xpos = stod(entity_config["x"].get<std::string>());
     double ypos = stod(entity_config["y"].get<std::string>());

     Gavin->set_pose(Pose(xpos, ypos));
     return Gavin;
  }

NAMESPACE_END(csci3081);

#endif  // SRC_FACTORY_H_
