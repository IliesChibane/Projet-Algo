#include "tree.hpp"
#include<chrono>

//Recherche d'un element dans un arbre binaire 
using namespace std;

void chercher_element(struct element* &element_cherche, int val, struct element* &element){ // passage par référence pour changer la valeur de element_cherche avec l'element trouvé.
    while(element_cherche && element_cherche->valeur != val){
        element = element_cherche;

        if(val < element_cherche->valeur)
            element_cherche = element_cherche->gauche;
        else
            element_cherche = element_cherche->droit;
    }
}

//Recherche de la valeur minimale dans un arbre, utile pour la suppression d'un element avec deux fils.

struct element* valeur_minimale(struct element* elt){
    struct element* min = elt;
    while(min && min->gauche != nullptr)
        min=min->gauche;
    return min;
}
/***
 * SUPPRESSION SIMPLE ET RECURSIVE
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * ***/
//suppression d'un element dans un arbre binaire 
struct element* supprimer_element_recursive(struct element* racine, int val){ //premier essai, pas très optimisé.
   
    if(racine==nullptr) //cas de base pour la récursivité
        return racine; 

    if(val < racine->valeur)  //si la val a supprimer est inf à la valeur de l'elt alors on va supprimer à gauche.
        racine->gauche = supprimer_element_recursive(racine->gauche,val);

    else if(val > racine->valeur)  //si la val a supprimer est inf à la valeur de l'elt alors on va supprimer à droite.
        racine->droit = supprimer_element_recursive(racine->droit,val);

    else{ //si val == racine->valeur (on a trouvé l'elt à supprimer)

        //si l'elt n'a aucun fils
        if(racine->droit==nullptr && racine->droit==nullptr)
            return nullptr;

        //si l'elt a un seul fils
        else if(racine->gauche==nullptr){
            struct element* intermediaire = racine->droit;
            free(racine);
            return intermediaire;
        }else if(racine->droit==nullptr){
            struct element* intermediaire = racine->gauche;
            free(racine);
            return intermediaire;
        }

        //si l'elt a deux fils : on cherche le minimum du coté droit de l'elt et on écrase la valeur de cet elt avec le min trouvé
        struct element* min = valeur_minimale(racine->droit);
        //on écrase la valeur de l'elt à supprimer
        racine->valeur = min->valeur;
        //on supprime le min
        racine->droit = supprimer_element_recursive(racine->droit, min->valeur); //on peut éviter cet appel récursif et diminuer la complexité
    }
    return racine;
}
/***
 * SUPPRESSION NON RECURSIVE
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * ***/

struct element* supprimer_element(struct element* racine, int val){
    struct element* pere=nullptr;
    struct element* actuel = racine;

    chercher_element(actuel,val,pere); // on cherche l'elt à supprimer, pere point sur le parent de actuel

    //si la valeur cherchée est inexistante
    if(actuel==nullptr)
        return nullptr;
    
    // si le noeud a supp a au plus un fils , on cherche c'est quel fils
    if (actuel->gauche == nullptr || actuel->droit == nullptr) {
 
        // un ptr pour replacer le noeud à supprimer
        element* inter; //
 
        // si le noeud a un fils droit, on pointe sur lui 
        if (actuel->gauche == nullptr)
            inter = actuel->droit;
        else
            inter = actuel->gauche;
 
        
        // si le noeud à supprimer est la racine, on retourne directement le ptr
        if (pere == nullptr)
            return inter;
 
        //si le noeud à supprimer n'est pas une racine, on lie son père avec notre ptr
        if (actuel == pere->gauche)
            pere->gauche = inter;
        else
            pere->droit = inter;
 
        // on libère l'espace du  noeud actuel et on garde le ptr intermediaire 
        free(actuel);
    }
 
    // si le noeud à supp a deux fils
    else {
        element* min;
 
        // on cherche le min du sous arbre droit du noeud à supprimer on garddant trace du pere 
        min = actuel->droit;
        while (min->gauche != nullptr) {
            pere = min;
            min = min->gauche;
        }
 
        if (pere != nullptr) //vérifie si le parent du successeur en ordre sup est le courant ou non. s'il ne l'est pas, alors l'enfant gauche de son parent est égal à l'enfant droit de sup.
            pere->gauche = min->droit;
        else
            actuel->droit = min->droit;
 
        actuel->valeur = min->valeur;
        free(min);
    }
    return racine;

    
}

void CalculateTimeRecursive(element* racine, int val)
{

        //time start
        chrono::time_point<chrono::steady_clock> start = chrono::steady_clock::now(), stop;
        racine = supprimer_element_recursive(racine, val);
        //time ends
        stop = chrono::steady_clock::now();
    	chrono::duration<double, nano> duration = stop - start;
        printf("Le temps d'execution avec une approche Récursive est : %lf nanosecondes\n", duration.count());

}

void CalculateTimeIterative(element* racine, int val)
{
    //time start
        chrono::time_point<chrono::steady_clock> start = chrono::steady_clock::now(), stop;
        racine = supprimer_element(racine, val);
        //time ends
        stop = chrono::steady_clock::now();
    	chrono::duration<double, nano> duration = stop - start;
        printf("Le temps d'execution avec une approche Itérative est : %lf nanosecondes\n", duration.count());

}