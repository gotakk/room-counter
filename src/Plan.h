#ifndef __PLAN_H__
#define __PLAN_H__

#include <vector>
#include <iostream>

class Plan
{
public:

  Plan(unsigned width, unsigned height, std::vector<int> const & map) : _width(width), _height(height), _map(map) { }
  Plan(Plan const && plan) { }


  void		setCell(unsigned index, int value) {
    _map[index] = value;
  }

  unsigned	getCell(unsigned index) const {
    return _map[index];
  }

  void		setCell(unsigned width, unsigned height, int value) {
    _map[width * height + height] = value;
  }

  unsigned	getCell(unsigned width, unsigned height) const {
    return _map[width * height + height];
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
    char	c;
    int		cellValue;
    unsigned	planWidth = plan.getWidth();

    for (unsigned index = 0; index < plan.getSize(); ++index) {
      if (index && index % planWidth == 0) {
	oss << std::endl;
      }

      cellValue = plan.getCell(index);
      c = (cellValue == 0) ? ' ' : '#';
      oss << c;
    }

    oss << std::endl;

    return oss;
  }

private:
  Plan() = delete;
  Plan(Plan const & plan) = delete;
  Plan &	operator=(Plan const &);

  unsigned		_width = 0;
  unsigned		_height = 0;
  std::vector<int>	_map;
};

#endif
