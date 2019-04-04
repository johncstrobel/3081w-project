/**
 * @file braitenberg_vehicle.h
 *
 * @copyright 2017 3081 Staff, All rights reserved.
 */

#ifndef SRC_BRAITENBERG_PREDATOR_CC_
#define SRC_BRAITENBERG_PREDATOR_CC_

/*******************************************************************************
 * Includes
 ******************************************************************************/

#include <ctime>
#include <string>
#include <vector>
#include "src/braitenberg_predator.h"


/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NAMESPACE_BEGIN(csci3081);

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief Braitenberg vehicle subclass that can consume other braitenbergs
 *
 * @detail
 */

Predator::Predator(): BraitenbergVehicle(), killcount_(0){
  BraitenbergVehicle::set_light_behavior(kCoward);
  BraitenbergVehicle::set_food_behavior(kNone);
  BraitenbergVehicle::set_braitenberg_behavior(kAggressive);
}


Predator::~Predator(){}

void Predator::HandleCollision(__unused EntityType ent_type,
  ArenaEntity * object){
  if(object->get_type() == kBraitenberg){
    static_cast<BraitenbergVehicle*>(object)->kill();
  } else {
    BraitenbergVehicle::HandleCollision(ent_type, object);
  }
}
   /* things it needs to do differently:
    * behaviors (ez)
    * when colliding with a BV, kill it
    *  -overload handlecollision
    *
    */

NAMESPACE_END(csci3081);

#endif  // SRC_BRAITENBERG_PREDATOR_CC_
