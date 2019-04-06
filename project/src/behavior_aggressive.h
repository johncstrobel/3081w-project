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
 * @brief update me
 * @TODO
 *
 */
class BehaviorAggressive : public Behavior {
 public:
    BehaviorAggressive();

    void operator=(const BehaviorAggressive &b2) = delete;
    BehaviorAggressive(const BehaviorAggressive &b2) = delete;

    ~BehaviorAggressive() {delete velocity_;}

    WheelVelocity * CalculateVelocity(double leftDist, double rightDist,
      double defaultSpeed) override;


 private:
  // BehaviorEnum type_;
  // WheelVelocity * velocity_;
};

NAMESPACE_END(csci3081);

#endif  // SRC_BEHAVIOR_AGGRESSIVE_H_
