#include "WalkMaze.h"
#include "Maze.h"
#include "Box.h"

int main() {
  mazewalking::Maze * maze = new mazewalking::Maze;
  // mazewalking::Maze maze;

  mazewalking::WalkMaze walk(maze);

  // walk.initMap();
  // walk.showMap();

  // mazewalking::Box start1(6, 6);
  // mazewalking::Box taget1(1, 1);
  // walk.showResult(start1, taget1);

  // mazewalking::Box start2(1, 1);
  // mazewalking::Box taget2(6, 5);
  // walk.showResult(start2, taget2);

  mazewalking::Box start2(1, 1);
  // mazewalking::Box taget2(4, 8);
  mazewalking::Box taget2(3, 7);

  walk.showResult(start2, taget2);

  // mazewalking::Box start(3, 4);
  // mazewalking::Box taget(4, 2);

  // std::cout << walk.findPath(start, taget) << std::endl;






  std::cout << "\nDone" << std::endl;
  return 0;

}