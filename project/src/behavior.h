#ifndef SRC_BEHAVIOR_H_
#define SRC_BEHAVIOR_H_


/*******************************************************************************
 * Includes
 ******************************************************************************/
 #include "src/wheel_velocity.h"


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
class Behavior {
 public:
    virtual WheelVelocity * UpdateVelocity() = 0;
   // in inherited classes, params:
   // double leftDist, double rightDist, double defaultSpeed
 private:
   std::string behavior_type_;
};

NAMESPACE_END(csci3081);

#endif  // SRC_BEHAVIOR_H_
