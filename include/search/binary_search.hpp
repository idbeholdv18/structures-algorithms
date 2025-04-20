#pragma once

#include <stddef.h>

using namespace std;

template <typename T>
int binary_search(const T *original, size_t length, T target)
{
    int start = 0;
    int end = length - 1;

    while (start <= end)
    {
        int mid = start + (end - start) / 2;

        if (original[mid] < target)
        {
            start = mid + 1;
        }
        else if (original[mid] > target)
        {
            end = mid - 1;
        }
        else
            return mid;
    }

    return -1;
}