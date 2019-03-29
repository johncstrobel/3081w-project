#ifndef SRC_BEHAVIOR_COWARD_CC_
#define SRC_BEHAVIOR_COWARD_CC_


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
BehaviorCoward::BehaviorCoward(){
  velocity_ = new WheelVelocity(0,0);
}

WheelVelocity * BehaviorCoward::UpdateVelocity(double leftDist, double rightDist, double defaultSpeed){
  return velocity_;
}

// class BehaviorCoward : public Behavior {
//  public:
//     BehaviorCoward();
//
//     ~BehaviorCoward(){delete velocity_;};
//
//    WheelVelocity * UpdateVelocity(double leftDist, double rightDist, double defaultSpeed);
//
//  private:
//    // BehaviorEnum type_;
//    WheelVelocity * velocity_;
// };

NAMESPACE_END(csci3081);

#endif  // SRC_BEHAVIOR_COWARD_CC_
