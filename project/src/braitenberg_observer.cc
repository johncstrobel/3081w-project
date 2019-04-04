/**
 * @file observer.h
 *
 * @copyright 2019 John Strobel
 */

#ifndef SRC_BRAITENBERG_OBSERVER_CC_
#define SRC_BRAITENBERG_OBSERVER_CC_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <vector>
#include "src/braitenberg_observer.h"
#include "src/observer.h"
#include "src/wheel_velocity.h"


/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NAMESPACE_BEGIN(csci3081);

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief Observer abstract class for observing entities in the arena
 *
 */


BraitenbergObserver::BraitenbergObserver(): velocities_(), num_velocities_(6){
  for(int i = 0; i < num_velocities_; i++)
   velocities_.push_back(0.0); //guarantee there are always 6 velocities
}

void BraitenbergObserver::update(WheelVelocity * lightvel, WheelVelocity * foodvel,
  WheelVelocity * bvvel){
    velocities_.erase(velocities_.begin(),velocities_.end());
    velocities_.push_back(lightvel->right);
    velocities_.push_back(lightvel->left);
    velocities_.push_back(foodvel->right);
    velocities_.push_back(foodvel->left);
    velocities_.push_back(bvvel->right);
    velocities_.push_back(bvvel->left);
}

std::vector<double> * BraitenbergObserver::getVelocities(){
  return &velocities_;
}

NAMESPACE_END(csci3081);

#endif  // SRC_BRAITENBERG_OBSERVER_CC_
