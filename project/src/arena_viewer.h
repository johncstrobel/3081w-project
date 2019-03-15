/**
 * @file arena_viewer.h
 *
 * @copyright 2017 3081 Staff, All rights reserved.
 */

#ifndef SRC_ARENA_VIEWER_H_
#define SRC_ARENA_VIEWER_H_

#include "src/arena.h"

NAMESPACE_BEGIN(csci3081);

/**
* @brief Does something related to running the actual app. Was a given file
*  so I'm not sure how it does that.
* 
*/
class ArenaViewer {
 public:
  virtual ~ArenaViewer() {}
  virtual bool RunViewer() = 0;
  virtual void SetArena(Arena* arena) = 0;
};

NAMESPACE_END(csci3081);

#endif  // SRC_ARENA_VIEWER_H_
