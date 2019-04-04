/**
 * @file braitenberg_vehicle.cc
 *
 * @copyright 2017 3081 Staff, All rights reserved.
 */
/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <iostream>
#include <ctime>
#include "src/braitenberg_vehicle.h"
// #include "src/params.h"

class SensorLightLove;

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NAMESPACE_BEGIN(csci3081);

int BraitenbergVehicle::count = 0;

/*******************************************************************************
 * Constructors/Destructor
 ******************************************************************************/

BraitenbergVehicle::BraitenbergVehicle() :
  light_sensors_(), wheel_velocity_(), light_wheel_velocity_(),
  food_wheel_velocity_(), bv_wheel_velocity_(),
  light_behavior_enum_(kNone), food_behavior_enum_(kNone),
  braitenberg_behavior_enum_(kNone),
  light_behavior_(NULL), food_behavior_(NULL),
  braitenberg_behavior_(NULL), closest_light_entity_(NULL),
  closest_food_entity_(NULL), closest_braitenberg_entity_(NULL),
  defaultSpeed_(5.0), colliding_(0.0), observers_() {
  food_behavior_ = new BehaviorNone();
  light_behavior_ = new BehaviorNone();
  braitenberg_behavior_ = new BehaviorNone();
  set_type(kBraitenberg);
  motion_behavior_ = new MotionBehaviorDifferential(this);
  light_sensors_.push_back(Pose());
  light_sensors_.push_back(Pose());
  set_color(BRAITENBERG_COLOR);
  set_pose(ROBOT_INIT_POS);

  wheel_velocity_ = WheelVelocity(0, 0);

  // Set ID
  count++;
  set_id(count);
}

void BraitenbergVehicle::TimestepUpdate(__unused unsigned int dt) {
  if (is_moving()) {
    motion_behavior_->UpdatePose(dt, wheel_velocity_);
  } else {  // is moving() returns something else
    motion_behavior_->UpdatePose(dt, WheelVelocity(-2, -2));
    colliding_ = colliding_ - dt;
    if (colliding_ <= 0) {
      set_is_moving(true);
      set_heading(static_cast<int>((get_pose().theta + 45)) % 360);
    }
  }
  UpdateLightSensors();
}

void BraitenbergVehicle::HandleCollision(__unused EntityType ent_type,
                                         __unused ArenaEntity * object) {
  set_is_moving(false);
  colliding_ = 20;
}

void BraitenbergVehicle::SenseEntity(const ArenaEntity& entity) {
  const ArenaEntity** closest_entity_ = NULL;
  if (entity.get_type() == kLight) {
    closest_entity_ = &closest_light_entity_;
  } else if (entity.get_type() == kFood) {
    closest_entity_ = &closest_food_entity_;
  } else if (entity.get_type() == kBraitenberg) {
    closest_entity_ = &closest_braitenberg_entity_;
  }

  if (!closest_entity_) {
    return;
  }

  if (!*closest_entity_) {
    *closest_entity_ = &entity;
  }

  double distance = (this->get_pose()-entity.get_pose()).Length();
  double closest_distance =
  (this->get_pose()-(*closest_entity_)->get_pose()).Length();
  if (distance < closest_distance) {
    *closest_entity_ = &entity;
    closest_distance = distance;
  }
  if (closest_distance > 100.0) {
    *closest_entity_ = NULL;
  }
}

void BraitenbergVehicle::Update() {
  CalculateWheelVelocity();
  DynamicColor();
}

std::string BraitenbergVehicle::get_name() const {
  return "Braitenberg " + std::to_string(get_id());
}

std::vector<Pose> BraitenbergVehicle::get_light_sensors_const() const {
  return light_sensors_;
}

std::vector<Pose> BraitenbergVehicle::get_light_sensors() {
  return light_sensors_;
}

double BraitenbergVehicle::get_sensor_reading_left(const ArenaEntity* entity) {
  if (entity) {
    return 1800.0/std::pow(
      1.08, (entity->get_pose()-light_sensors_[0]).Length());
  }

  return 0.0001;
}

double BraitenbergVehicle::get_sensor_reading_right(const ArenaEntity* entity) {
  if (entity) {
    return 1800.0/std::pow(
      1.08, (entity->get_pose()-light_sensors_[1]).Length());
  }

  return 0.0001;
}

void BraitenbergVehicle::UpdateLightSensors() {
  for (unsigned int f = 0; f < light_sensors_.size(); f++) {
    Pose& pos = light_sensors_[f];
    if (f == 0) {
      pos.x = get_pose().x + get_radius() * cos(deg2rad(get_pose().theta - 40));
      pos.y = get_pose().y + get_radius() * sin(deg2rad(get_pose().theta - 40));
    } else {
      pos.x = get_pose().x + get_radius() * cos(deg2rad(get_pose().theta + 40));
      pos.y = get_pose().y + get_radius() * sin(deg2rad(get_pose().theta + 40));
    }
  }
}

