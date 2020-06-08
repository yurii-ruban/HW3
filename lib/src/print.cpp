#include "print.h"

void print::printString(const std::string& s)
{
  std::cout << s;
}

void print::printName()
{
  const char* fullName = __PRETTY_FUNCTION__;
  std::string libName = getLibrary(fullName);
  std::cout << libName << " library is used!" << std::endl;
}
