#pragma once

template <typename T>
int partition(T *arr, int low, int high)
{
    T pivot = arr[high];
    int i = low;

    for (int j = low; j < high; ++j)
    {
        if (arr[j] <= pivot)
        {
            swap(arr[i], arr[j]);
            ++i;
        }
    }

    swap(arr[i], arr[high]);
    return i;
}

template <typename T>
void quick_sort_impl(T *arr, int low, int high)
{
    if (low < high)
    {
        int pivot_idx = partition(arr, low, high);

        quick_sort_impl(arr, low, pivot_idx - 1);
        quick_sort_impl(arr, pivot_idx + 1, high);
    }
}

template <typename T>
T *quick_sort(T *original, int length)
{
    T *sorted = new T[length];

    for (int i = 0; i < length; i++)
    {
        sorted[i] = original[i];
    }

    quick_sort_impl(sorted, 0, length - 1);

    return sorted;
}
