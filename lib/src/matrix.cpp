#include "matrix.h"

Matrix::Matrix():m_buffer(nullptr), m_width(0), m_height(0)
{

}

Matrix::Matrix(const Matrix& obj)
{
  m_width = obj.m_width;
  m_height = obj.m_height;

  m_buffer = new int*[m_height];
  for(size_t i = 0; i < m_height; ++i)
  {
    m_buffer[i] = new int[m_width];
    for(size_t j = 0; j < m_width; ++j)
    {
      m_buffer[i][j] = obj.m_buffer[i][j];
    }
  }
}

Matrix::Matrix(const int* const* buffer, size_t height, size_t width)
{
  m_width = width;
  m_height = height;

  m_buffer = new int*[m_height];
  for(size_t i = 0; i < m_height; ++i)
  {
    m_buffer[i] = new int[m_width];
    for(size_t j = 0; j < m_width; ++j)
    {
      m_buffer[i][j] = buffer[i][j];
    }
  }
}

/* Experimental implementation
 * Might be implemented without excess height and width
 * BTW i'm not sure that nested initializer_list is a good practice */
Matrix::Matrix(std::initializer_list<std::initializer_list<int>> list, size_t height, size_t width)
{
  m_height = height;
  m_width = width;

  auto topListIter = list.begin(); //Need to fit with a double for-statement
  m_buffer = new int*[height];
  for(size_t i = 0; i < m_height; ++i, topListIter++)
  {
    m_buffer[i] = new int[m_width];
    auto nestedListIter = topListIter->begin();
    for(size_t j = 0; j < m_width; ++j)
    {
      m_buffer[i][j] = *(nestedListIter)++;
    }
  }
}

Matrix& Matrix::operator=(const Matrix& rhs)
{
  if(this != &rhs)
  {
    for(size_t i = 0; i < m_height; ++i)
    {
      delete[] m_buffer[i];
    }
    delete[] m_buffer;

    m_width = rhs.m_width;
    m_height = rhs.m_height;
    m_buffer = new int*[m_height];
    for(size_t i = 0; i < m_height; ++i)
    {
      m_buffer[i] = new int[m_width];
      for(size_t j = 0; j < m_width; ++j)
      {
        m_buffer[i][j] = rhs.m_buffer[i][j];
      }
    }
  }
  return *this;
}

void Matrix::fillData()
{
  const int startValue = 1;
  const int endValue = 100;

  std::random_device random_device;
  std::mt19937 random_engine(random_device());
  std::uniform_int_distribution<int> distribution(startValue, endValue);

  for(size_t i = 0 ; i < m_height; ++i)
  {
    for(size_t j = 0; j < m_width; ++j)
    {
      m_buffer[i][j] = distribution(random_engine);
    }
  }
}

bool Matrix::equal(const Matrix& obj) const
{
  bool result = false;
  if(equalSize(obj))
  {
    result = true;
    for(size_t i = 0 ; i < m_height; ++i)
    {
      for(size_t j = 0; j < m_width; ++j)
      {
        if(!(m_buffer[i][j] == obj.m_buffer[i][j]))
        {
          result = false;
          break;
        }
      }
    }
  }
  return result;
}

bool Matrix::add(const Matrix& obj)
{
  if(equalSize(obj))
  {
    for(size_t i = 0; i < m_height; ++i)
    {
      for(size_t j = 0; j < m_width; ++j)
      {
        m_buffer[i][j] += obj.m_buffer[i][j];
      }
    }
    return true;
  }
  return false;
}


bool Matrix::substract(const Matrix& obj)
{
  if(equalSize(obj))
  {
    for(size_t i = 0; i < m_height; ++i)
    {
      for(size_t j = 0; j < m_width; ++j)
      {
        m_buffer[i][j] -= obj.m_buffer[i][j];
      }
    }
    return true;
  }
  return false;
}

Matrix Matrix::transpose()
{
  Matrix result;
  result.m_width = m_height;
  result.m_height = m_width;

  result.m_buffer = new int*[result.m_height];
  for(size_t i = 0; i < result.m_height;++ i)
  {
    result.m_buffer[i] = new int[result.m_width];
    for(size_t j = 0; j < result.m_width; ++j)
    {
      result.m_buffer[i][j] = m_buffer[j][i];
    }
  }

  return result;
}


bool Matrix::equalSize(const Matrix& obj) const
{
  return (m_width == obj.m_width && m_height == obj.m_height);
}

Matrix::~Matrix()
{
  for(size_t i = 0; i < m_height; ++i)
  {
    delete [] m_buffer[i];
  }
  delete[] m_buffer;
}

void Matrix::display()
{
  std::cout << "=======================\n";
  if(!m_width && !m_height)
  {
    std::cout << "No elements\n";
  }
  else
  {
    std::cout << "The content of matrix:\n";
    for(size_t i = 0; i < m_height; ++i)
    {
      for(size_t j = 0; j < m_width; ++j)
      {
        std::cout << m_buffer[i][j] << " ";
      }
      std::cout << std::endl;
    }
  }
  std::cout << "=======================\n\n";
}

