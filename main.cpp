#include "print.h"
#include "multiplier.h"
#include "matrix.h"

/* This function revise that all of the provided Matrix lib functionality
 * works and doesn't cause any issues */
void checkMatrix()
{
  std::cout << "\t\t\tCheck of matrix operations:\n";
  const size_t height = 2;
  const size_t width = 3;

  int **arr = new int*[height];
  for(size_t i = 0; i < height; ++i)
  {
    arr[i] = new int[width];
    for(size_t j = 0; j < width; ++j)
    {
      arr[i][j] = i+j;
    }
  }
  std::cout << "\tInitialized by raw buffer:\n";
  Matrix origin(arr, height, width);
  origin.display();

  std::cout << "\tInitialized by initialize_list:\n";
  Matrix init({{1,2,3},
                 {3,2,1}}, height, width);
  init.display();

  std::cout << "\tEmpty matrix, fillData, assignment operator:\n";
  Matrix empty;
  origin.fillData();
  empty = origin;
  empty.display();

  std::cout << "\tCopy constructor, add, substract, transpose:\n";
  Matrix copy(empty);
  if(copy.equal(empty))
  {
    copy.add(empty);
    copy.substract(empty);
    origin = copy.transpose();
  }
  origin.display();
}

/* This function revise that all of the provided print, multiplier functionality
 * works and doesn't cause any issues */
void checkPrintName()
{
  std::cout << "\t\t\tCheck of printName functions:\n";
  print::printName();
  multiplier::printName();
}

int main(int argc, char** argv)
{
  checkPrintName();
  checkMatrix();
  return 0;
}
