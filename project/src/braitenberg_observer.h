/**
 * @file observer.h
 *
 * @copyright 2019 John Strobel
 */

#ifndef SRC_BRAITENBERG_OBSERVER_H_
#define SRC_BRAITENBERG_OBSERVER_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <vector>
#include "src/observer.h"


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

class BraitenbergObserver : public Observer {
 public:
   void update(WheelVelocity * lightvel, WheelVelocity * foodvel,
     WheelVelocity * bvvel) override;
   BraitenbergObserver();

   std::vector<double> * getVelocities();

 private:
   std::vector<double> velocities_;
   int num_velocities_;
};


NAMESPACE_END(csci3081);

#endif  // SRC_BRAITENBERG_OBSERVER_H_
