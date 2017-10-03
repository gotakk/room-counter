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
  }
  Plan(Plan const && plan) { }


  void		setCell(unsigned index, int value) {
    if (value == 0) {
      if (index == 0 || index < _width || index > (_width * _height - _width) || index % 4 == 0 || index % 4 == _width - 1) {
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

      if (plan.getCell(indexPlan) == 0) {
	oss << ' ';
      } else {
	oss << '#';
      }
    }

    oss << std::endl;

    return oss;
  }

private:
  Plan() = delete;
  Plan(Plan const & plan) = delete;
  Plan &	operator=(Plan const &) = delete;

  unsigned		_width = 0;
  unsigned		_height = 0;
  std::vector<int>	_map;
};

#endif
