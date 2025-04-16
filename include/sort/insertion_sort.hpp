#pragma once

template <typename T>
T *insertion_sort(T *original, int length)
{
    T *sorted = new T[length];

    for (int i = 0; i < length; i++)
    {
        sorted[i] = original[i];
    }

    for (int i = 1; i < length; i++)
    {
        T key = sorted[i];
        int k = i - 1;
        while (k >= 0 && sorted[k] > key)
        {
            sorted[k + 1] = sorted[k];
            --k;
        }
        sorted[k + 1] = key;
    }

    return sorted;
}