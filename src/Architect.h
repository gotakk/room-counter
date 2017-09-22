#ifndef __ARCHITECT_H__
#define __ARCHITECT_H__

#include "Plan.h"
#include <iostream>
#include <vector>

class Architect
{
public:
  Architect() {}

  void exploreCell(int rowIndex, int colIndex, int maxRowIndex, int maxColIndex) {
    matrix[rowIndex][colIndex] = 2;

    // TOP
    if (rowIndex > 0 && matrix[rowIndex - 1][colIndex] == 0) {
      exploreCell(rowIndex - 1, colIndex, maxRowIndex, maxColIndex);
    }

    // RIGHT
    if (colIndex < maxColIndex && matrix[rowIndex][colIndex + 1] == 0) {
      exploreCell(rowIndex, colIndex + 1, maxRowIndex, maxColIndex);
    }

    // BOTTOM
    if (rowIndex < maxRowIndex && matrix[rowIndex + 1][colIndex] == 0) {
      exploreCell(rowIndex + 1, colIndex, maxRowIndex, maxColIndex);
    }

    // LEFT
    if (colIndex > 0 && matrix[rowIndex][colIndex - 1] == 0) {
      exploreCell(rowIndex, colIndex - 1, maxRowIndex, maxColIndex);
    }
  }

  int countRoom(const Plan & plan) {
    Plan tmp = plan;
    int counter = 0;
    matrix = tmp.getMatrix();
    int maxRowIndex = matrix.size();
    int maxColIndex = matrix[0].size();

    for (int rowIndex = 0; rowIndex < matrix.size(); ++rowIndex) {
      for (int colIndex = 0; colIndex < matrix[rowIndex].size(); ++colIndex) {
	if (matrix[rowIndex][colIndex] == 0) {
	  ++counter;
	  exploreCell(rowIndex, colIndex, maxRowIndex, maxColIndex);
	}
      }
    }

    std::cout << counter;
  }
private:
  Plan::Matrix		matrix;
};

#endif
