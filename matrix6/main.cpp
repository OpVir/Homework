#include <iostream> 
#include <cstdlib> // std::system 

 
int main() 
{ 
  unsigned int N = 4, M = 4, Q = 5;
  int array[N] = {1, 2, 3, 4};
  int matrix[M][N];
  for (int i = 0; i < N; i++)
  {
    matrix[0][i] = array[i];
    std::cout << matrix[0][i]<< " ";
  }
  std::cout << std::endl;

  for (int i = 1; i < M; i++){
    for (int j = 0; j < N; j++){
      matrix[i][j] = matrix[i-1][j] * Q;
      std::cout << matrix[i][j]<< " ";
    }
    std::cout << std::endl;
  }
  
  std::system("pause"); 
  return 0; 
}