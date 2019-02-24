/**
 * @file robot_land.h
 *
 * @copyright 2017 3081 Staff, All rights reserved.
 */

#ifndef SRC_ROBOT_LAND_H_
#define SRC_ROBOT_LAND_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <cmath>
#include <iostream>
#include "robot.h"

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief The main class for the simulation of a 2D world with two robots.
 *
 * RobotViewer or Tests call \ref set_time and \ref advance_time to control the
 * simulation and use the get*() functions to read out the current state of the
 * simulation (i.e., the current positions and orientations of robots and
 * obstacles).
 *
 *  For now, RobotLand is hard coded to run a simulation of two robots running
 *  around in a circle. Their positions on the circle are determined by the
 *  simulation time, their speed, and initial position. You can see their
 *  sensors, but they don't yet respond to each other or to obstacles.
 */
class RobotLand {
 public:
  Robot * Robots_[30]; //max length 30
  int RobotsLength_ = 2; //num robots

  RobotLand(void) {
   Point ori = Point(512,350);//origin
   int spd;
   for(int i = 0; i < RobotsLength_; i++){
     if(i==0)
      spd = 1;
     else
      spd = 0.75;
    Robots_[i] = new Robot(i, 50.0, ori, spd);
   }
  }

  ~RobotLand(void){
   for(int i = 0; i < RobotsLength_; i++){
    delete(Robots_[i]);
   }
  }

  /**
   * @brief Set the simulation time for \ref RobotLand.
   *
   * This function will be used mainly for testing purposes, as time flows in a
   * steady forward direction in general simulation.
   *
   * @param[in] t The new simulation time.
   */
  void set_time(double t) {
    sim_time_ = t;
    std::cout << "Setting simulation time to " << sim_time_ << std::endl;
  }

  /**
   * @brief Advance the simulation by the specified # of steps.
   *
   * @param[in] dt The # of steps to increment by.
   */

  // Once the robot class is created, this should call a robot method to
  // advance its position and set the velocity based on dt
  void AdvanceTime(double dt) {
    sim_time_ += dt;
    std::cout << "Advancing simulation time to " << sim_time_ << std::endl;
    for(int i = 0; i < RobotsLength_; i++){
      Robots_[i]->Update(sim_time_);
    }
  }

  /**
   * @brief Get the current simulation time.
   */
  double get_current_time(void) { return sim_time_; }

  /*
   * @brief Get the current # of robots in the arena. Hardcoded for now.
   */
  int get_num_robots(void) { return 2; }

  /*
   * @brief return robot object with passed in ID.
   *
   * @param[in] id the ID of the desired robots.
   *
   * @return the robot object corresponding to the passed in ID.
   */
  Robot * get_robot(int id){
    if(id < RobotsLength_ && id > 0){
      return Robots_[id];
    }
  }

  /**
   * @brief Get the position of the obstacle.
   *
   * @param[out] x_pos The X component of the position.
   * @param[out] y_pos The Y component of the position.
   *
   */
  void get_obstacle_pos(double *x_pos, double *y_pos);

  /**
   * @brief Get the radius of the obstacle.
   *
   * @return The obstacle's radius.
   */
  double get_obstacle_radius() { return 75; }

 private:

  double sim_time_{0.0};
};

#endif  // SRC_ROBOT_LAND_H_
