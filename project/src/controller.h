/**
 * @file controller.h
 *
 * @copyright 2017 3081 Staff, All rights reserved.
 */

#ifndef SRC_CONTROLLER_H_
#define SRC_CONTROLLER_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <nanogui/nanogui.h>
#include <string>
#include <vector>

#include "src/arena.h"
#include "src/common.h"
#include "src/arena_viewer.h"
#include "src/params.h"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NAMESPACE_BEGIN(csci3081);

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief Controller that mediates Arena and GraphicsArenaViewer communication.
 *
 * The Controller instantiates the Arena and the GraphicsArenaViewer. The
 * viewer contains the main loop that keeps it live, but at each update, the
 * viewer sends a message to the controller to update its time.
 *
 * Other types of communication between Arena and Viewer include:
 * - keypresses intercepted by the Viewer.
 * - Play/Pause/New Game user input via the Viewer.
 * - Game status from arena to the viewer.
 **/
class Controller {
 public:
  /**
   * @brief Controller's constructor that will create Arena and Viewer.
   */
  Controller(int argc, char **argv);

  virtual ~Controller();

  virtual ArenaViewer* CreateViewer(int width, int height);

  /**
   * @brief Run launches the graphics and starts the game.
   */
  void Run();

  /**
   * @brief AdvanceTime is communication from the Viewer to advance the
   * simulation.
   */
  void AdvanceTime(double dt);

 /**
  * @brief Completely destroy and remake the arena
  */
  void Reset();

  // copy constructor
  Controller(const Controller &other):
  last_dt(other.last_dt), arena_x_(other.arena_x_), arena_y_(other.arena_y_),
  viewers_(other.viewers_), config_(other.config_) {
    // normal params
//    last_dt = other.last_dt;
//    viewers_ = other.viewers_;

    // copy reference for pointers?
    arena_ = other.arena_;
    *viewer_ = *other.viewer_;
//    *config_ = *other.config_;
  }

  Controller &operator=(const Controller &other) = delete;

  std::string add_quotes(std::string word);
  inline bool in_number_set(std::string word);
  std::string csv_to_json(std::string filename);

  bool is_json_file(std::string in);
  bool is_csv_file(std::string in);

 private:
  double last_dt{0};
  Arena* arena_{nullptr};
  double arena_x_;
  double arena_y_;
  ArenaViewer* viewer_{nullptr};
  std::vector<ArenaViewer*> viewers_;
  json_value* config_;
};

NAMESPACE_END(csci3081);

#endif  // SRC_CONTROLLER_H_
