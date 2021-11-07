#include <iostream>
#include <vector>
#include <string>

#include "lex.hpp"
#include "tree.hpp"
#include "sem.hpp"

/*  Représentation d'une expression arithmétique en arbre binaire
 *  -------------------------------------------------------------
 *
 *  Entrée : Expression arithmétique sous forme d'une chaîne de caractères.
 *  Sortie : Une représentation en arbre binaire de l'expression arithmétique.
 *
 *  Détails de l'algorithme
 *  -----------------------
 *
 *  Le traitement de la chaîne passe par les étapes suivantes :
 *      - Analyse lexicale : à l'issue de laquelle on génére les entités 
 *      lexicales.
 *      - Analyse syntaxico-sémantique par descente récursive : Où le 
 *      séquencement d'entités lexicales est transformé en arbre binaire.
 *
 *      expression --<analyse lexicale>--> tableau d'entités 
 *                          --<analyse syntaxico-sémantique>--> arbre binaire
 */

int main(int argc, char **argv) {
    // Lecture de l'expression arithmétique
    std::string expression;
    std::getline(std::cin, expression);
    std::cout << "expression: " << expression << std::endl << std::endl;

    // Génération des entités lexicales
    std::vector<entity> entities = string_to_entities(expression);
    std::cout << "entités lexicales : ";
    for (int i = 0; i < entities.size(); i++)
        std::cout << entities[i] << " ";
    std::cout << std::endl << std::endl;

    // Génération de l'arbre syntaxique
    binary_tree<entity> bt = entities_to_binary_tree(entities); 
    bt.print_tree();

    return 0;
}
