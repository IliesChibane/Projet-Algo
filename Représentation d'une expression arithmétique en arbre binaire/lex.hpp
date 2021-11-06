#ifndef LEX_HPP_
#define LEX_HPP_

#include <string>
#include <iostream>
#include <vector>

enum class entity_type {
    number,
    operation,
    parenthesis
};

enum class operation_type {
    add,
    sub,
    mul,
    div,
    mod
};

enum class parenthesis_type {
    open,
    close
};

class entity {
    public:
        entity_type type;
        union {
            long double number;
            operation_type operation;
            parenthesis_type parenthesis;
        } value;

        friend std::ostream& operator<<(std::ostream& stream, const entity& entity);
};

std::vector<entity> string_to_entities(const std::string &expression);

#endif
