#ifndef TREE_HPP_
#define TREE_HPP_

#include <iostream>

template <class T>
struct node {
    T value;
    node<T>* left;
    node<T>* right;
};

template <class T>
class binary_tree{
    private:
        node<T>* root_;

        void print(const std::string& prefix, node<T> *node, bool is_left);

    public:
        binary_tree();
        binary_tree(binary_tree<T>& lt, binary_tree<T>& rt, T& value);
        void set_root(const T& value);
        void set_left(binary_tree<T>& tree);
        void set_right(binary_tree<T>& tree);
        void print_tree();
};

#include "tree.tcc"

#endif
