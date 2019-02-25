/**
 * @brief An entity in RobotLand that moves around the window.
 *
 * Its id, size, initial position, and velocity are fixed.
 * The position and direction are updated at each frame refresh.
 * The color can be changed via a user button in the RobotViewer.
 *
 * @file robot.cc
 */

#include "src/robot.h"

Robot::Robot(int id, double radius, Point origin, double speed)
	: id_(id), radius_(radius), origin_(origin), speed_(speed) {
	color_ = false;
	position_ = Point(712,350); //hard coded for now: see circle_x and y
	direction_ = 0.0;
	sensor_angle_ = 2.0;
	sensor_range_ = 150.0;
}

void Robot::Update(double time){
  //record old position
	double prev_pos_x = position_.x_;
	double prev_pos_y = position_.y_;

	//update position
	position_.x_ = circle_x(speed_ * time);
	position_.y_ = circle_y(speed_ * time);

	//update direction
	double x_vel = position_.x_ - prev_pos_x;
	double y_vel = position_.y_ - prev_pos_y;
	direction_ = std::atan2(y_vel,x_vel);
}

bool Robot::get_color(){
	return color_;
}

void Robot::set_color(bool color){
	color_ = color;
}

int Robot::get_id(){
	return id_;
}

double Robot::get_radius(){
	return radius_;
}

Point Robot::get_position(){
	return position_;
}

double Robot::get_x_position(){
	return position_.x_;
}

double Robot::get_y_position(){
	return position_.y_;
}

double Robot::get_direction(){
	return direction_;
}

double Robot::get_sensor_angle(){
	return sensor_angle_;
}

double Robot::get_sensor_range(){
	return sensor_range_;
}
