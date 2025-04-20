#include <iostream>

int* createMemo(int size) {
    int* memo = new int[size];
    for (int i = 0; i < size; ++i) {
        memo[i] = -1;
    }
    return memo;
}

void deleteMemo(int* memo) {
    delete[] memo;
}

int fibonacciMemo(int n, int* memo) {
    if (n <= 1) return n;
    if (memo[n] != -1) return memo[n];
    memo[n] = fibonacciMemo(n - 1, memo) + fibonacciMemo(n - 2, memo);
    return memo[n];
}
