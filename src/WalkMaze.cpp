#include "WalkMaze.h"
#include "Box.h"
#include "Maze.h"

#include<iostream>
#include <vector>
#include <stack>
#include <array>


using std::vector;
using std::cout;
using std::endl;

namespace mazewalking
{
void WalkMaze::initMap() {

  vector<vector<int>> orignal_map = _maze->getMaze();

  _maze_row_numb = _maze->getMazeRowNumb();
  _maze_col_numb = _maze->getMazeColNumb();

  // init Map with size (_maze_col_numb + 2, _maze_row_numb + 2)
  // since we add boundary obstacle, the size will increase by 2
  vector<int> vtemp(_maze_col_numb + 2, 1);
  vector<vector<int>> map_temp(_maze_row_numb + 2, vtemp);

  // add the orignal_map into Map with boundary obstacle.
  for (int i = 0; i < _maze_row_numb; ++i) {
    for (int j = 0; j < _maze_col_numb; ++j) {
      map_temp[i + 1][j + 1] =  orignal_map[i][j];
    }
  }

  _map = map_temp;

} 

void WalkMaze::initMoveDiretion() {
  MoveLocation move_up     (-1,  0);
  MoveLocation move_down   ( 1,  0);
  MoveLocation move_left   ( 0, -1);
  MoveLocation move_right  ( 0,  1);
  
  // default movement direction as follows: move right、 down、 left、 up
  _move_dire.push_back(move_right);
  _move_dire.push_back(move_down);
  _move_dire.push_back(move_left);
  _move_dire.push_back(move_up);
}

void WalkMaze::showMap() {
  for (int i = 0; i < _maze_row_numb + 2; ++i) {
    for (int j = 0; j < _maze_col_numb + 2; ++j) {
      if (_map[i][j] == 1) {
        cout << "x ";
      } else {
          cout << "o ";
        }
    }
    cout << std::endl;
  }
}

bool WalkMaze::findPath(Box start_box, Box tag_box) {
  initMap();
  initMoveDiretion();
  showMap();

  int start_x = start_box.getX();
  int start_y = start_box.getY();

  int tag_x = tag_box.getX();
  int tag_y = tag_box.getY();

  // The start and target box can't be obstacle.
  if (_map[start_x][start_y] == 1)
  {
    cout << "Can't begin with this input start box!!!" << endl;
    return false;
  }
  if (_map[tag_x][tag_y] == 1)
  {
    cout << "Can't arrived this target box!!! Since it's an obstacle" << endl;
    return false;
  }
  

  // 每走一步就让其变成障碍
  _map[start_x][start_y] = 1;

  int option = 0;
  int max_option = 3;

  int direct;

  std::array<int, 4> greedy_choice_of_move_direction;

  // while (start_x < _maze_row_numb || start_y < _maze_col_numb)
  while (abs(start_x - tag_x) > 0 || abs(start_y - tag_y) > 0)

  {
    cout << "qidian" << start_x<<"," << start_y<< option<<endl;
    
    // 选择走的方向 贪心顺序：根据起点和终点的相对位置，设置行走方向优先级
 
    if ((start_x - tag_x) != 0 && (start_y - tag_y) != 0)
    {
      // case1: 起点位于终点左下方
      if (start_x >= tag_x && start_y <= tag_y)
      {
        greedy_choice_of_move_direction = {0, 3, 2, 1};
      }
      // case 2: 起点位于终点左上方
      else if (start_x <= tag_x && start_y <= tag_y)
      {
        greedy_choice_of_move_direction = {0, 1, 2, 3};
      }
      // case 3: 起点位于终点右下方
      else if (start_x >= tag_x && start_y >= tag_y)
      {
        greedy_choice_of_move_direction = {2, 3, 0, 1};
      }
      // case 4: 起点位于终点右上方
      else if (start_x <= tag_x && start_y >= tag_y)
      {
        greedy_choice_of_move_direction = {2, 1, 0, 3};
      }
    } else {
        if (start_x - tag_x == 0 && start_y - tag_y < 0)  // 起点在终点左方
        {
          greedy_choice_of_move_direction = {0, 3, 1, 2};
        } 
        else if (start_x - tag_x == 0 && start_y - tag_y > 0)
        {                                          // 起点在终点右方
          greedy_choice_of_move_direction = {2, 3, 0, 1};
        }

        else if (start_x - tag_x < 0 && start_y - tag_y == 0)  // 起点在终点上方
        {
          greedy_choice_of_move_direction = {1, 3, 0, 2};
        } 
        else if (start_x - tag_x > 0 && start_y - tag_y == 0)
        {                                          // 起点在终点下方
          greedy_choice_of_move_direction = {3, 2, 0, 1};
        }
      
      }
    
    
    // // case1: 起点位于终点左下方
    // if (start_x >= tag_x && start_y <= tag_y)
    // {
    //   greedy_choice_of_move_direction = {0, 3, 2, 1};
    // }
    // // case 2: 起点位于终点左上方
    // else if (start_x <= tag_x && start_y <= tag_y)
    // {
    //   greedy_choice_of_move_direction = {0, 1, 2, 3};
    // }
    // // case 3: 起点位于终点右下方
    // else if (start_x >= tag_x && start_y >= tag_y)
    // {
    //   greedy_choice_of_move_direction = {2, 3, 0, 1};
    // }
    // // case 4: 起点位于终点右上方
    // else if (start_x <= tag_x && start_y >= tag_y)
    // {
    //   greedy_choice_of_move_direction = {2, 1, 0, 3};
    // }

    // int direct = greedy_choice_of_move_direction[option];

    int next_position_x;
    int next_position_y;
    while (option <= max_option)
    { 
      // cout << "adsfadsfadsfa" ;
      // for (int i = 0; i < 4; i++)
      // {
      //   cout << greedy_choice_of_move_direction[i] << "";
      // }
      // cout << endl;

      direct = greedy_choice_of_move_direction[option];
      next_position_x = start_x + _move_dire[direct].getX();
      next_position_y = start_y + _move_dire[direct].getY();
      
      // next_position_x = start_x + _move_dire[option].getX();
      // next_position_y = start_y + _move_dire[option].getY();
      // 此路可通
      if (_map[next_position_x][next_position_y] == 0) {
        break;
      }
      ++option;
    }
    // std::cout << option << std::endl;
    if (option <= max_option)
    {
      // 到达终点
      // if (next_position_x == tag_box.getX() 
      //     && next_position_y == tag_box.getY()) {
      //   return true;
      // }

      // _path.push(start_box);
      _path.push(Box(start_x,start_y));
      // cout << "path" << start_x<<"," << start_y<< endl;
      // int direct = greedy_choice_of_move_direction[option];

      switch (direct)
      {
      case 0:
        _act.push_back(Action::go_right);
        break;
      case 1:
        _act.push_back(Action::go_down);
        break;
      case 2:
        _act.push_back(Action::go_left);
        break;
      case 3:
        _act.push_back(Action::go_up);
        break;
      default:
        break;
      }
      
      // cout << "x" << start_box.getX()<<next_position_x<< endl;
      // cout << "y" << start_box.getY()<<next_position_y<< endl;

      // start_box.setX(next_position_x);
      // start_box.setY(next_position_y);

      // cout << "xxxx" << start_box.getX()<< endl;
      // cout << "yyyy" << start_box.getY()<< endl;


      // 起点变换
      start_x = next_position_x;
      start_y = next_position_y;

      // 标记已走
      _map[next_position_x][next_position_y] = 1;

      // cout << "add"<< std::endl;
      // cout << next_position_x << " " << next_position_y << std::endl;

      option = 0;
    } else {
        cout << "cannot find"<< _path.size() << std::endl;
        
        if (_path.empty()) {//无路可退
          return false;
        }

        Box curr_box = _path.top();
        _path.pop();
        _act.pop_back();
        // if (curr_box.getX() == start_x) {//先前的节奏保持在了同一行，那么那一步要么上，要么下
        // direct = 2 + curr_box.getY() - start_y;
        // } else {
        //   //先前的节奏保持在了同一列，那么那一步要么左，要么结束
        //     direct = 3 + curr_box.getX() - start_x;
        //   }
        direct = 0;
        option = 0;
        start_x = curr_box.getX();
        start_y = curr_box.getY();
      cout << "nest" << start_x<<"," << start_y<< endl;

      }
  }
  _path.push(tag_box);
  return true; 
}

void WalkMaze::showResult(Box start_box, Box tag_box) {
  if (findPath(start_box, tag_box))
  {
    // printPath();
    printMazeWithPath(start_box, tag_box);
  } else {
    std::cout << "Cannot find path!!!" << std::endl;
  }
  
  for (auto act:_act)
  {
    cout << int(act) << " ";
  }
  
  
}

void WalkMaze::printPath() {
  while(!_path.empty())
  {
    Box temp = _path.top();
    _path.pop();
    std::cout << "(" << temp.getX() << "," << temp.getY() << ")";
    if (!_path.empty())
    {
     std::cout << "<-";
    } 
  }
}


void WalkMaze::printMazeWithPath(Box start_box, Box tag_box) {
  int row_size_of_map = _map.size() + 2 * (_map.size() - 1);
  int col_size_of_map = _map[0].size() + 2 * (_map[0].size() - 1);
  cout<<row_size_of_map<<" " << col_size_of_map <<endl;

  vector<vector<string>> map(row_size_of_map, vector<string>(col_size_of_map, "⬜"));

  int start_x = start_box.getX();
  int start_y = start_box.getY();

  int tag_x = tag_box.getX();
  int tag_y = tag_box.getY();
  
  int a = 0;
  int b = 0;
  for (int i = 0; i < _maze_row_numb+2; i++)
  {
    for (int j = 0; j < _maze_col_numb+2; j++)
    {
      // cout << 'i' << i << " j" << j <<endl;
      // cout << 'a' << a << " b" << b <<endl;

      if (_map[i][j] == 0)
      {
        map[a][b] = "👻";
      } else {
        map[a][b] = "🐍";
      }
      
      // map[a][b] = orignal_map[i][j];
      b += 3;
      if (b > col_size_of_map)
      {
        b = 0;
      }
      
    }
    a += 3;
    if (a > row_size_of_map)
    {
      a = 0;
    }
    
  }

  int path_len = _path.size();
  for (int i = 0; i < path_len; i++)
  {
    Box temp = _path.top();
    _path.pop();
    map[temp.getX()*3][temp.getY()*3] = "🍕";
    // cout << temp.getX() << "y" << temp.getY() << endl;

    int act_len = _act.size();
    if (i < act_len)
    {  
      // cout << (int)_act[act_len-1-i] << endl;

      // switch (_act[act_len-1-i])
      // {
      // case Action::go_down:
      //   map[temp.getX() * 3 - 1][temp.getY()*3] = "v";
      //   map[temp.getX() * 3 - 2][temp.getY()*3] = "|";
      //   break;
      // case Action::go_right:
      //   map[temp.getX()*3][temp.getY() * 3 - 1] = ">";
      //   map[temp.getX()*3][temp.getY() * 3 - 2] = "-";
      //   break;
      // case Action::go_up:
      //   map[temp.getX() * 3 + 1][temp.getY()*3] = "^";
      //   map[temp.getX() * 3 + 2][temp.getY()*3] = "|";
      //   break;
      // case Action::go_left:
      //   map[temp.getX()*3][temp.getY() * 3 + 1] = "<";
      //   map[temp.getX()*3][temp.getY() * 3 + 2] = "-";
      //   break;
      // default:
      //   break;
      // }
      switch (_act[act_len-1-i])
      {
      case Action::go_down:
        map[temp.getX() * 3 - 1][temp.getY()*3] = "🐁";
        map[temp.getX() * 3 - 2][temp.getY()*3] = "🐁";
        break;
      case Action::go_right:
        map[temp.getX()*3][temp.getY() * 3 - 1] = "🐁";
        map[temp.getX()*3][temp.getY() * 3 - 2] = "🐁";
        break;
      case Action::go_up:
        map[temp.getX() * 3 + 1][temp.getY()*3] = "🐁";
        map[temp.getX() * 3 + 2][temp.getY()*3] = "🐁";
        break;
      case Action::go_left:
        map[temp.getX()*3][temp.getY() * 3 + 1] = "🐁";
        map[temp.getX()*3][temp.getY() * 3 + 2] = "🐁";
        break;
      default:
        break;
      }
    }
  }
  
  /** Mark the start and target points: 
      🚩 denotes the start
      🏁 denotes the target **/
  map[start_x * 3][start_y * 3] = "🚩";
  map[tag_x * 3][tag_y * 3] = "🏁";

  for (int i = 0; i < row_size_of_map; i++)
  {
    for (int j = 0; j < col_size_of_map; j++)
    {
      cout << map[i][j];
    }
    cout << endl;
  }
  
  
}

} // namespace mazewalking
