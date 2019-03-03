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

class Factory {
 public:
   Factory(){};

   BraitenbergVehicle* ConstructRobot(){};
   Food * ConstructFood(){};
   Light * ConstructLight(){};

 private:
};

NAMESPACE_END(csci3081);

#endif  // SRC_FACTORY_H_
