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
#include "src/factory.h"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NAMESPACE_BEGIN(csci3081);

class Factory;

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief A Braitenberg vehicle subclass that can consume other braitenbergs
 *
 * @detail See description of BraitenbergVehicle class for more details on basic
 *  behavior. This class operates identically, except that when it collides with
 *  a braitenberg vehicle, it 'kills' it instead of performing the normal
 *  backing up and changing direction. It can also 'disguise' itself as other
 *  standard arena entities in order to attract BraitenbergVehicles to it.
 */

class Predator : public BraitenbergVehicle {
 public:
  Predator();

  ~Predator();

  Predator(const Predator & rhs) = delete;

  Predator operator=(const Predator & rhs) = delete;

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

  void Update() override;

  void DisguiseSelf();

  void TimestepUpdate(unsigned int dt) override;

  EntityType get_type() const override {
    if(disguise_){
      return disguise_->get_type();
    }
    return kBraitenberg;
  }

  // EntityType get_type() const { return type_; }

 private:
    // for fun :)
    int kill_count_;

    ArenaEntity * disguise_;
    Factory * disguise_factory_;
    std::vector<EntityType> disguise_options_;
};

NAMESPACE_END(csci3081);

#endif  // SRC_BRAITENBERG_PREDATOR_H_
