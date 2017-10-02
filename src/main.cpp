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

  std::ifstream ifs(argv[1], std::ifstream::in);

  PlnLoader plnLoader;
  Plan plan = plnLoader.load(ifs);
  Architect architect;

  ifs.close();
  std::cout << plan;


  architect.countRooms(plan);

  return 0;
}
