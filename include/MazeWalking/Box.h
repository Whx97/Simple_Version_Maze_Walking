#pragma once

namespace mazewalking
{
class Box {

 public:
  Box (int x, int y)
    : _x(x),
      _y(y) {
  }
  int getX() { return _x; }
  int getY() { return _y; }

 private:
  int       _x;
  int       _y;
};
} // namespace mazewalking
