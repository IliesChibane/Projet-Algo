#include "lex.hpp"
#include "tree.hpp"
#include "sem.hpp"

/*  Grammaire:
 *  Z --> E #
 *  E --> T + { T }* | T - { T }*
 *  T --> F x { F }* | F / { F }*
 *  F --> nb | ( E ) | - F
 */

binary_tree<entity> entities_to_binary_tree(const std::vector<entity>& entities) {
    int ct = 0;
    if (entities.size() == 0) 
        throw 1;
    binary_tree<entity> bt = e(entities, ct);
    if (ct < entities.size())
        throw 1;
    
    return bt;
}

// Routine pour reconnaitre les expressions : gère les opérations + et -
binary_tree<entity> e(const std::vector<entity>& entities, int& ct) {
    binary_tree<entity> bt, rt, lt;
    try {
        // Premier opérande
        bt = t(entities, ct);
        while (ct < entities.size() && 
                entities[ct].type == entity_type::operation &&
                (entities[ct].value.operation == operation_type::add ||
                entities[ct].value.operation == operation_type::sub)) {
            entity op = entities[ct];
            lt = bt;
            ct = ct + 1;
            if (ct >= entities.size())
                throw 1;

            // Deuxième opérande
            rt = t(entities, ct);

            // Construction du noeud d'opération
            bt.set_root(op);
            bt.set_left(lt);
            bt.set_right(rt);
        }
    } catch (int e) {
        throw e;
    }
    return bt;
}

// Routine pour reconnaitre les termes : gène les opérations de *, / et %
binary_tree<entity> t(const std::vector<entity>& entities, int& ct) {
    binary_tree<entity> bt, rt, lt;
    try {
        // Premier opérande
        bt = f(entities, ct);
        while (ct < entities.size() &&
                entities[ct].type == entity_type::operation &&
                (entities[ct].value.operation == operation_type::mul ||
                entities[ct].value.operation == operation_type::div ||
                entities[ct].value.operation == operation_type::mod)) {
            entity op = entities[ct];
            lt = bt;
            ct = ct + 1;
            if (ct >= entities.size())
                throw 1;

            // Deuxième opérande
            rt = f(entities, ct);

            // Construction du noeud d'opération
            bt.set_root(op);
            bt.set_left(lt);
            bt.set_right(rt);
        }
    } catch (int e) {
        throw e;
    }
    return bt;
}

// Routine pour reconnaitre les entités, les parenthèses et les signes
binary_tree<entity> f(const std::vector<entity>& entities, int& ct) {
    binary_tree<entity> bt, rt, lt;
    // Cas de parenthèses
    if (entities[ct].type == entity_type::parenthesis &&
            entities[ct].value.parenthesis == parenthesis_type::open) {
        // Lecture de la première parenthèse ouvrante
        ct = ct + 1;
        if (ct >= entities.size())
            throw 1;
        // Passage à l'expression englobée par les parenthèses
        bt = e(entities, ct);
        // Lectures de la deuxième parenthèse fermante
        if (ct < entities.size() &&
            entities[ct].type == entity_type::parenthesis &&
            entities[ct].value.parenthesis == parenthesis_type::close) {
            ct = ct + 1;
        } else {
            throw 1;
        }
    // Cas d'un signe
    } else if (entities[ct].type == entity_type::operation &&
                (entities[ct].value.operation == operation_type::sub ||
                entities[ct].value.operation == operation_type::add)) {
        // Construction d'un noeud (0 <signe> opérande)
        entity op = entities[ct];

        entity left;
        left.type = entity_type::number;
        left.value.number = 0;

        ct = ct + 1;
        if (ct >= entities.size())
            throw 1;

        rt = f(entities, ct);
        lt.set_root(left);

        bt.set_root(op);
        bt.set_left(lt);
        bt.set_right(rt);
    // Cas d'un nombre
    } else {
        // Création d'une feuille contenant le nombre
        entity e = entities[ct];
        bt.set_root(e);
        ct = ct + 1;
    }
    return bt;
}

