#pragma once
#include <iostream>
#include "tools.hpp"

using namespace tools;

namespace sorting
{
    auto bubble(Value *array, Size size, bool direction) -> void;
    auto bubble_extra(Value *array, Size size, bool direction) -> void;
    
    auto merge_sort(Value *array, Index n) -> void;
    auto merge_sort_extra(Value *array, Index n) -> void;
    auto split(Value *const array, Size n) -> Value*;

    auto merge(Value* l, Value* r, Index n) -> void;

} // namespace sorting

auto sorting::bubble(Value *array, Size size, bool direction) -> void
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size - 1; j++)
        {
            if (direction)
            {
                if (array[j] > array[j + 1])
                {
                    swap(array, j, j + 1);
                }
            }
            else
            {
                if (array[j] < array[j + 1])
                {
                    swap(array, j, j + 1);
                }
            }
        }
    }
}
auto sorting::bubble_extra(Value *array, Size size, bool direction) -> void
{
    bool sup_dir = true;
    int stop = size;
    for (int i = 0; i < size / 2; i++)
    {
        if (sup_dir)
        {
            int min = array[i];
            int index_min = i;
            for (int j = i + 1; j <= stop; j++)
            {
                if (array[j] < min)
                {
                    min = array[j];
                    index_min = j;
                }
            }
            if (i != index_min)
            {
                swap(array, i, index_min);
            }
        }
        else
        {
            int max = array[stop];
            int index_max = stop;
            for (int j = stop - 1; j >= i; j--)
            {
                if (array[j] > max)
                {
                    max = array[j];
                    index_max = j;
                }
            }
            if (stop != index_max)
            {
                swap(array, stop, index_max);
            }
            stop--;
            i--;
        }
        sup_dir = !sup_dir;
    }

    /*for (int k = 0; k < size; k++)
    {
        bool sup_dir = true;
        int first_stop = size/2;
        int second_stop = size;
        for (int i = 0; i < first_stop; i++){
            if (sup_dir){
                for (int j = i; j < second_stop-1; j++){
                    if(array[j] > array[j+1]){
                        swap(array, j, j+1);
                       }
                }
            } else{
                for (int j = second_stop; j > i+1; j--){
                    if(array[j] < array[j-1]){
                        swap(array, j, j-1);
                       }

                }
                second_stop--;
            }
            sup_dir = !sup_dir;

        }
    }*/

    //[0]--->>>[10] [1]<<<---[10] [1]--->>[9] ....
}
auto sorting::merge_sort(Value *array, Index n) -> void{
    Value *mid = split(array, n);

    if (n > 1)
    {
        Index m = mid - array + 1;
        merge_sort(array, m); 
        merge_sort(mid + 1, n - m);
    }
    merge(array, mid+1, n);
}
auto sorting::split(Value *const array, Size n) -> Value*{
    return array + (n + 1) / 2 - 1;
}
auto sorting::merge(Value* l, Value* r, Index n) -> void{
    Value* tmp = new Value[n];
    Index m = r - l;
    Index i , j;
    for (i = 0, j = 0;(i < m) && (j < n - m);){
        if(l[i] < r[j]){
            tmp[i+j] = l[i];
            i++;
        } else{
            tmp[i+j] = r[j];
            j++;
        }
    }
    for ( ; i < m; i++)
    {
        tmp[i+j] = l[i];
    }
    for (; j < n - m; j++)
    {
        tmp[i+j] = r[j];
    }
    for (Index k = 0; k < n; k++)
    {
        l[k] = tmp[k];
    }

    delete[] tmp;
    return;
}
