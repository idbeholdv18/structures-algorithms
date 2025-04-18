#pragma once

#include "linked_list/node.hpp"
#include "linked_list/linked_list.interface.hpp"
#include <functional>

namespace linked_list
{
    template <typename T>
    class LinkedList : public ILinkedList<T>
    {
    protected:
        Node<T> *_head;
        Node<T> *_tail;
        int _length;

    public:
        LinkedList()
            : _head(nullptr), _tail(nullptr), _length(0) {}
        ~LinkedList()
        {
            clear();
        }

        ILinkedList<T> &push(T data) override
        {
            Node<T> *newNode = new Node<T>(data);
            if (!_head)
            {
                _head = _tail = newNode;
            }
            else
            {
                _tail->next = newNode;
                newNode->prev = _tail;
                _tail = newNode;
            }
            _length++;
            return *this;
        };
        ILinkedList<T> &pop() override
        {
            if (!_head)
                return *this;

            if (_head == _tail)
            {
                delete _head;
                _head = _tail = nullptr;
            }
            else
            {
                Node<T> *newTail = _tail->prev;
                newTail->next = nullptr;
                delete _tail;
                _tail = newTail;
            }

            _length--;
            return *this;
        };
        // ILinkedList<T> &unshift(T data) override;
        // ILinkedList<T> &shift() override;
        ILinkedList<T> &forEach(const std::function<void(T &)> &func) override
        {
            Node<T> *current = _head;
            while (current)
            {
                func(current->m_data);
                current = current->next;
            }
            return *this;
        };
        void forEach(const std::function<void(const T &)> &func) const override
        {
            Node<T> *current = _head;
            while (current)
            {
                func(current->m_data);
                current = current->next;
            }
        };

        template <typename U>
        LinkedList<U> map(const std::function<U(const T &)> &func) const
        {
            LinkedList<U> newList;
            for (auto current = _head; current; current = current->next)
            {
                newList.push(func(current->m_data));
            }
            return newList;
        };

        ILinkedList<T> &clear() override
        {
            Node<T> *current = _head;
            while (current)
            {
                Node<T> *next = current->next;
                delete current;
                current = next;
            }
            _head = _tail = nullptr;
            _length = 0;
            return *this;
        };
    };
}
