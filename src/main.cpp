#include <iostream>
#include "sort/bubble_sort.hpp"
#include "sort/shaker_sort.hpp"
#include "sort/insertion_sort.hpp"
#include "sort/selection_sort.hpp"
#include "sort/quick_sort.hpp"
#include "sort/shared/print.hpp"

using namespace std;

int main()
{
    const int ARR_LENGTH = 10;
    int numbers[ARR_LENGTH]{8, 6, 1, 9, 3, 0, 4, 5, 2, 7};
    print(numbers, ARR_LENGTH);

    // bubble sort
    int *bubble_sorted = bubble_sort(numbers, ARR_LENGTH);
    cout << "bubble sort: ";
    print(bubble_sorted, ARR_LENGTH);
    delete[] bubble_sorted;

    // shaker sort
    int *shaker_sorted = shaker_sort(numbers, ARR_LENGTH);
    cout << "shaker sort: ";
    print(shaker_sorted, ARR_LENGTH);
    delete[] shaker_sorted;

    // insertion sort
    int *insertion_sorted = insertion_sort(numbers, ARR_LENGTH);
    cout << "insertion sort: ";
    print(insertion_sorted, ARR_LENGTH);
    delete[] insertion_sorted;

    // selection sort
    int *selection_sorted = selection_sort(numbers, ARR_LENGTH);
    cout << "selection sort: ";
    print(selection_sorted, ARR_LENGTH);
    delete[] selection_sorted;

    // quick sort
    int *quick_sorted = quick_sort(numbers, ARR_LENGTH);
    cout << "quick sort: ";
    print(quick_sorted, ARR_LENGTH);
    delete[] quick_sorted;

    return 0;
}