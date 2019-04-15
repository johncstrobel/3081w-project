/*
* Copyright 2019 John Strobel
*
* @file: behavior_love.h
*/

#ifndef SRC_BEHAVIOR_LOVE_H_
#define SRC_BEHAVIOR_LOVE_H_


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
  * @brief A behavior where sensors are inversely related to wheels, and sensors
  * are connected to the same wheel. The result is a robot that moves
  * quickly while out of range of the target but slows and turns towards them
  * when close.
  *
  */
class BehaviorLove : public Behavior {
 public:
    BehaviorLove();

    void operator=(const BehaviorLove &b2) = delete;
    BehaviorLove(const BehaviorLove &b2) = delete;

    ~BehaviorLove() {delete velocity_;}

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

#endif  // SRC_BEHAVIOR_LOVE_H_
