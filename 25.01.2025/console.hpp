#pragma once 
 
#include <iostream> 
#include "types.hpp" 
 
 
namespace con{ 
    using namespace tps; 
 
    void output(Index value); 
    void output(Coord value); 

    void output(Index** matrix, Size nRows, Size nCols); 
    void output(Coord** matrix, Size nRows, Size nCols); 
} 
 
void con::output(Index val){ 
    std::cout << val << ' '; 
} 
void con::output(Coord val){ 
    std::cout << val << ' '; 
} 

void con::output(Index** mat, Size nRows, Size nCols){ 
    for (Size i = 0; i < nRows; i++){ 
           for (Size j = 0; j < nCols; j++){ 
            output(mat[i][j]); 
        } 
        std::cout << std::endl; 
    } 
} 
void con::output(Coord** mat, Size nRows, Size nCols){ 
    for (Size i = 0; i < nRows; i++){ 
           for (Size j = 0; j < nCols; j++){ 
            output(mat[i][j]); 
        } 
        std::cout << std::endl; 
    } 
}