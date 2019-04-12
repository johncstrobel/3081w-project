/*
* Copyright 2019 John Strobel
*
* @file: behavior_coward.h
*/

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
  * @brief A behavior where sensors are directly related to wheels, and sensors
  * are connected to the opposite wheel. The result is a robot that moves
  * slowly while out of range of the target but speeds up and turns away from
  * them when close.
  *
  */
class BehaviorCoward : public Behavior {
 public:
    BehaviorCoward();

    void operator=(const BehaviorCoward &b2) = delete;
    BehaviorCoward(const BehaviorCoward &b2) = delete;

    ~BehaviorCoward() {delete velocity_;}

    /*
     * @brief Calculates wheel velocity based on passed in distances and
     * default speed. Overrides CalculateVelocity from behavior.h
     *
     */
    WheelVelocity * CalculateVelocity(double leftDist, double rightDist,
      double defaultSpeed) override;


 private:
  // BehaviorEnum type_;
  // WheelVelocity * velocity_;
};

NAMESPACE_END(csci3081);

#endif  // SRC_BEHAVIOR_COWARD_H_
