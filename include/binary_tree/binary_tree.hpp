#pragma once

#include "binary_tree/node.hpp"
#include "binary_tree/binary_tree.interface.hpp"
#include <functional>
#include <iostream>

namespace binary_tree
{
    template <typename T>
    class Tree : public ITree<T>
    {
    private:
        Node<T> *_root;
        std::less<T> _compare;

        void _exportDotRecursive(Node<T>* node, std::ostream& out) {
            if (!node) return;
        
            if (node->left) {
                out << "    \"" << node->m_data << "\" -> \"" << node->left->m_data << "\";\n";
                _exportDotRecursive(node->left, out);
            }
            if (node->right) {
                out << "    \"" << node->m_data << "\" -> \"" << node->right->m_data << "\";\n";
                _exportDotRecursive(node->right, out);
            }
        }

        void _preorderTraversal(Node<T> *node)
        {
            if (!node)
                return;
            std::cout << node->m_data << " ";
            _preorderTraversal(node->left);
            _preorderTraversal(node->right);
        }

        void _clearRecursive(Node<T> *&node)
        {
            if (!node)
                return;
            _clearRecursive(node->left);
            _clearRecursive(node->right);
            delete node;
            node = nullptr;
        }

        Node<T> *_insertRecursive(Node<T> *node, T data)
        {
            if (!node)
                return new Node<T>(data);

            if (_compare(data, node->m_data))
            {
                node->left = _insertRecursive(node->left, data);
            }
            else
            {
                node->right = _insertRecursive(node->right, data);
            }

            return node;
        }

    public:
        Tree() : _root(nullptr) {}
        ~Tree()
        {
            clear();
        }

        ITree<T> &add(T data) override
        {
            _root = _insertRecursive(_root, data);
            return *this;
        }

        ITree<T> &clear() override
        {
            _clearRecursive(_root);
            return *this;
        }

        void dsfPreorder() override
        {
            _preorderTraversal(_root);
            std::cout << std::endl;
        }

        void exportToDot(std::ostream& out) override {
            out << "digraph BinaryTree {\n";
            _exportDotRecursive(_root, out);
            out << "}\n";
        }
    };
}