#pragma once

#include "sort/shared/swap.hpp"

template <typename T>
T *selection_sort(T *original, int length)
{
    T *sorted = new T[length];

    // cp original arr
    for (int i = 0; i < length; i++)
    {
        sorted[i] = original[i];
    }

    for (int i = 0; i < length - 1; i++)
    {
        int min_idx = i;
        for (int k = i + 1; k < length; k++)
        {
            if (sorted[k] < sorted[min_idx])
                min_idx = k;
        }
        if (min_idx != i)
        {
            swap(sorted[i], sorted[min_idx]);
        }
    }

    return sorted;
}