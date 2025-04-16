#include <iostream>
#include "sort/bubble_sort.hpp"
#include "sort/shared/print.hpp"

using namespace std;

int main() {
    const int ARR_LENGTH = 10;
    int numbers[ARR_LENGTH]{8, 6, 1, 9, 3, 0, 4, 5, 2, 7};

    int * sorted = bubble_sort(numbers, ARR_LENGTH);

    print(numbers, ARR_LENGTH);
    print(sorted, ARR_LENGTH);
    
    delete[] sorted;
    return 0;
}