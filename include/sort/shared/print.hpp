#include <iostream>

template <typename T>
void print(const T * array, int length) {
    using std::cout;
    for (int i = 0; i < length; i++) {
        cout << array[i] << " ";
    }
    cout << "\n";
}