#include <iostream> 
#include <cstdlib> 
#include "sorting.hpp"
#include "tools.hpp"

using namespace sorting;
using namespace tools;

int main() 
{ 
  const int n = 20;
  int array[n] = {2, 5, 4, 1, 2, 9, 6, 5, 10, 12, 2, 5, 4, 1, 2, 6, 5, 10, 12};

  bubble_extra(array, n, 1);

  term(array, n);
  
  std::system("pause");
  return 0; 
}