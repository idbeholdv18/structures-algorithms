#include <iostream>
#include <string>
#include "sort/bubble_sort.hpp"
#include "sort/shaker_sort.hpp"
#include "sort/insertion_sort.hpp"
#include "sort/selection_sort.hpp"
#include "sort/quick_sort.hpp"
#include "sort/merge_sort.hpp"
#include "sort/shared/print.hpp"
#include "linked_list/linked_list.hpp"
#include "binary_tree/binary_tree.hpp"
#include <fstream>

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

    // quick sort
    int *merge_sorted = merge_sort(numbers, ARR_LENGTH);
    cout << "merge sort: ";
    print(merge_sorted, ARR_LENGTH);
    delete[] merge_sorted;

    // linked list
    auto list = std::make_unique<linked_list::LinkedList<int>>();
    list
        ->push(1)
        .push(2)
        .push(3)
        .push(4)
        .push(5)
        .unshift(0)
        .unshift(9)
        .shift()
        .pop();

    cout << "All nodes: ";
    list->forEach([](const int &value)
                  { cout << value << " "; });
    cout << "\n";

    list->forEach([](int &value)
                  { value *= 2; });

    cout << "Multiplied: ";
    list->forEach([](const int &value)
                  { cout << value << " "; });
    cout << "\n";

    auto string_list = list->map<string>([](const int &v)
                                         { return string("val#") + to_string(v); });

    cout << "new string list: ";
    string_list.forEach([](const string &s)
                        { cout << s << " "; });
    cout << "\n";

    // binary tree

    binary_tree::Tree<int> tree;
    tree.add(8).add(6).add(1).add(9).add(3).add(0).add(4).add(5).add(2).add(7);

    std::cout << "Preorder: ";
    tree.dsfPreorder();

    std::cout << "Inorder: ";
    tree.dsfInorder();

    std::cout << "Postorder: ";
    tree.dsfPostorder();

    std::ofstream file("tree.dot");
    tree.exportToDot(file);
    file.close();

    std::cout << "DOT файл сохранён: tree.dot\nCheck out: https://dreampuf.github.io/GraphvizOnline/";
    return 0;
}