#pragma once
#include <iostream>
#include "tools.hpp"

using namespace tools;

namespace sorting
{
    auto bubble(Value *array, Size size, bool direction) -> void;
    auto bubble_extra(Value *array, Size size, bool direction) -> void;

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