#include <iostream> 
#include <cstdlib> // std::system 
#include <fstream> //std::{ifstream, ofstream, fstream} 
#include <ios>     //std::ios::binary 
#include "geometry.hpp" 
 
 
int main() 
{ 
  using namespace geom; 
  //using geom::operator*; 
  vector v1, v2; 
 
  input(v1); 
  input(v2); 
 
  output(v1*v2); 
  output(scale(v1, 10)); 
  std::system("pause"); 
  return 0; 
}