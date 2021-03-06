/*
* Copyright 2019 John Strobel
*
* @file: behavior_explore.cc
*/

#ifndef SRC_BEHAVIOR_EXPLORE_CC_
#define SRC_BEHAVIOR_EXPLORE_CC_


/*******************************************************************************
 * Includes
 ******************************************************************************/

#include "src/behavior_explore.h"


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
BehaviorExplore::BehaviorExplore() {
  Behavior::type_ = kExplore;
  Behavior::velocity_ = new WheelVelocity(0, 0);
}

WheelVelocity * BehaviorExplore::CalculateVelocity(double leftDist,
  double rightDist, double defaultSpeed) {
  if (leftDist < MIN_DISTANCE) {
    leftDist = MIN_DISTANCE;
  }
  if (rightDist < MIN_DISTANCE) {
    rightDist = MIN_DISTANCE;
  }
  velocity_ = new WheelVelocity(1.0/rightDist, 1.0/leftDist, defaultSpeed);
  return velocity_;
}

NAMESPACE_END(csci3081);

#endif  // SRC_BEHAVIOR_EXPLORE_CC_
