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
#include "src/light.h"


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

Predator::Predator(): BraitenbergVehicle(), kill_count_(0), disguise_(),
  disguise_factory_(), disguise_options_() {
  BraitenbergVehicle::set_light_behavior(kCoward);
  BraitenbergVehicle::set_food_behavior(kNone);
  BraitenbergVehicle::set_braitenberg_behavior(kAggressive);
  disguise_ = nullptr;
  disguise_factory_ = new Factory();
  disguise_options_.push_back(kBraitenberg);
  disguise_options_.push_back(kFood);
  disguise_options_.push_back(kLight);
}

  // number of behaviors
Predator::~Predator() {}

void Predator::HandleCollision(__unused EntityType ent_type,
  ArenaEntity * object) {
  if (object == nullptr) {
    if (disguise_) {
      if (disguise_->get_type() == kLight) {
        static_cast<Light*>(disguise_)->HandleCollision(ent_type, object);
      } else {BraitenbergVehicle::HandleCollision(ent_type, object);}
    } else {BraitenbergVehicle::HandleCollision(ent_type, object);}
  } else if (object->get_type() == kBraitenberg) {
    ConsumeFood(object);
  } else {
    if (disguise_) {
      if (disguise_->get_type() == kLight) {
        static_cast<Light*>(disguise_)->HandleCollision(ent_type, object);
      } else {BraitenbergVehicle::HandleCollision(ent_type, object);}
    } else {BraitenbergVehicle::HandleCollision(ent_type, object);}
  }
}

void Predator::ConsumeFood(ArenaEntity * victim) {
  static_cast<BraitenbergVehicle*>(victim)->Kill();
  kill_count_++;
  hunger_ = 600.0;
  disguise_options_.clear();
  disguise_options_.push_back(kBraitenberg);
  disguise_options_.push_back(kFood);
  disguise_options_.push_back(kLight);
}

void Predator::LoadFromObject(json_object* entity_config) {
  ArenaEntity::LoadFromObject(entity_config);
  UpdateLightSensors();
}

void Predator::Update() {
  // int x = (rand() % (disguise_options_.size()));
  // std::cout << "random x: " << x << std::endl;
  if (disguise_) {
    if (disguise_->get_type() != kLight) {
      disguise_->Update();
    }
      // else do nothing
  } else {
    BraitenbergVehicle::Update();
  }
}

void Predator::DisguiseSelf() {
  int x = (rand_r() % (disguise_options_.size()));

  int newDisguise = disguise_options_[x];
  switch (newDisguise) {
    case kLight:
      disguise_ = disguise_factory_->ConstructLight();
      set_color(LIGHT_COLOR);
      break;
    case kFood:
      disguise_ = disguise_factory_->ConstructFood();
      set_color(FOOD_COLOR);
      break;
    case kBraitenberg:
      disguise_ = disguise_factory_->ConstructRobot();
      static_cast<BraitenbergVehicle*>(disguise_)->RandomizeBehaviors();
      static_cast<BraitenbergVehicle*>(disguise_)->
        set_braitenberg_behavior(kAggressive);
      set_color(BRAITENBERG_MAROON);
      break;
    default:
      break;
  }

  if (disguise_) {
    for (int i = 0; i < static_cast<int>(disguise_options_.size()); i++) {
      if (disguise_->get_type() == disguise_options_[i]) {
        disguise_options_.erase(disguise_options_.begin()+i);
      }
    }
  }
}

void Predator::TimestepUpdate(unsigned int dt) {
  if (hunger_ < HUNGER1 && disguise_options_.size() == 3) {
    DisguiseSelf();
  } else if (hunger_ < HUNGER2 && disguise_options_.size() == 2) {
    DisguiseSelf();
  } else if (hunger_ < HUNGER3 && disguise_options_.size() == 1) {
    DisguiseSelf();
  }

  if (disguise_ && disguise_->get_type() == kLight) {
    static_cast<Light*>(disguise_)->TimestepUpdate(dt);
    hunger_ = hunger_ - dt;
  }
  if (disguise_ && disguise_->get_type() == kBraitenberg) {
    BraitenbergVehicle::TimestepUpdate(dt);
  }
  if (disguise_ && disguise_->get_type() == kFood) {
    static_cast<Food*>(disguise_)->TimestepUpdate(dt);
    hunger_ = hunger_ - dt;
  }
  if (!disguise_) {
    BraitenbergVehicle::TimestepUpdate(dt);
  }
}

NAMESPACE_END(csci3081);

#endif  // SRC_BRAITENBERG_PREDATOR_CC_
