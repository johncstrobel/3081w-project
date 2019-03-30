#ifndef SRC_BEHAVIOR_LOVE_CC_
#define SRC_BEHAVIOR_LOVE_CC_


/*******************************************************************************
 * Includes
 ******************************************************************************/

 #include "src/behavior_love.h"


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
BehaviorLove::BehaviorLove() {
  Behavior::type_ = kLove;
  Behavior::velocity_ = new WheelVelocity(0,0);
}

WheelVelocity * BehaviorLove::CalculateVelocity(double leftDist, double rightDist, double defaultSpeed){
  velocity_ = new WheelVelocity(1.0/leftDist, 1.0/rightDist, defaultSpeed);
  return velocity_;
}

NAMESPACE_END(csci3081);

#endif  // SRC_BEHAVIOR_COWARD_CC_
