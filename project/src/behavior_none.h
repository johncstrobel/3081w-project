#ifndef SRC_BEHAVIOR_NONE_H_
#define SRC_BEHAVIOR_NONE_H_


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
class BehaviorNone : public Behavior {
 public:
    BehaviorNone();

    void operator=(const BehaviorNone &b2) = delete;
    BehaviorNone(const BehaviorNone &b2) = delete;

    ~BehaviorNone(){delete velocity_;};

   WheelVelocity * CalculateVelocity(double leftDist, double rightDist, double defaultSpeed) override;

   WheelVelocity * CalculateVelocity(double leftDist, double rightDist);

 private:
   // BehaviorEnum type_;
   // WheelVelocity * velocity_;
};

NAMESPACE_END(csci3081);

#endif  // SRC_BEHAVIOR_NONE_H_
