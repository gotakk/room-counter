#ifndef __PLN_LOADER_H__
#define __PLN_LOADER_H__

#include <vector>
#include <string>
#include <fstream>

#include "Plan.h"

class PlnLoader
{
public:
  PlnLoader() {}
  ~PlnLoader() {}

  void				parseLine(std::vector<int> & map, std::string const & line) const {
    for (auto character : line) {
      map.push_back((character == '1') ? 1 : 0);
    }
  }

  Plan                          load(std::ifstream & plnFile) const {
    unsigned				width = 0;
    unsigned				height = 0;
    std::vector<int>			map;
    std::string                         line;

    while (std::getline(plnFile, line)) {
      parseLine(map, line);
      ++height;
    }

    width = line.size();
    return Plan(width, height, map);
  }

private:
  PlnLoader(PlnLoader const &) = delete;
  PlnLoader & operator=(PlnLoader const &) = delete;
};

#endif
