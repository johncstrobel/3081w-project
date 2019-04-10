/**
 * @file braitenberg_predator.h
 *
 * @copyright 2017 3081 Staff, All rights reserved.
 */

#ifndef SRC_BRAITENBERG_PREDATOR_H_
#define SRC_BRAITENBERG_PREDATOR_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/

#include <ctime>
#include <string>
#include <vector>
#include "src/braitenberg_vehicle.h"


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
 * @detail See description of BraitenbergVehicle class for more details on basic
 *  behavior. This class operates identically, except that when it collides with
 *  a braitenberg vehicle, it 'kills' it instead of performing the normal
 *  backing up and changing direction.
 */

class Predator : public BraitenbergVehicle {
 public:
  Predator();

  ~Predator();

  void HandleCollision(EntityType ent_type, ArenaEntity * object) override;

  void LoadFromObject(json_object* entity_config) override;

  bool IsPredator() override {return true;}

  void ConsumeFood(ArenaEntity * victim) override;
  /* things it needs to do differently:
   * behaviors (ez)
   * when colliding with a BV, kill it
   *  -overload handlecollision
   *
   */
 private:
    int killcount_;
};

NAMESPACE_END(csci3081);

#endif  // SRC_BRAITENBERG_PREDATOR_H_
