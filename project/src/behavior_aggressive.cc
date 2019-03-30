#ifndef SRC_BEHAVIOR_AGGRESSIVE_CC_
#define SRC_BEHAVIOR_AGGRESSIVE_CC_


/*******************************************************************************
 * Includes
 ******************************************************************************/

 #include "src/behavior_aggressive.h"


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
BehaviorAggressive::BehaviorAggressive() {
  Behavior::type_ = kAggressive;
  Behavior::velocity_ = new WheelVelocity(0,0);
}

WheelVelocity * BehaviorAggressive::CalculateVelocity(double leftDist, double rightDist, double defaultSpeed){
  if(leftDist<MIN_DISTANCE){
    leftDist = MIN_DISTANCE;
  }
  if(rightDist<MIN_DISTANCE){
    rightDist = MIN_DISTANCE;
  }
  velocity_ = new WheelVelocity(rightDist, leftDist, defaultSpeed);
  return velocity_;
}

NAMESPACE_END(csci3081);

#endif  // SRC_BEHAVIOR_AGGRESSIVE_CC_
