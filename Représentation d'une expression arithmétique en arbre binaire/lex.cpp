#include <string>
#include <vector>
#include <iostream>

#include "lex.hpp"


std::vector<entity> string_to_entities(const std::string &expression) {
    std::vector<entity> entities; 

    // could use regex tho ...
    for (int i = 0; i < expression.size(); i++) {
        entity e;
        // Cas d'un operateur
        if (expression[i] == '+') {
            e.type = entity_type::operation;
            e.value.operation = operation_type::add;
            entities.push_back(e);
        } else if (expression[i] == '-') {
            e.type = entity_type::operation;
            e.value.operation = operation_type::sub;
            entities.push_back(e);
        } else if (expression[i] == '*') {
            e.type = entity_type::operation;
            e.value.operation = operation_type::mul;
            entities.push_back(e);
        } else if (expression[i] == '/') {
            e.type = entity_type::operation;
            e.value.operation = operation_type::div;
            entities.push_back(e);
        } else if (expression[i] == '%') {
            e.type = entity_type::operation;
            e.value.operation = operation_type::mod;
            entities.push_back(e);

        // Cas de parenthèses
        } else if (expression[i] == '(') {
            e.type = entity_type::parenthesis;
            e.value.parenthesis = parenthesis_type::open;
            entities.push_back(e);
        } else if (expression[i] == ')') {
            e.type = entity_type::parenthesis;
            e.value.parenthesis = parenthesis_type::close;
            entities.push_back(e);

        // Cas d'un nombre
        } else if (isdigit(expression[i]) || expression[i] == '.') {
            int j = 1;
            while (i + j < expression.size() && 
                    (isdigit(expression[i + j]) || expression[i + j] == '.'))
                j++;

            e.type = entity_type::number;
            e.value.number = std::stold(expression.substr(i, j));

            entities.push_back(e);
            i = i + j - 1;
        // Cas d'un blanc
        } else if (expression[i] == ' ') {
            continue;
        } else {
            throw 1;
        }
    }

    return entities;
}

entity::entity() {
}

// Affichage d'une entité
std::ostream& operator<<(std::ostream& stream, const entity& entity) {
    if (entity.type == entity_type::number) {
        stream << "[type: number, value: " << entity.value.number << "]";
    } else if (entity.type == entity_type::operation) {
        stream << "[type: operation, value: ";
        switch (entity.value.operation) {
            case operation_type::add:
                stream << "addition]";
                break;
            case operation_type::sub:
                stream << "subtraction]";
                break;
            case operation_type::mul:
                stream << "multiplication]";
                break;
            case operation_type::div:
                stream << "division]";
                break;
            case operation_type::mod:
                stream << "modulo]";
                break;
            default:
                break;
        }
    } else {
        stream << "[type: parenthesis, value: ";
        switch (entity.value.parenthesis) {
            case parenthesis_type::open:
                stream << "open]";
                break;
            case parenthesis_type::close:
                stream << "close]";
                break;
            default:
                break;
        }
    }
    return stream;
}

