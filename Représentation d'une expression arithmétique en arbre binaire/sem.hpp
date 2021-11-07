#ifndef SEM_HPP_
#define SEM_HPP_

#include "lex.hpp"
#include "tree.hpp"

binary_tree<entity> entities_to_binary_tree(const std::vector<entity> entities);

binary_tree<entity> e(const std::vector<entity>, int& ct);
binary_tree<entity> t(const std::vector<entity>, int& ct);
binary_tree<entity> f(const std::vector<entity>, int& ct);

#endif
