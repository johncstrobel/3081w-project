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
 * @brief update me
 * @TODO
 *
 */
class BehaviorLove : public Behavior {
 public:
    BehaviorLove();

    void operator=(const BehaviorLove &b2) = delete;
    BehaviorLove(const BehaviorLove &b2) = delete;

    ~BehaviorLove() {delete velocity_;}

    WheelVelocity * CalculateVelocity(double leftDist, double rightDist,
      double defaultSpeed) override;


 private:
  // BehaviorEnum type_;
  // WheelVelocity * velocity_;
};

NAMESPACE_END(csci3081);

#endif  // SRC_BEHAVIOR_LOVE_H_
