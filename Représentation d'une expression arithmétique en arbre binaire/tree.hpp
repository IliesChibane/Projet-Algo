#ifndef TREE_HPP_
#define TREE_HPP_

template <class T>
struct node {
    T value;
    node* left;
    node* right;
}

template <class T>
class binary_tree{
    private:
        node* root_;

        void destruct_tree(node *node);

    public:
        binary_tree();
        ~binary_tree();
}

#include "tree.tcc"

#endif
