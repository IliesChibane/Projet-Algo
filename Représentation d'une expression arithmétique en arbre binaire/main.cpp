#include <iostream>
#include <vector>
#include <string>
#include <chrono>

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
    std::cout << "entrez l'expression : ";
    std::getline(std::cin, expression);
    std::cout << "expression: " << expression << std::endl << std::endl;

    std::vector<entity> entities;
    binary_tree<entity> bt;


    std::chrono::time_point<std::chrono::steady_clock> start = std::chrono::steady_clock::now(), stop;
    try {
        // Génération des entités lexicales
        entities = string_to_entities(expression);
        /*std::cout << "entités lexicales : ";
        for (int i = 0; i < entities.size(); i++)
            std::cout << entities[i] << " ";
        std::cout << std::endl << std::endl;*/
    } catch (int e) {
        std::cout << "Erreur lexicale" << std::endl;
        return 1;
    }

    try {
        // Génération de l'arbre syntaxique
        bt = entities_to_binary_tree(entities); 
        stop = std::chrono::steady_clock::now(); 
        //bt.print_tree();
    } catch (int e) {
        std::cout << "Erreur syntaxique" << std::endl;
        return 1;
    }

    std::chrono::duration<double, std::nano> duration = stop - start;
    std::cout << "temps = " << duration.count() << "ns" << std::endl;

    return 0;
}
