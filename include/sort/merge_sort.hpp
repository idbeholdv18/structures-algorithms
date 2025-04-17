#pragma once

template <typename T>
void merge(T *arr, int l, int m, int r)
{
    const int l_length = m - l + 1;
    const int r_length = r - m;

    T *l_buff = new T[l_length];
    T *r_buff = new T[r_length];

    for (int i = 0; i < l_length; i++)
    {
        l_buff[i] = arr[l + i];
    }

    for (int i = 0; i < r_length; i++)
    {
        r_buff[i] = arr[i + m + 1];
    }

    int l_idx = 0;
    int r_idx = 0;
    int arr_idx = l;

    while (l_idx < l_length && r_idx < r_length)
    {
        if (l_buff[l_idx] <= r_buff[r_idx])
        {
            arr[arr_idx] = l_buff[l_idx];
            l_idx++;
        }
        else
        {
            arr[arr_idx] = r_buff[r_idx];
            r_idx++;
        }
        arr_idx++;
    }

    while (l_idx < l_length)
    {
        arr[arr_idx] = l_buff[l_idx];
        l_idx++;
        arr_idx++;
    }

    while (r_idx < r_length)
    {
        arr[arr_idx] = r_buff[r_idx];
        r_idx++;
        arr_idx++;
    }

    delete[] l_buff;
    delete[] r_buff;
}

template <typename T>
void merge_sort_impl(T *arr, int l, int r)
{
    if (l < r)
    {
        int m = l + (r - l) / 2;

        merge_sort_impl(arr, l, m);
        merge_sort_impl(arr, m + 1, r);

        merge(arr, l, m, r);
    }
}

template <typename T>
T *merge_sort(const T *original, const int length)
{
    T *sorted = new T[length];

    for (int i = 0; i < length; i++)
    {
        sorted[i] = original[i];
    }

    merge_sort_impl(sorted, 0, length - 1);

    return sorted;
}