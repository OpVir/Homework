#pragma once
#include <iostream>

namespace tools
{
    using Value = int;
    using Size = int;
    using Index = int;

    struct Result
    {
        Value result;
        Index index;
    };

    auto swap(Value *array, Index first, Index second) -> void;

    auto term(Value *const array, Size const size) -> void;

    auto max(Value *array, Index begin, Index end) -> Result;

    auto min(Value *array, Index begin, Index end) -> Result;
}
auto tools::swap(Value *array, Index first, Index second) -> void
{
    Value buf = array[second];
    array[second] = array[first];
    array[first] = buf;
}
auto tools::term(Value *const array, Size const size) -> void
{
    for (int i = 0; i < size; i++)
    {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;
}
auto tools::max(Value *array, Index begin, Index end) -> Result
{
    int result = array[begin];
    int index = begin;
    for (int j = begin; j <= end; j++)
    {
        if (array[j] > result)
        {
            result = array[j];
            index = j;
        }
    }

    return {result, index};
}
auto tools::min(Value *array, Index begin, Index end) -> Result
{
    int result = array[begin];
    int index = begin;
    for (int j = begin; j <= end; j++)
    {
        if (array[j] < result)
        {
            result = array[j];
            index = j;
        }
    }

    return {result, index};
}
