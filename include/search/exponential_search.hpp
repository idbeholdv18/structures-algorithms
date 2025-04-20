#pragma once

#include <stddef.h>
#include <cmath>

using namespace std;

template <typename T>
int exponential_search(const T * original, size_t length, T target) {
    if (length == 0) return -1;

    if (original[0] == target) return 0;

    size_t bound = 1;

    while (bound < length && original[bound] < target) bound *= 2;

    size_t left = bound / 2;
    size_t right = min(bound, length - 1);

    while (left <= right)
    {
        size_t mid = left + (right - left) / 2;

        if (original[mid] < target)
            left = mid + 1;
        else if (original[mid] > target)
            right = mid - 1;
        else
            return mid;
    }

    return -1;
}