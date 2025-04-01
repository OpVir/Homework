#include <iostream> 
#include <cstdlib> 
#include "sorting.hpp"
#include "tools.hpp"
#include "heap.hpp"

using namespace sorting;
using namespace tools;
using namespace hs;

int main() 
{ 
  const int n = 15;
  int array[n] = {2, 5, 4, 1, 3, 2, 5, 4, 1, 3, 2, 5, 4, 1};

  //merge_sort(array, n);

  
  sort(array, n); 
  
  term(array, n);

  std::system("pause");
  return 0; 
}