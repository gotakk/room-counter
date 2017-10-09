#ifndef __ARCHITECT_H__
#define __ARCHITECT_H__

#include <vector>

#include "Plan.h"

class Architect
{
public:
  Architect() {}
  ~Architect() {}

  int countRooms(Plan & plan) {
    int counter = 0;
    size_t width = plan.getWidth();
    size_t height = plan.getHeight();

    for (size_t x = 0; x < width; ++x) {
      for (size_t y = 0; y < height; ++y) {
	if (plan.getCell(x, y) == 0) {
	  ++counter;
	  exploreRoom(plan, x, y, width, height);
	}
      }
    }

    return counter;
  }

private:
  void			exploreRoom(Plan & plan, size_t x, size_t y, size_t width, size_t height) {
    plan.setCell(x, y, 2);

    // TOP
    if (x > 0 && plan.getCell(x - 1, y) == 0) {
      exploreRoom(plan, x - 1, y, width, height);
    }

    // RIGHT
    if (y < height && plan.getCell(x, y + 1) == 0) {
      exploreRoom(plan, x, y + 1, width, height);
    }

    // BOTTOM
    if (x < width && plan.getCell(x + 1, y) == 0) {
      exploreRoom(plan, x + 1, y, width, height);
    }

    // LEFT
    if (y > 0 && plan.getCell(x, y - 1) == 0) {
      exploreRoom(plan, x, y - 1, width, height);
    }
  }

private:
  Architect(Architect const & architect) = delete;
  Architect &	operator=(Architect const & architect) = delete;

};

#endif
