/*
* Copyright 2019 John Strobel
*
* @file: behavior.h
*/

#ifndef SRC_BEHAVIOR_H_
#define SRC_BEHAVIOR_H_


/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "src/wheel_velocity.h"
#include "src/behavior_enum.h"
#include "src/params.h"


/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NAMESPACE_BEGIN(csci3081);


/*******************************************************************************
 * Class Definitions
 ******************************************************************************/


/**
 * @brief An abstract class that defines characteristics of Braitenberg motion
 * behaviors.
 *
 */
class Behavior {
 public:
  Behavior() : type_(kNone), velocity_(NULL) {}

  virtual ~Behavior() {}

  Behavior(const Behavior &other) = delete;

  int operator=(const Behavior &other) = delete;
    // in inherited classes, params:
    // double leftDist, double rightDist, double defaultSpeed

  /*
   * @brief Calculates wheel velocity based on passed in distances and
   * default speed.
   *
   */
  virtual WheelVelocity * CalculateVelocity(double leftDist, double rightDist,
    double defaultSpeed) = 0;

  BehaviorEnum get_type() {return type_;}

 protected:
  BehaviorEnum type_;
  WheelVelocity * velocity_;
};

NAMESPACE_END(csci3081);

#endif  // SRC_BEHAVIOR_H_
