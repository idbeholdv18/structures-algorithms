#pragma once

namespace binary_tree
{
    template <typename T>
    struct Node
    {
        T m_data;
        Node *left;
        Node *right;

        Node(T data) : m_data(data), left(nullptr), right(nullptr) {}
    };
}