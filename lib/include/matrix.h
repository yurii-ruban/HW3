/* Library, that implements 2D array functionality.
 * Provides object consistency and basic ariphmetic operations*/

#ifndef MATRIX_H
#define MATRIX_H

#include <cstddef>
#include <random>
#include <iostream>

class Matrix
{
 public:
  Matrix();
  Matrix(const Matrix& obj);
  Matrix(const int* const* buffer, size_t height, size_t width);
  Matrix(std::initializer_list<std::initializer_list<int>> list, size_t height, size_t width);

  void fillData();
  bool equal(const Matrix& obj) const;
  bool add(const Matrix& obj);
  bool substract(const Matrix& obj);
  void display();
  Matrix transpose();
  Matrix& operator=(const Matrix& rhs);

  ~Matrix();

 private:
  int** m_buffer;
  size_t m_height;
  size_t m_width;

  bool equalSize(const Matrix& obj) const;
};

#endif // MATRIX_H
