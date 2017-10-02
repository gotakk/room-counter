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
    unsigned widthIndex = 0;
    unsigned heightIndex = 0;
    unsigned size = plan.getSize();

    for (unsigned index = 0; index < size; ++index) {
      widthIndex = index / width;
      heightIndex = (index / width) + height;

      if (plan.getCell(index) == 0) {
	++counter;
	exploreRoom(plan, widthIndex, heightIndex, width, height);
      }
    }

    // for (unsigned rowIndex = 0; rowIndex < matrix.size(); ++rowIndex) {
    //   for (unsigned colIndex = 0; colIndex < matrix[rowIndex].size(); ++colIndex) {
    // 	if (matrix[rowIndex][colIndex] == 0) {
    // 	  ++counter;
    // 	  exploreRoom(rowIndex, colIndex, maxRowIndex, maxColIndex);
    // 	}
    //   }
    // }

    std::cout << counter << std::endl;
    return counter;
  }

private:
  void			exploreRoom(Plan & plan, unsigned widthIndex, unsigned heightIndex, unsigned width, unsigned height) {
    plan.setCell(widthIndex, heightIndex, 2);

    // TOP
    if (widthIndex > 0 && plan.getCell(widthIndex - 1, heightIndex) == 0) {
      exploreRoom(plan, widthIndex - 1, heightIndex, width, height);
    }

    // RIGHT
    if (heightIndex < height && plan.getCell(widthIndex, heightIndex + 1) == 0) {
      exploreRoom(plan, widthIndex, heightIndex + 1, width, height);
    }

    // BOTTOM
    if (widthIndex < width && plan.getCell(widthIndex + 1, heightIndex) == 0) {
      exploreRoom(plan, widthIndex + 1, heightIndex, width, height);
    }

    // LEFT
    if (heightIndex > 0 && plan.getCell(widthIndex, heightIndex - 1) == 0) {
      exploreRoom(plan, widthIndex, heightIndex - 1, width, height);
    }
  }

private:
  Architect(Architect const & architect) = delete;
  Architect &	operator=(Architect const & architect) = delete;

};

#endif
