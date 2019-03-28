#ifndef SRC_BEHAVIOR_H_
#define SRC_BEHAVIOR_H_


/*******************************************************************************
 * Includes
 ******************************************************************************/
 #include "src/wheel_velocity.h"
 #include "src/behavior_enum.h"


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
    Behavior(int behaviortype){behavior_type_ = behaviortype};
    Behavior();

    virtual ~Behavior();

    // in inherited classes, params:
    // double leftDist, double rightDist, double defaultSpeed
   virtual WheelVelocity * UpdateVelocity() = 0;

   virtual Behavior * ChooseFromIndex();
 private:
   int behavior_type_;
};

NAMESPACE_END(csci3081);

#endif  // SRC_BEHAVIOR_H_