void BraitenbergVehicle::DynamicColor(){  // colors the robot
  // @TODO: change these so they depend on actual distance from the robot
  int food_influence = 1;
  int light_influence = 1;
  int braitenberg_influence = 1;
  double lefttol = 0.0002;
  double righttol = 0.0002;
  int r=0,g=0,b=0;
  if (get_sensor_reading_left(closest_light_entity_) < lefttol &&
     get_sensor_reading_right(closest_light_entity_) < righttol) {
       light_influence = 0;
  }

  if (get_sensor_reading_left(closest_food_entity_) < lefttol &&
     get_sensor_reading_right(closest_food_entity_) < righttol) {
       food_influence = 0;
  }

  if (get_sensor_reading_left(closest_braitenberg_entity_) <= lefttol &&
     get_sensor_reading_right(closest_braitenberg_entity_) <= righttol) {
       braitenberg_influence = 0;
  }

  if (food_influence) {b+=100;}
  if (light_influence) {r+=100;}
  if (braitenberg_influence) {g+=100;}
  if (!food_influence && !light_influence && !braitenberg_influence) {
    r=0;g=0,b=0;
  }
  set_color(RgbColor(r,g,b));
}

void BraitenbergVehicle::CalculateWheelVelocity(){

  light_wheel_velocity_ =
    light_behavior_->CalculateVelocity(
      get_sensor_reading_left(closest_light_entity_),
      get_sensor_reading_right(closest_light_entity_),
      defaultSpeed_);

  food_wheel_velocity_ =
    food_behavior_->CalculateVelocity(
      get_sensor_reading_left(closest_food_entity_),
      get_sensor_reading_right(closest_food_entity_),
      defaultSpeed_);

  bv_wheel_velocity_ =
    braitenberg_behavior_->CalculateVelocity(
      get_sensor_reading_left(closest_braitenberg_entity_),
      get_sensor_reading_right(closest_braitenberg_entity_),
      defaultSpeed_);

  int numBehaviors = 0;
  if(braitenberg_behavior_enum_) numBehaviors++;
  if(light_behavior_enum_) numBehaviors++;
  if(food_behavior_enum_) numBehaviors++;

  if (numBehaviors) {  // numBehaviors > 0
    wheel_velocity_ = WheelVelocity(
      (light_wheel_velocity_->left + food_wheel_velocity_->left +
        bv_wheel_velocity_->left)/numBehaviors,
      (light_wheel_velocity_->right + food_wheel_velocity_->right +
        bv_wheel_velocity_->right)/numBehaviors,
      defaultSpeed_);
  } else {
    wheel_velocity_ = WheelVelocity(0, 0);
  }

  NotifyObservers(light_wheel_velocity_,food_wheel_velocity_,
    bv_wheel_velocity_);
}

void BraitenbergVehicle::LoadFromObject(json_object* entity_config) {
  ArenaEntity::LoadFromObject(entity_config);

  if (entity_config->find("light_behavior") != entity_config->end()) {
      light_behavior_enum_ = get_behavior_type(
        (*entity_config)["light_behavior"].get<std::string>());
      set_light_behavior(light_behavior_enum_);
  }
  if (entity_config->find("food_behavior") != entity_config->end()) {
      food_behavior_enum_ = get_behavior_type(
        (*entity_config)["food_behavior"].get<std::string>());
      set_food_behavior(food_behavior_enum_);
  }
  if (entity_config->find("braitenberg_behavior") != entity_config->end()) {
      braitenberg_behavior_enum_ = get_behavior_type(
        (*entity_config)["braitenberg_behavior"].get<std::string>());
      set_braitenberg_behavior(braitenberg_behavior_enum_);
  }

  UpdateLightSensors();
}

void BraitenbergVehicle::RegisterObserver(Observer * other){
  observers_.push_back(other)
}

void BraitenbergVehicle::RemoveObserver(Observer * other){
  for(unsigned int i = 0; i < observers_.size(); i++){
    if(observers_[i] == other){
      observers_.erase(observers_.begin()+i);
    }
  }
}

void BraitenbergVehicle::NotifyObservers(WheelVelocity * lightvel,
  WheelVelocity * foodvel,  WheelVelocity * bvvel){
  for(unsigned int i = 0; i < observers_.size();i++){
    observers_[i]->update(lightvel,foodvel,bvvel);
  }
}; //for o in observers o-> update();


NAMESPACE_END(csci3081);
