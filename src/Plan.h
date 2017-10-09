#ifndef __PLAN_H__
#define __PLAN_H__

#include <vector>
#include <iostream>

class Plan
{
public:

  Plan(size_t width, size_t height, std::vector<int> const & map)
    : _width(validateWidth(width))
    , _height(validateHeight(height))
    , _map(validateMap(map)) { }
  Plan(Plan const && plan) { }


  void		setCell(size_t index, int value) {
    if (index > _map.size()) {
      throw std::logic_error("index overflow");
    }

    _map[index] = value;
  }

  size_t	getCell(size_t index) const {
    if (index > _map.size()) {
      throw std::logic_error("index overflow");
    }

    return _map[index];
  }

  void		setCell(size_t x, size_t y, int value) {
    setCell(x + _width * y, value);
  }

  size_t	getCell(size_t x, size_t y) const {
    return getCell(x + _width * y);
  }

  size_t	getWidth() const {
    return _width;
  }

  size_t	getHeight() const {
    return _height;
  }

  size_t	getSize() const {
    return _map.size();
  }

  friend std::ostream &                 operator<<(std::ostream & oss, Plan const & plan) {
    size_t	planWidth = plan.getWidth();
    size_t	planSize = plan.getSize();

    for (size_t indexPlan = 0; indexPlan < planSize; ++indexPlan) {
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

  size_t	validateWidth(size_t width) {
    if (width < 2) {
      throw std::invalid_argument("width must be strictly higher than 1");
    }
    return width;
  }

  size_t	validateHeight(size_t height) {
    if (height < 2) {
      throw std::invalid_argument("height must be strictly higher than 1");
    }
    return height;
  }

  std::vector<int> const &	validateMap(std::vector<int> const & map) {
    size_t const	mapSize = map.size();

    if (_width * _height != mapSize) {
      throw std::invalid_argument("width * height are different of map size");
    }

    // check TOP and BOTTOM
    for (size_t i = 0; i < _width; ++i) {
      size_t const topOffset = i;
      size_t const bottomOffset = (_height - 1) * _width + i;
      if (map[topOffset] == 0) {
	throw std::invalid_argument("bad map, not surrounded by walls (top side)");
      }
      if (map[bottomOffset] == 0) {
	throw std::invalid_argument("bad map, not surrounded by walls (bottom side)");
      }
    }

    // check LEFT and RIGHT
    for (size_t i = 0; i < _height; ++i) {
      size_t const leftOffset = i * _width;
      size_t const rightOffset = leftOffset + (_width - 1);
      if (map[leftOffset] == 0) {
	throw std::invalid_argument("bad map, not surrounded by walls (left side)");
      }
      if (map[rightOffset] == 0) {
	throw std::invalid_argument("bad map, not surrounded by walls (right side)");
      }
    }

    return map;
  }

  size_t const          _width = 0;
  size_t const 	        _height = 0;
  std::vector<int>	_map;
};

#endif
