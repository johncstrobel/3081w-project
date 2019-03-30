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

/**
* @brief Factory constructor.
*
*/
  Factory::Factory() {}

/**
* @brief Method for constructing braitenberg vehicles.
*
* @param entity_config Json object containing details for how the vehicle
*  should be constructed.
*/
  BraitenbergVehicle* Factory::ConstructRobot(json_object * entity_config) {
     BraitenbergVehicle * Brandon = new BraitenbergVehicle();
     Brandon->LoadFromObject(entity_config);  // behaviors
     return Brandon;
  }

  /**
  * @brief Method for constructing Food entities.
  *
  * @param entity_config Json object containing details for how the food
  *  should be constructed.
  */
  Food * Factory::ConstructFood(json_object * entity_config) {
     Food * Fred = new Food();
     Fred->LoadFromObject(entity_config);
     return Fred;
  }

  /**
  * @brief Method for constructing Light entities.
  *
  * @param entity_config Json object containing details for how the light
  *  should be constructed.
  */
  Light * Factory::ConstructLight(json_object* entity_config) {
     Light * Amanda = new Light();
     Amanda->LoadFromObject(entity_config);
     return Amanda;
  }

NAMESPACE_END(csci3081);

#endif  // SRC_FACTORY_H_
