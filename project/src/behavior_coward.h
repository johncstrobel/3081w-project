#ifndef SRC_BEHAVIOR_COWARD_H_
#define SRC_BEHAVIOR_COWARD_H_


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
class BehaviorCoward : public Behavior {
 public:
    BehaviorCoward();

    void operator=(const BehaviorCoward &b2) = delete;
    BehaviorCoward(const BehaviorCoward &b2) = delete;

    ~BehaviorCoward(){delete velocity_;};

    WheelVelocity * CalculateVelocity(double leftDist, double rightDist, double defaultSpeed) override;


 private:
   // BehaviorEnum type_;
   // WheelVelocity * velocity_;
};

NAMESPACE_END(csci3081);

#endif  // SRC_BEHAVIOR_COWARD_H_
