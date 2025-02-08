#include <iostream> 
#include <cstdlib> // std::system 

 
int main() 
{ 
  unsigned int year = 0;
  std::cout<<"Enter year: ";
  std::cin >> year;
  unsigned int centary = 0;
  if (year/100 == 0){
    centary = 1;
  } else if (year % 100 > 0){
    centary = year/100 + 1;
  } else{
    centary = year /100;
  }
  std::cout<< "cenatry is ";
  std::cout << centary << std::endl;
  std::system("pause"); 
  return 0; 
}