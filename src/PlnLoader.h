#ifndef __PLN_LOADER_H__
#define __PLN_LOADER_H__

#include <vector>
#include <string>
#include <fstream>

class PlnLoader
{
public:
  PlnLoader() {}
  ~PlnLoader() {}

  std::vector<int>              parseLine(std::string const & line) const {
    std::vector<int>            matrixRow;

    matrixRow.reserve(line.length());
    for (auto character : line) {
      matrixRow.push_back((character == '1') ? 1 : 0);
    }

    return matrixRow;
  }

  Plan                          load(std::ifstream & plnFile) const {
    std::vector<std::vector<int>>       matrix;
    std::string                         line;

    while (std::getline(plnFile, line)) {
      matrix.push_back(parseLine(line));
    }

    return Plan(matrix);
  }
};

#endif
