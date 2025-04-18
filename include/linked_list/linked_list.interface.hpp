#pragma once

namespace linked_list
{
    template <typename T>
    class ILinkedList
    {
    public:
        virtual ~ILinkedList() = default;

        virtual ILinkedList<T>& push(T data) = 0;
        virtual ILinkedList<T>& pop() = 0;
        // virtual ILinkedList<T>& unshift(T data) = 0;
        // virtual ILinkedList<T>& shift() = 0;
        virtual ILinkedList<T>& clear() = 0;

        virtual ILinkedList<T>& forEach(const std::function<void(T&)>& func) = 0;
        virtual void forEach(const std::function<void(const T&)>& func) const = 0;
    };
}