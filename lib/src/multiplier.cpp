#include "multiplier.h"

int multiplier::makeDouble(int number)
{
  return 2 * number;
}

void multiplier::printName()
{
  const char* fullName = __PRETTY_FUNCTION__;
  std::string libName = getLibrary(fullName);
  std::cout << libName << " library is used!" << std::endl;
}
