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
   * @brief Deleting the copy assignment and copy constructor. required now with
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

  /**
   * @brief Sets the behavior of the vehicle to the passed in Behavior object
   * pointer. The behavior that is set is indicated by the parameter 'type.'
   *
   * @param behavior the behavior to be settings
   *
   * @param type the type of behavior that will be assigned
   */
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

  /**
   * @brief Returns light behavior, as a Behavior object pointer.
   */
  Behavior * get_light_behavior() { return light_behavior_; }

  /**
   * @brief Returns light behavior, as a BehaviorEnum.
   */
  BehaviorEnum  get_light_behavior_enum() { return light_behavior_enum_; }

  /**
   * @brief Sets the light behavior based on the passed in BehaviorEnum. Calls
   * set_behavior and creates a new behavior appropriate to the passed in enum.
   *
   * @param behavior a BehaviorEnum that represents the behavior to set.
   */
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

  /**
   * @brief Returns food behavior, as a Behavior object pointer.
   */
  Behavior * get_food_behavior() { return food_behavior_; }


  /**
   * @brief Returns food behavior, as a BehaviorEnum.
   */
  BehaviorEnum  get_food_behavior_enum() { return food_behavior_enum_; }

  /**
   * @brief Sets the food behavior based on the passed in BehaviorEnum. Calls
   * set_behavior and creates a new behavior appropriate to the passed in enum.
   *
   * @param behavior a BehaviorEnum that represents the behavior to set.
   */
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


  /**
   * @brief Returns food behavior, as a Behavior object pointer.
   */
  Behavior * get_braitenberg_behavior() { return braitenberg_behavior_; }

  /**
   * @brief Returns food behavior, as a BehaviorEnum.
   */
  BehaviorEnum get_braitenberg_behavior_enum()
    {return braitenberg_behavior_enum_;}

  /**
   * @brief Sets the BraitenbergVehicle behavior based on the passed in
   * BehaviorEnum. Calls set_behavior and creates a new behavior appropriate
   * to the passed in enum.
   *
   * @param behavior a BehaviorEnum that represents the behavior to set.
   */
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

  /**
   * @brief calculates distance from the left sensor to the passed in
   * ArenaEntity.
   *
   * @param entity the entity to be sensed.
   */
  double get_sensor_reading_left(const ArenaEntity* entity);

  /**
   * @brief calculates distance from the right sensor to the passed in
   * ArenaEntity.
   *
   * @param entity the entity to be sensed.
   */
  double get_sensor_reading_right(const ArenaEntity* entity);

  /**
   * @brief Changes the BV's color depending on its state: distance from
   * food, lights, and predators, and its hunger.
   *
   */
  void DynamicColor();

  /**
   * @brief calculates the velocity of each wheel depending on the state of the
   * BV and sets wheel_velocity_ accordingly. Also acts differently depending
   * on hunger level.
   *
   */
  void CalculateWheelVelocity();

  /**
   * @brief makes the BV a 'ghost' (no collisions, color is white, stops moving)
   *
   */
  void kill();
  bool IsDead() {return dead;}
  virtual void ConsumeFood(__unused ArenaEntity * object);

  static int count;

  /**
   * @brief Adds an observer to the list of observers.
   *
   */
  void RegisterObserver(Observer * other);

  /**
   * @brief Removes an observer from the list of observers.
   *
   */
  void RemoveObserver(Observer * other);

  /**
   * @brief Iterates through list of observers, calling observer->update() on
   * each one.
   *
   */
  void NotifyObservers(WheelVelocity * lightvel, WheelVelocity * foodvel,
      WheelVelocity * bvvel);

 private:
  std::vector<Pose> light_sensors_;
  MotionBehaviorDifferential * motion_behavior_{nullptr};

  WheelVelocity wheel_velocity_;  // overall wheel velocity
  WheelVelocity * light_wheel_velocity_;  // passed to observer
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

 protected:
  double colliding_;  // tracks time until robot is done backing up
  bool dead;  // marks if the robot is alive
  double hunger_;  // time until death by starvation

  std::vector<Observer*> observers_;
};

NAMESPACE_END(csci3081);

#endif  // SRC_BRAITENBERG_VEHICLE_H_
