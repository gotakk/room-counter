#ifndef __PLAN_H__
#define __PLAN_H__

#include <vector>
#include <iostream>

class Plan
{
public:
  typedef std::vector<std::vector<int>>		Matrix;

public:
  Plan() = delete;
  Plan(Matrix matrix) : _matrix(matrix) {}
  Plan & operator=(const Plan & other) {
    if (this != &other) {
      _matrix = other.getMatrix();
    }
    return *this;
  }

  Matrix				getMatrix() const {
    return _matrix;
  }

  friend std::ostream &                 operator<<(std::ostream & oss, Plan const & plan) {
    for (auto row : plan.getMatrix()) {
      for (auto cell : row) {
        char c = (cell == 0) ? ' ' : '#';
        oss << c;
      }
      oss << std::endl;
    }

    return oss;
  }
private:
  Matrix         _matrix;
};

#endif
