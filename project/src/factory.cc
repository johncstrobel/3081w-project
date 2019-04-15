/*
 * @file factory.cc
 *
 * @copyright John Strobel 2019
 *
*/

#ifndef SRC_FACTORY_CC_
#define SRC_FACTORY_CC_

#include <string>

#include "src/factory.h"

NAMESPACE_BEGIN(csci3081);

  Factory::Factory() {}


  BraitenbergVehicle* Factory::ConstructRobot(json_object * entity_config) {
     BraitenbergVehicle * Brandon = new BraitenbergVehicle();
     Brandon->LoadFromObject(entity_config);  // behaviors
     return Brandon;
  }

  Food * Factory::ConstructFood(json_object * entity_config) {
     Food * Fred = new Food();
     Fred->LoadFromObject(entity_config);
     return Fred;
  }


  Light * Factory::ConstructLight(json_object* entity_config) {
     Light * Amanda = new Light();
     Amanda->LoadFromObject(entity_config);
     return Amanda;
  }

  BraitenbergVehicle* Factory::ConstructPredator(json_object* entity_config) {
    Predator * Teresa = new Predator();
    Teresa->LoadFromObject(entity_config);
    return Teresa;
  }

NAMESPACE_END(csci3081);

#endif  // SRC_FACTORY_H_
