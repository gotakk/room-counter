#ifndef __ARCHITECT_H__
#define __ARCHITECT_H__

#include <iostream>
#include <vector>
#include "Plan.h"

class Architect
{
public:
  Architect() {}

  int countRooms(Plan & plan) {
    int counter = 0;
    unsigned width = plan.getWidth();
    unsigned height = plan.getHeight();

    for (unsigned x = 0; x < width; ++x) {
      for (unsigned y = 0; y < height; ++y) {
	if (plan.getCell(x, y) == 0) {
	  ++counter;
	  exploreRoom(plan, x, y, width, height);
	}
      }
    }

    std::cout << counter << std::endl;
    return counter;
  }

private:
  void			exploreRoom(Plan & plan, unsigned x, unsigned y, unsigned width, unsigned height) {
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
