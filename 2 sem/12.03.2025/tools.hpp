#pragma once 
#include <iostream> 

namespace tools{
    using Value = int;
    using Size = int;
    using Index = int;

    auto swap(Value* array, Index first, Index second) -> void;

    auto term(Value* const array, Size const size) -> void;
}
auto tools::swap(Value* array, Index first, Index second) -> void{
    Value buf = array[second];
    array[second] = array[first];
    array[first] = buf;
}
auto tools::term(Value* const array, Size const size) -> void{
    for (int i = 0; i < size; i++)
    { 
        std::cout << array[i] << " ";
    }
    std::cout<<std::endl;
}

