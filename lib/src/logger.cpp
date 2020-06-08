#ifndef LOGGER_CPP
#define LOGGER_CPP

#include "logger.h"

std::string getLibrary(const char* fullName)
{
  std::string libName("");
  while(*fullName != ' ')
  {
    fullName++;
  }
  fullName++;

  while(*fullName != ':')
  {
    libName += *fullName;
    fullName++;
  }
  return libName;
}

#endif // LOGGER_CPP
