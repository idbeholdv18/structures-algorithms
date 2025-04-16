#include "sort/shared/swap.hpp"

template<typename T>
T * bubble_sort(const T * original, int length) {
    T * sorted = new T[length];
    
    // cp original arr
    for (int i = 0; i < length; ++i) {
        sorted[i] = original[i];
    }

    for (int i = 0; i < length - 1; ++i) {
        for (int j = 0; j < length - i - 1; ++j) {
            if (sorted[j] > sorted[j + 1]) {
                swap(sorted[j], sorted[j + 1]);
            }
        }
    }

    return sorted;
}