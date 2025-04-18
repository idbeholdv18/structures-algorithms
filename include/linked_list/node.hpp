#pragma once

namespace linked_list
{
    template <typename T>
    struct Node
    {
        T m_data;
        Node *next;
        Node *prev;

        Node(T data) : m_data(data), next(nullptr), prev(nullptr) {}
    };
}