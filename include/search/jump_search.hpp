#pragma once

#include <stddef.h>
#include <cmath>

using namespace std;

template <typename T>
int jump_search(const T * original, size_t length, T target) {
    size_t blockSize = sqrt(length);
    size_t start = 0;
    size_t next = blockSize;

    while (start < length && original[min(next, length) - 1] < target) {
        start = next;
        next += blockSize;
        if (start >= length) return -1;
    }

    for (size_t i = start; i < min(next, length); ++i) {
        if (original[i] == target) return i;
    }

    return -1;
}