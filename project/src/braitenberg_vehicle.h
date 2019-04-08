/**
 * @file braitenberg_vehicle.h
 *
 * @copyright 2017 3081 Staff, All rights reserved.
 */

#ifndef SRC_BRAITENBERG_VEHICLE_H_
#define SRC_BRAITENBERG_VEHICLE_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/

#include <ctime>
#include <string>
#include <vector>
#include "src/common.h"
#include "src/arena_mobile_entity.h"
#include "src/motion_behavior_differential.h"
#include "src/wheel_velocity.h"
#include "src/behavior_enum.h"
#include "src/behavior.h"
#include "src/behavior_coward.h"
#include "src/behavior_aggressive.h"
#include "src/behavior_love.h"
#include "src/behavior_none.h"
#include "src/behavior_explore.h"
#include "src/params.h"
#include "src/braitenberg_observer.h"
#include "src/observer.h"


/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NAMESPACE_BEGIN(csci3081);

class BraitenbergObserver;
/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief Entity class to represent a Braitenberg Vehicle
 *
 * @detail A braitenberg vehicle is a simple machine that is used to show how simple
 * concepts (in this case wiring) can give way to complex looking behavior. In
 * this simulation, Braitenberg vehicles contain sensors, which can be hooked
 * up in four different ways, and thus they can exhibit four different behaviors
 */

class BraitenbergVehicle : public ArenaMobileEntity {
 public:
  /**
   * @brief Default constructor.
   */
  BraitenbergVehicle();

  /**
   * Deleting the copy assignment and copy constructor. required now with
   *  inclusion of references to sensors and motion_handler/behavior
   */
  BraitenbergVehicle(const BraitenbergVehicle & rhs) = delete;

  BraitenbergVehicle operator=(const BraitenbergVehicle & rhs) = delete;

  /**
   * @brief Update the BraitenbergVehicle's position and velocity after the
   * specified duration has passed.
   *
   * @param dt The # of timesteps that have elapsed since the last update.
   */
  void TimestepUpdate(unsigned int dt) override;

  void Update() override;

  /**
   * @brief Change the movement state of the BraitenbergVehicle.
   */
  void HandleCollision(EntityType ent_type,
    ArenaEntity * object = NULL) override;

  /**
  * @brief Compares in param with current closest entity.
  *
  * @param entity The entity to be compared to the current closest.
  */
  void SenseEntity(const ArenaEntity& entity);

  std::string get_name() const override;

  std::vector<Pose> get_light_sensors_const() const;

  std::vector<Pose> get_light_sensors();

  /**
  * @brief Changes effective range of the light sensors.
  *
  * @detail Updates the vector for each of the light sensors based on the
  *  current position of the vehicle.
  */
  void UpdateLightSensors();

  /**
  * @brief Updates settings based on JSON file.
  *
  * @param entity_config JSON object that determines parameters for the object.
  */
  void LoadFromObject(json_object* entity_config) override;

  void set_behavior(Behavior * behavior, std::string type) {
    if (type.compare("food") == 0) {
      food_behavior_ = behavior;
    } else if (type.compare("light") == 0) {
      light_behavior_ = behavior;
    } else if (type.compare("braitenberg") == 0) {
      braitenberg_behavior_ = behavior;
    } else {
      std::cout << "ya done goofed" << std::endl;
    }
  }

  Behavior * get_light_behavior() { return light_behavior_; }
  BehaviorEnum  get_light_behavior_enum() { return light_behavior_enum_; }
  void set_light_behavior(BehaviorEnum behavior) {
  light_behavior_enum_ = behavior;
  switch (behavior) {
    case 1:
      set_behavior (new BehaviorAggressive(), "light");
      break;
    case 2:
      set_behavior(new BehaviorCoward(), "light");
      break;
    case 3:
      set_behavior(new BehaviorExplore(), "light");
      break;
    case 4:
      set_behavior(new BehaviorLove(), "light");
      break;
    case 0:
    default:
      set_behavior(new BehaviorNone(), "light");
  }
}

  Behavior * get_food_behavior() { return food_behavior_; }
  BehaviorEnum  get_food_behavior_enum() { return food_behavior_enum_; }
  void set_food_behavior(BehaviorEnum behavior) {
  food_behavior_enum_ = behavior;
  switch (behavior) {
    case 1:
      set_behavior(new BehaviorAggressive(), "food");
      break;
    case 2:
      set_behavior(new BehaviorCoward(), "food");
      break;
    case 3:
      set_behavior(new BehaviorExplore(), "food");
      break;
    case 4:
      set_behavior(new BehaviorLove(), "food");
      break;
    case 0:
    default:
      set_behavior(new BehaviorNone(), "food");
  }
}

  Behavior * get_braitenberg_behavior() { return braitenberg_behavior_; }
  BehaviorEnum get_braitenberg_behavior_enum()
    {return braitenberg_behavior_enum_;}
  void set_braitenberg_behavior(BehaviorEnum behavior) {
  braitenberg_behavior_enum_ = behavior;
  switch (behavior) {
    case 1:
      set_behavior(new BehaviorAggressive(), "braitenberg");
      break;
    case 2:
      set_behavior(new BehaviorCoward(), "braitenberg");
      break;
    case 3:
      set_behavior(new BehaviorExplore(), "braitenberg");
      break;
    case 4:
      set_behavior(new BehaviorLove(), "braitenberg");
      break;
    case 0:
    default:
      set_behavior(new BehaviorNone(), "braitenberg");
  }
}

  double get_sensor_reading_left(const ArenaEntity* entity);
  double get_sensor_reading_right(const ArenaEntity* entity);

  void DynamicColor();

  void CalculateWheelVelocity();

  void kill();

  bool IsDead() {return dead;}

  static int count;

  void RegisterObserver(Observer * other);
  void RemoveObserver(Observer * other);
  void NotifyObservers(WheelVelocity * lightvel, WheelVelocity * foodvel,
      WheelVelocity * bvvel);

 private:
  std::vector<Pose> light_sensors_;
  MotionBehaviorDifferential * motion_behavior_{nullptr};
  WheelVelocity wheel_velocity_;
  WheelVelocity * light_wheel_velocity_;
  WheelVelocity * food_wheel_velocity_;
  WheelVelocity * bv_wheel_velocity_;
  BehaviorEnum light_behavior_enum_;
  BehaviorEnum food_behavior_enum_;
  BehaviorEnum braitenberg_behavior_enum_;
  Behavior * light_behavior_;
  Behavior * food_behavior_;
  Behavior * braitenberg_behavior_;
  const ArenaEntity* closest_light_entity_;
  const ArenaEntity* closest_food_entity_;
  const ArenaEntity* closest_braitenberg_entity_;
  double defaultSpeed_;
  double colliding_;  // tracks time until robot is done backing up
  bool dead;  // marks if the robot is alive
  std::vector<Observer*> observers_;

};

NAMESPACE_END(csci3081);

#endif  // SRC_BRAITENBERG_VEHICLE_H_
