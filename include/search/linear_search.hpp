#pragma once

#include <cstddef>

using namespace std;

template <typename T>
int linear_search(const T *original, size_t length, T target)
{
    for (size_t i = 0; i < length; i++)
    {
        if (original[i] == target)
            return i;
    }
    return -1;
}