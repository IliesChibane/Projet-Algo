#include "tree.hpp"
#include<chrono>

//Recherche d'un element dans un arbre binaire 
using namespace std;



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

    else { //si val == racine->valeur (on a trouvé l'elt à supprimer)

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

    // on cherche l'elt à supprimer, pere point sur le pere de actuel
    while(actuel != nullptr && actuel->valeur != val){
        pere = actuel;

        if(val < actuel->valeur)
            actuel = actuel->gauche;
        else
            actuel = actuel->droit;
    } 

    //si la valeur cherchée est inexistante
    if(actuel==nullptr){
        printf("La valeur que vous cherchez à supprimer n'existe pas\n");
        return nullptr;
    }
    
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
        pere = racine;
 
        // on cherche le min du sous arbre droit du noeud à supprimer on garddant trace du pere 
        min = actuel->droit;
        while (min->gauche != nullptr) {
            pere = min;
            min = min->gauche;
        }
 
        if (pere != racine) //vérifie si le pere du successeur en ordre sup est le courant ou non. s'il ne l'est pas, alors l'enfant gauche de son pere est égal à l'enfant droit de sup.
            pere->gauche = min->droit;
        else
            actuel->droit = min->droit;
 
        actuel->valeur = min->valeur;
        free(min);
    }
    return racine;
}


// Autre fonction de suppression
struct element* supprimer_element0(element* racine, int val)
{
    element* pere = nullptr;
    element* actuel = racine;
 
    // on cherche l'elt à supprimer, pere point sur le pere de actuel
    while(actuel != nullptr && actuel->valeur != val){
        pere = actuel;

        if(val < actuel->valeur)
            actuel = actuel->gauche;
        else
            actuel = actuel->droit;
    } 
 
    //si la valeur cherchée est inexistante
    if(actuel==nullptr){
        printf("La valeur que vous cherchez à supprimer n'existe pas\n");
        return nullptr;
    }
 
    // Cas 1: le noeud n'a aucun fils
    if (actuel->gauche == nullptr && actuel->droit == nullptr){
        // si le noeud à supp n'est pas une racine, on met son pere gauche/droit à Null
        if (actuel != racine)
        {
            if (pere->gauche == actuel) 
                pere->gauche = nullptr;
            
            else 
                pere->droit = nullptr;
        }
        // si nous avons qu'une racine
        else {
            return nullptr;
        }

        // on libère l'espace
        free(actuel);        // ou bien delete actuel en appelant le destructeur
    }

    // Cas 2: noeud à supp a deux fils
    else if (actuel->gauche && actuel->droit){
        element* min; // pour chercher le succ en ordre
        pere = racine;

        // on cherche le min du sous arbre droit du noeud à supprimer on garddant trace du pere 
        min = actuel->droit;
        while (min->gauche != nullptr) {
            pere = min;
            min = min->gauche;
        }

        if (pere != racine) //vérifie si le pere du successeur en ordre sup est le courant ou non. s'il ne l'est pas, alors l'enfant gauche de son pere est égal à l'enfant droit de sup.
            pere->gauche = min->droit;
        else
            actuel->droit = min->droit;

        actuel->valeur = min->valeur;
        free(min);
    }
    // Cas 3: le noeud à supp a un seul fils
    else {
        // choose a intermediaire node
        element* intermediaire = (actuel->gauche)? actuel->gauche: actuel->droit;

        //si le noeud n'est pas une racine, on lie le pere gauche/droit avec l'intermediaire  
        if (actuel != racine)
        {
            if (actuel == pere->gauche) 
                pere->gauche = intermediaire;
            
            else 
                pere->droit = intermediaire;
            
        }
        //si le noeud  est la racine, l'intermediaire devient direct la racine
        else 
            return intermediaire;
        
        // deallocate the memory
        free(actuel);
    }
    return racine;
}



bool existe(struct element* noeud, int val){ //vérifier si le noeud existe pour l'approche récursiv
    if (noeud == nullptr)
        return false;
 
    if (noeud->valeur == val)
        return true;
 
    
    bool res1 = existe(noeud->gauche, val);
    
    if(res1) return true;
 
    
    bool res2 = existe(noeud->droit, val);
 
    return res2;
}

void CalculateTimeRecursive(element* &racine, int val){
    if (! existe(racine,val)){
        printf("La valeur que vous cherchez à supprimer n'existe pas\n");
    } 
    else{
        //time start
        chrono::time_point<chrono::steady_clock> start = chrono::steady_clock::now(), stop;
        racine = supprimer_element_recursive(racine, val);
        //time ends
        stop = chrono::steady_clock::now();
        chrono::duration<double, nano> duration = stop - start;
        printf("Le temps d'execution avec une approche Récursive est : %lf nanosecondes\n", duration.count());
    }
}

void CalculateTimeIterative(element* &racine, int val, int &ex){
        //time start
        chrono::time_point<chrono::steady_clock> start = chrono::steady_clock::now(), stop;
        racine = supprimer_element(racine, val);
        //time ends
        stop = chrono::steady_clock::now();
        chrono::duration<double, nano> duration = stop - start;
        printf("Le temps d'execution avec une approche Itérative est : %lf nanosecondes\n", duration.count());
	    ex = duration.count();

}