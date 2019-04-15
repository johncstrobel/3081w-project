/*
 * @file factory.h
 *
 * @copyright John Strobel 2019
*/

#ifndef SRC_FACTORY_H_
#define SRC_FACTORY_H_

#include "src/braitenberg_vehicle.h"
#include "src/food.h"
#include "src/light.h"
#include "src/common.h"
#include "src/braitenberg_predator.h"

NAMESPACE_BEGIN(csci3081);

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief Class for constructing entities in the arena.
 *
 * @detail Contains a different method for each type of entity in the
 *  simulation. Each method takes in a json object and returns a pointer
 *  to the object of the appropriate type.
 */
class Factory {
 public:
  Factory();

  /**
   * @brief Constructs BraitenbergVehicle objects.
   * @param entity_config the JSON object from which the robot will be loaded.
   * @return a pointer to a BraitenbergVehicle object.
   */
  BraitenbergVehicle* ConstructRobot(json_object* entity_config);

  /**
   * @brief Constructs Food objects.
   * @param entity_config the JSON object from which the food will be loaded.
   * @return a pointer to a food object.
   */
  Food * ConstructFood(json_object* entity_config);

  /**
   * @brief Constructs light objects.
   * @param entity_config the JSON object from which the light will be loaded.
   * @return a pointer to a light object.
   */
  Light * ConstructLight(json_object* entity_config);

  /**
   * @brief Constructs Predator objects.
   * @param entity_config the JSON object from which the robot will be loaded.
   * @return a pointer to a Predator object.
   */
  BraitenbergVehicle* ConstructPredator(json_object* entity_config);
};

NAMESPACE_END(csci3081);

#endif  // SRC_FACTORY_H_
