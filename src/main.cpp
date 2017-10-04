#include <fstream>
#include <iostream>
#include <memory>

#include	"Plan.h"
#include	"PlnLoader.h"
#include	"Architect.h"

int main(int argc, char * argv[])
{
  if (argc < 2) {
    std::cerr << "USAGE: ./a.out PLN_FILE" << std::endl;
    return 1;
  }

  PlnLoader plnLoader;
  Plan plan = plnLoader.load(argv[1]);
  Architect architect;

  std::cout << architect.countRooms(plan) << std::endl;

  return 0;
}
