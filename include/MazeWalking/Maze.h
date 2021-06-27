#pragma once

#include<iostream>
#include <vector>
#include <stack>

using std::vector;

namespace mazewalking
{
class Maze {
  
 public:
  vector<vector<int>> getMaze() { return _map; }

  int getMazeRowNumb() { return _map.size(); }
  int getMazeColNumb() { return _map[0].size(); }
 private:

 // "1" means this road is not available;
 // "0" means passable.
//   vector<vector<int>> _map = {  { 0,1,1,0,1,1 },
//                                 { 0,0,1,0,1,0 },
//                                 { 0,0,1,0,0,0 },
//                                 { 1,0,0,0,1,0 },
//                                 { 0,1,1,1,0,0 },
//                                 { 0,1,1,1,0,0 } };
  vector<vector<int>> _map = {  { 0,0,0,0,1,1,1,1 },
                                { 0,0,0,0,0,1,1,1 },
                                { 1,1,0,1,1,0,0,0 },
                                { 1,0,0,0,0,0,0,0 } };


};
} // namespace mazewalking
