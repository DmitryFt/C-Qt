#include "gaiiulin_lab_4.h"
#include <stdexcept>
#include <strstream>
#include <iostream>

using namespace std;

vector<int> CSimp::prove(int x, int y)
{
  if(x <= 0)
  {
    throw std::out_of_range("a must be positive or not null");
  }
  if(y <= 0)
  {
    throw std::out_of_range("b must be positive or not null");
  }
  if(x >= y)
  {
    throw std::out_of_range("b must be more a");
  }
  vector <int> v;
  for(int i = x; i <= y; ++i)
    if(viv(i))
    {
      v.push_back(i);
    }
  return v;
}
bool CSimp::viv(int m)
{
  if(m <= 1)
  {
    return false;
  }
  for(int i = 2; i < m; ++i)
    if(m % i == 0)
    {
      return false;
    }
  return true;
}






