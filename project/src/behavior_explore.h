#ifndef SRC_BEHAVIOR_EXPLORE_H_
#define SRC_BEHAVIOR_EXPLORE_H_


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
class BehaviorExplore : public Behavior {
 public:
    BehaviorExplore();

    void operator=(const BehaviorExplore &b2) = delete;
    BehaviorExplore(const BehaviorExplore &b2) = delete;

    ~BehaviorExplore(){delete velocity_;};

    WheelVelocity * CalculateVelocity(double leftDist, double rightDist, double defaultSpeed) override;


 private:
   // BehaviorEnum type_;
   // WheelVelocity * velocity_;
};

NAMESPACE_END(csci3081);

#endif  // SRC_BEHAVIOR_EXPLORE_H_
