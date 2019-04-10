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

Predator::Predator(): BraitenbergVehicle(), killcount_(0) {
  BraitenbergVehicle::set_light_behavior(kCoward);
  BraitenbergVehicle::set_food_behavior(kNone);
  BraitenbergVehicle::set_braitenberg_behavior(kAggressive);
  // set_type(kPredator);
}


Predator::~Predator() {}

void Predator::HandleCollision(__unused EntityType ent_type,
  ArenaEntity * object) {
  if (object == nullptr) {
    BraitenbergVehicle::HandleCollision(ent_type, object);
  } else if (object->get_type() == kBraitenberg) {
    ConsumeFood(object);
  } else {
    BraitenbergVehicle::HandleCollision(ent_type, object);
  }
}

void Predator::ConsumeFood(ArenaEntity * victim) {
  static_cast<BraitenbergVehicle*>(victim)->kill();
  killcount_++;
  hunger_ = 600.0;
}

void Predator::LoadFromObject(json_object* entity_config) {
  ArenaEntity::LoadFromObject(entity_config);
  UpdateLightSensors();
}
   /* things it needs to do differently:
    * behaviors (ez)
    * when colliding with a BV, kill it
    *  -overload handlecollision
    *  -remove BV from collidable objects
    */

NAMESPACE_END(csci3081);

#endif  // SRC_BRAITENBERG_PREDATOR_CC_
