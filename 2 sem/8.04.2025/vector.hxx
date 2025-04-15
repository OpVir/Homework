#pragma once
#include <iostream>
#include "tools.hxx"

namespace vec
{
    using namespace tls;

    struct vector
    {
        Value *array = nullptr;
        Index size = 0;
    };

    auto resize(vector &v, Size size) -> void;
    auto remove(vector &v) -> void;
    auto fill(vector& v) -> void;
    auto output(vector const& v) -> void;
}

auto vec::resize(vector &v, Size size) -> void{
    remove(v);
    v.array = new Value[size];
    v.size = size;
}

auto vec::remove(vector &v) -> void{
    if (v.size != 0){
        delete[] v.array;
        v.size = 0;
    }
}

auto vec::fill(vector& v) -> void{
    for (Index i = 0; i < v.size; i++)
    { 
        v.array[i] = i*i;
    }
}
auto vec::output(vector const& v) -> void{
    for (Index i = 0; i < v.size; i++)
    { 
        std::cout << v.array[i] << ' ';
    }
    std::cout<<std::endl;
}