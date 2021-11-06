template <class T>
binary_tree<T>::binary_tree() : root_{nullptr} {
}

template <class T>
binary_tree<T>::~binary_tree() {
    destructTree(root_);
}

template <class T>
void binary_tree<T>::destruct_tree(node perform_lexical_analysis*node) {
    if (node != nullptr) {
        destruct_tree(node->left);
        destruct_tree(node->right);
        delete node;
    }
}
