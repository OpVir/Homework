#pragma once 
#include <iostream> 

namespace tls{
    using Value = int;
    using Size = int;
    using Index = int;
    
    auto term(Value* const array, Size const size) -> void;
}

auto tls::term(Value* const array, Size const size) -> void{
    for (int i = 0; i < size; i++)
    { 
        std::cout << array[i] << " ";
    }
    std::cout<<std::endl;
}