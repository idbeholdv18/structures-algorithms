#pragma once

namespace binary_tree
{
    template <typename T>
    class ITree
    {
    public:
        virtual ITree<T> &add(T data) = 0;
        virtual void dsfPreorder() = 0;
        virtual void dsfInorder() = 0;
        virtual void dsfPostorder() = 0;
        virtual Node<T> * search(const T data) = 0;
        virtual void bfs() = 0;
        virtual ITree<T> &clear() = 0;
        virtual ~ITree() = default;
        virtual void exportToDot(std::ostream& out) = 0;
    };
}