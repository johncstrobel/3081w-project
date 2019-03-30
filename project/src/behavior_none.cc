#ifndef SRC_BEHAVIOR_NONE_CC_
#define SRC_BEHAVIOR_NONE_CC_


/*******************************************************************************
 * Includes
 ******************************************************************************/

 #include "src/behavior_none.h"


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
BehaviorNone::BehaviorNone() {
  Behavior::type_ = kCoward;
  Behavior::velocity_ = new WheelVelocity(0,0);
}

WheelVelocity * BehaviorNone::UpdateVelocity(__unused double leftDist,
  __unused double rightDist, __unused double defaultSpeed){
  velocity_ = new WheelVelocity(0,0);
  return velocity_;
}

NAMESPACE_END(csci3081);

#endif  // SRC_BEHAVIOR_NONE_CC_
