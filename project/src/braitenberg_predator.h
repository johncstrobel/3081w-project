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

  /**
   * @brief Override of HandleCollision that kills braitenbergs if they are
   * the colliding object.
   *
   * @param ent_type type of the passed in ArenaEntity.
   *
   * @param object ArenaEntity this is colliding with.
   */
  void HandleCollision(EntityType ent_type, ArenaEntity * object) override;

  /**
   * @brief Override of LoadFromObject that ignores behavior parameters,
   * instead automatically setting all behaviors to predator default.
   */
  void LoadFromObject(json_object* entity_config) override;

  /**
   * @brief Method for determining if ArenaEntity is a predator.
   */
  bool IsPredator() override {return true;}

  /**
   * @brief Overridden from BraitenbergVehicle to consume BVs instead of normal
   * food objects.
   */
  void ConsumeFood(ArenaEntity * victim) override;

 private:
    // for fun :)
    int kill_count_;
};

NAMESPACE_END(csci3081);

#endif  // SRC_BRAITENBERG_PREDATOR_H_
