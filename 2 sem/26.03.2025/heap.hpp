#pragma once

#include "tools.hpp"

namespace hs {
    using tools::Value, tools::Index, tools::swap;

    void sort(Value* a, Index n);
    void heapMax(Value* a, Index n, Index i);
}

void hs::sort(Value* a, Index n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapMax(a, n, i);
    }

    for (int i = n - 1; i > 0; i--) {
        swap(a, 0, i);
        heapMax(a, i, 0);
    }
}

void hs::heapMax(Value* a, Index n, Index i) {
    Index current = i;
    
    while (true) {
        Index largest = current;
        Index left = 2 * current + 1;
        Index right = 2 * current + 2;

        if (left < n && a[left] > a[largest]) {
            largest = left;
        }

        if (right < n && a[right] > a[largest]) {
            largest = right;
        }

        if (largest == current) {
            break;
        }

        swap(a, current, largest);
        current = largest;
    }
}