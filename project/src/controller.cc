/**
 * @file controller.cc
 *
 * @copyright 2017 3081 Staff, All rights reserved.
 */

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <nanogui/nanogui.h>
#include <string>
#include <fstream>
#include <streambuf>

#include "src/common.h"
#include "src/controller.h"
#include "src/graphics_arena_viewer.h"
#include "src/light.h"
#include "src/food.h"
#include "src/braitenberg_vehicle.h"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NAMESPACE_BEGIN(csci3081);

// Add quotes around the string
// taken from Amy Larsen's ex09_csv_adapter. Copyright Amy Larsen 2019.
std::string Controller::add_quotes(std::string word) {
  std::string quoted_string("\"");
  quoted_string += (word + "\"");
  return quoted_string;
}

// To determine if quotes should be put around the parsed word
// taken from Amy Larsen's ex09_csv_adapter. Copyright Amy Larsen 2019.
inline bool Controller::in_number_set(std::string word) {
  // compare returns 0 when it matches the word
  return !(
    word.compare("x") && word.compare("y")
    && word.compare("r") && word.compare("theta") );
}

// converts contents of a CSV file to a JSON file.
// taken from Amy Larsen's ex09_csv_adapter. Copyright Amy Larsen 2019.
std::string Controller::csv_to_json(std::string filename) {
  try {
    std::string token;

    // all column labels of csv -- correspond to json keys (e.g. "type")
    std::vector<std::string> keys;

    // read the file that was passed in as argument
    std::ifstream fin(filename);

    // pull first row of column headings
    std::string labels;
    fin >> labels;

    // Save these as the keys that are put into the json string.
    // These include "type" "x" "robot_behavior" etc.
    std::istringstream ss(labels);
    while (std::getline(ss, token, ',')) {
      keys.push_back(token);
    }

    // Start the json configuration string with { "entities": ["
    std::string entities = "{ \"entities\": [\n";

    // read and parse csv file line-by-line
    // convert each line to json entity row and add to entities ...
    /*  for example, using keys from first row, convert
    Braitenberg,220,400,15,270.0,Love,Aggressive,Coward
        to
    {"type": "Braitenberg", "x":220, "y":400, "r":15, "theta": 270.0, "light_behavior": "Love", "food_behavior": "Aggressive", "robot_behavior": "Coward" }
    */

    std::string entity_json;  // populate below by converting csv row to json
    std::string row;          // temp holder of csv row
    std::vector<std::string> words;   // all words parsed from csv row

    // while more rows to parse and convert ...
    while (fin >> row) {
      // parse into separate words (separated by commas)
      std::istringstream sb(row);
      words.clear();
      while (std::getline(sb, token, ',')) {
        words.push_back(token);
      }
      // combine each key with associated word into json row
      // for example: "type" : "Braitenberg" or "x":220
      int keys_index = 0;
      entity_json = "     {";
      for (auto word : words) {
        if (keys_index != 0) { entity_json += ","; }
        entity_json += add_quotes(keys[keys_index]) + ":";
        if (in_number_set(keys[keys_index])) {
          entity_json += word;
        } else {
          entity_json += add_quotes(word);
        }
        ++keys_index;
      }
      entity_json += "}";
      entities += entity_json + ",\n";
    }

    // Erase last comma added to entities
    entities = entities.substr(0, entities.length()-2);

    // Close out the entities array and json string
    entities += "\n  ]\n}";

    // Let's see what we made ...
    return entities;
  }
  catch (const std::exception& e) {
    std::cerr << "Incorrect Format for CSV File" << std::endl;
    return 0;
  }
}  // csv_to_json

bool Controller::is_json_file(std::string in) {
  if (in.substr(in.find_last_of(".") + 1) == "json") {
    return true;
  }
  return false;
}

bool Controller::is_csv_file(std::string in) {
  if (in.substr(in.find_last_of(".") + 1) == "csv") {
    return true;
  }
  return false;
}

Controller::Controller(int argc, char **argv) :
  last_dt(0), arena_x_(X_DIM), arena_y_(Y_DIM),
  viewers_(), config_(NULL) {
  if (argc > 3) {
    std::string filename = std::string(argv[3]);
    arena_x_ = atof(argv[1]);
    arena_y_ = atof(argv[2]);
    std::string json;
    if (is_csv_file(filename)) {
      json = csv_to_json(filename);
    }
    if (is_json_file(filename)) {
      std::ifstream t(std::string(argv[3]).c_str());
      std::string str((std::istreambuf_iterator<char>(t)),
                     std::istreambuf_iterator<char>());
      json = str;
    }
    config_ = new json_value();
    std::string err = parse_json(config_, json);
    if (!err.empty()) {
      std::cerr << "Parse error: " << err << std::endl;
      delete config_;
      config_ = NULL;
    } else {
      arena_ = new Arena(&(config_->get<json_object>()), arena_x_, arena_y_);
    }
  }  // argc > 3
  if (!config_) {
    arena_ = new Arena();
  }
}

Controller::~Controller() {
  if (config_) {
    delete config_;
  }
  for (unsigned int f = 0; f < viewers_.size(); f++) {
    delete viewers_[f];
  }
}

ArenaViewer* Controller::CreateViewer(int width, int height) {
  return new GraphicsArenaViewer(width, height, this);
}

void Controller::Run() {
  viewers_.push_back(CreateViewer(arena_->get_x_dim(), arena_->get_y_dim()));
  for (unsigned int f = 0; f < viewers_.size(); f++) {
    viewers_[f]->SetArena(arena_);
  }

  for (unsigned int f = 0; f < viewers_.size(); f++) {
    viewer_ = viewers_[f];
    if (viewer_->RunViewer()) {
      break;
    }
  }
}

void Controller::AdvanceTime(double dt) {
  if ((last_dt + dt) <= .05) {
    last_dt += dt;
    return;
  }
  last_dt = 0;
  arena_->AdvanceTime(dt);
}


void Controller::Reset() {
  Light::count = 0;
  Food::count = 0;
  BraitenbergVehicle::count = 0;

  if (arena_) {
    delete (arena_);
  }
  if (config_) {
    arena_ = new Arena(&(config_->get<json_object>()), arena_x_, arena_y_);
  } else {
    arena_ = new Arena();
  }
  viewer_->SetArena(arena_);
}


NAMESPACE_END(csci3081);
