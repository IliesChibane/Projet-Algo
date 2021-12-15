// Constructeur par défaut
template <class T>
binary_tree<T>::binary_tree() : root_{nullptr} {
}

// Constructeur
template <class T>
binary_tree<T>::binary_tree(binary_tree<T>& lt, binary_tree<T>& rt, T& value) 
    : root_{new node<T>} {
        root_->value = value;
        set_left(lt);
        set_right(rt);
}

// Initialise la racine de l'arbre
template <class T>
void binary_tree<T>::set_root(const T& value) {
    root_ = new node<T>;
    root_->left = nullptr;
    root_->right = nullptr;
    root_->value = value;
}

// Initialise le fils gauche
template <class T>
void binary_tree<T>::set_left(binary_tree<T>& tree) {
    if (root_ != nullptr) 
        root_->left = tree.root_;
}

// Initialise le fils droit 
template <class T>
void binary_tree<T>::set_right(binary_tree<T>& tree) {
    if (root_ != nullptr)
        root_->right = tree.root_;
}

// Affiche un noeud de l'arbre et ses fils récursivement
template <class T>
void binary_tree<T>::print(const std::string& prefix, node<T> *node, bool is_left) {
    if (node != nullptr) {
        std::cout << prefix;
        std::cout << (is_left ? "├──" : "└──" );

        // Affichage du noeud courant
        std::cout << node->value << std::endl;

        // Affichage des noeuds fils
        print(prefix + (is_left ? "│   " : "    "), node->left, true);
        print(prefix + (is_left ? "│   " : "    "), node->right, false);
    }
}

// Affiche l'arbre
template <class T>
void binary_tree<T>::print_tree() {
    print("", root_, false);
}
