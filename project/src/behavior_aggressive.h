/*
* Copyright 2019 John Strobel
*
* @file: behavior_aggressive.h
*/

#ifndef SRC_BEHAVIOR_AGGRESSIVE_H_
#define SRC_BEHAVIOR_AGGRESSIVE_H_


/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "src/wheel_velocity.h"
#include "src/behavior_enum.h"
#include "src/behavior.h"


/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NAMESPACE_BEGIN(csci3081);


/*******************************************************************************
 * Class Definitions
 ******************************************************************************/


 /**
  * @brief A behavior where sensors are directly related to wheels, and sensors
  * are connected to the opposite wheel. The result is a robot that moves
  * slowly while out of range of the target but speeds up and turns towards
  * them when close.
  *
  */
class BehaviorAggressive : public Behavior {
 public:
    BehaviorAggressive();

    void operator=(const BehaviorAggressive &b2) = delete;
    BehaviorAggressive(const BehaviorAggressive &b2) = delete;

    ~BehaviorAggressive() {delete velocity_;}

    /*
     * @brief Calculates wheel velocity based on passed in distances and
     * default speed. Overrides CalculateVelocity from behavior.h
     *
     */
    WheelVelocity * CalculateVelocity(double leftDist, double rightDist,
      double defaultSpeed) override;


 private:
  // BehaviorEnum type_;
  // WheelVelocity * velocity_;
};

NAMESPACE_END(csci3081);

#endif  // SRC_BEHAVIOR_AGGRESSIVE_H_
