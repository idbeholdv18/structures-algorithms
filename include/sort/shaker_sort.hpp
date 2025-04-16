#include "sort/shared/swap.hpp"

template <typename T>
T *shaker_sort(const T *original, int length)
{
    T *sorted = new T[length];

    // cp original arr
    for (int i = 0; i < length; i++)
    {
        sorted[i] = original[i];
    }

    int left = 0;
    int right = length - 1;
    bool swapped = true;
    while (swapped)
    {
        swapped = false;

        for (int i = right; i > left; --i)
        {
            if (sorted[i] < sorted[i - 1])
            {
                swap(sorted[i], sorted[i - 1]);
                swapped = true;
            }
        }
        ++left;

        for (int i = left; i < right; ++i)
        {
            if (sorted[i] > sorted[i + 1])
            {
                swap(sorted[i], sorted[i + 1]);
                swapped = true;
            }
        }
        --right;
    }

    return sorted;
}