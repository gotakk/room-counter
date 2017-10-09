#ifndef __PLN_LOADER_H__
#define __PLN_LOADER_H__

#include <vector>
#include <string>
#include <fstream>
#include <stdexcept>

#include "Plan.h"

class PlnLoader
{
public:
  PlnLoader() = default;
  ~PlnLoader() = default;

  Plan                          load(std::string const & plnFilePath) const {
      std::ifstream	ifs(plnFilePath, std::ifstream::in);

      if (!ifs.is_open()) {
	throw std::invalid_argument("file not exists");
      }

      Plan		plan = load(ifs);

      ifs.close();
      return plan;
  }

  Plan                          load(std::ifstream & plnFile) const {
    size_t				width = 0;
    size_t				height = 0;
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

  void				parseLine(std::vector<int> & map, std::string const & line) const {
    for (auto character : line) {
      map.push_back((character == '1') ? 1 : 0);
    }
  }
};

#endif
