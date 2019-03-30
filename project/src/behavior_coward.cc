#ifndef SRC_BEHAVIOR_COWARD_CC_
#define SRC_BEHAVIOR_COWARD_CC_


/*******************************************************************************
 * Includes
 ******************************************************************************/

 #include "src/behavior_coward.h"


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
BehaviorCoward::BehaviorCoward() {
  Behavior::type_ = kCoward;
  Behavior::velocity_ = new WheelVelocity(0,0);
}

WheelVelocity * BehaviorCoward::UpdateVelocity(double leftDist, double rightDist, double defaultSpeed){
  velocity_ = new WheelVelocity(leftDist, rightDist, defaultSpeed);
  return velocity_;
}

NAMESPACE_END(csci3081);

#endif  // SRC_BEHAVIOR_COWARD_CC_
