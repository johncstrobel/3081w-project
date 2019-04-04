/**
 * @file observer.h
 *
 * @copyright 2019 John Strobel
 */

#ifndef SRC_OBSERVER_H_
#define SRC_OBSERVER_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "src/wheel_velocity.h"
#include "src/arena_entity.h"


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

class Observer {
 public:
   virtual void update(WheelVelocity * lightvel, WheelVelocity * foodvel,
     WheelVelocity * bvvel) = 0;  // called by entity to pass info to observer

   virtual ~Observer(){};
   int operator=(const Observer &other) = delete;
   Observer(const Observer &other) = delete;

   Observer(): subject_(NULL){};

 private:
   ArenaEntity * subject_;
};

NAMESPACE_END(csci3081);

#endif  // SRC_OBSERVER_H_
