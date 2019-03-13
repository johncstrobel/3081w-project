/*
 * @file factory.h
 *
 * @copyright John Strobel 2019
*/

#ifndef SRC_FACTORY_H_
#define SRC_FACTORY_H_

#include "src/braitenberg_vehicle.h"
#include "src/food.h"
#include "src/light.h"
#include "src/common.h"

NAMESPACE_BEGIN(csci3081);

/**
 * @brief Constructor class for creating arena objects.
 *
 */
class Factory {
 public:
   Factory(){};

   BraitenbergVehicle* ConstructRobot(json_object& entity_config);
   Food * ConstructFood(json_object& entity_config);
   Light * ConstructLight(json_object& entity_config);

 private:
};

NAMESPACE_END(csci3081);

#endif  // SRC_FACTORY_H_
