#ifndef __PLAN_H__
#define __PLAN_H__

#include <vector>
#include <iostream>

class Plan
{
public:

  Plan(unsigned width, unsigned height, std::vector<int> const & map) : _width(width), _height(height), _map(map) {
    if (_width < 2) {
      throw std::invalid_argument("width must be strictly higher than 1");
    }

    if (_height < 2) {
      throw std::invalid_argument("height must be strictly higher than 1");
    }

    if (_width * _height != _map.size()) {
      throw std::invalid_argument("width * height are different of map size");
    }

    unsigned size = getSize();

    for (unsigned i = 0; i < size; ++i) {
      if (map[i] == 0 && isSideWall(i)) {
	throw std::invalid_argument("bad map, not surrounded by walls");
      }
    }
  }
  Plan(Plan const && plan) { }


  void		setCell(unsigned index, int value) {
    if (value == 0) {
      if (isSideWall(index)) {
	throw std::logic_error("Try to remove an immoveable wall");
      }
    }

    _map[index] = value;
  }

  unsigned	getCell(unsigned index) const {
    return _map[index];
  }

  void		setCell(unsigned x, unsigned y, int value) {
    setCell(x + _width * y, value);
  }

  unsigned	getCell(unsigned x, unsigned y) const {
    return getCell(x + _width * y);
  }

  unsigned	getWidth() const {
    return _width;
  }

  unsigned	getHeight() const {
    return _height;
  }

  unsigned	getSize() const {
    return _map.size();
  }

  friend std::ostream &                 operator<<(std::ostream & oss, Plan const & plan) {
    unsigned	planWidth = plan.getWidth();
    unsigned	planSize = plan.getSize();

    for (unsigned indexPlan = 0; indexPlan < planSize; ++indexPlan) {
      if (indexPlan != 0) {
	if (indexPlan % planWidth == 0) {
	  oss << std::endl;
	}
      }

      switch (plan.getCell(indexPlan)) {
      case 0:
	oss << ' ';
	break;
      case 1:
	oss << '#';
	break;
      default:
	oss << '?';
	break;
      }
    }

    oss << std::endl;

    return oss;
  }

private:
  Plan() = delete;
  Plan(Plan const & plan) = delete;
  Plan &	operator=(Plan const &) = delete;

  bool		isSideWall(unsigned index) {
    // TOP
    if (index < _width) {
      return true;
    }

    // BOTTOM
    if (index > (_width * _height - _width)) {
      return true;
    }

    // RIGHT
    if (index % _width == 0) {
      return true;
    }

    // LEFT
    if (index % _width == _width - 1) {
      return true;
    }

    return false;
  }

  unsigned		_width = 0;
  unsigned		_height = 0;
  std::vector<int>	_map;
};

#endif
