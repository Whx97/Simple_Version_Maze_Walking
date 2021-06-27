#pragma once

#include "Maze.h"
#include "Box.h"

#include<iostream>
#include <vector>
#include <stack>

using std::vector;
using std::stack;
using std::string;

namespace mazewalking
{
class MoveLocation : public Box {
 public:
  MoveLocation(int x, int y)
    : Box(x, y) {
        this->_x = x;
        this->_y = y;
  }

 private:
  int _x;
  int _y;
};

class WalkMaze {

 public:
  enum class Action{go_right, go_down, go_left, go_up};

  WalkMaze(Maze *maze)
    : _maze(maze) {}

  // Initialize the obstacle wall outside the maze, this is to make it easier to handle the boundary location
  void initMap();
  // The default movement direction is defined, which will be updated continuously during the movement
  void initMoveDiretion();

  // show the map after initMap operation, it's including the boundary obstacle.
  void showMap();

  // find the path between start box and target box if exist
  bool findPath(Box start_box, Box tag_box);

  // For external use.
  // If there is a path from the start to the target, it will automatically find the path and print it out
  void showResult(Box start_box, Box tag_box);

  void printPath();

  // Print the walking path with interesting visualization
  void printMazeWithPath(Box start_box, Box tag_box);

 private:


  Maze *                 _maze;
  int                    _maze_row_numb;
  int                    _maze_col_numb;

 // "1" means this road is not available;
 // "0" means passable.
  vector<vector<int>>   _map;

  stack<Box>            _path;

  // Movement direction
  vector<MoveLocation>  _move_dire;

  // used to record action
  vector<Action>        _act;
};
} // namespace mazewalking
