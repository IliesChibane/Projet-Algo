#include <iostream>
#include <stdlib.h> //pour génerer des entiers aléatoirement
#include <bits/stdc++.h>
#include "CreationTableau.hpp"



using namespace std;

//Création de la structure de base
struct element{ //Définition de la structure
    int valeur;
    struct element *gauche=nullptr, *droit=nullptr; 
};

struct element* creer_element(int val){ //Création d'un élement dans l'arbre 
    struct element* intermediaire = (struct element*)malloc(sizeof(struct element));
    intermediaire->valeur= val;
    intermediaire->droit = intermediaire->gauche =nullptr;
    return intermediaire;
}

struct element* inserer_element(struct element* elt, int val){ //insertion d'un element dans l'arbre
    if(elt==nullptr)
        return creer_element(val);

    if(val > elt->valeur)
        elt->droit = inserer_element(elt->droit, val);

    else
        elt->gauche = inserer_element(elt->gauche, val);

    return elt;

}




struct element* creer_arbre_equilibree(int arr[], int debut, int fin){
    
    if (debut > fin)
    return nullptr;

    int milieu = (debut +fin)/2;
    element* inter = creer_element(arr[milieu]);

    //Le coté gauche du tableau fera un sous-arbre droit de l'elt du milieu du tableau 
    inter->gauche = creer_arbre_equilibree(arr, debut, milieu - 1);
 
    //Le coté droit du tableau fera un sous-arbre droit de l'elt du milieu du tableau 
    inter->droit = creer_arbre_equilibree(arr, milieu + 1, fin);
 
    return inter;
}



//Remplissage de l'arbre binaire avec un nombre n d'entiers aléatoires
struct element* creer_arbre(int arr[], int taille){
    struct element *elt =nullptr;
    for(int i=0;i<taille; i++){
        elt = inserer_element(elt, arr[i]);
    }
    return elt;
}


void chercher(element *racine, int level, int &maxLevel, int &res) //charcher la valeur du noeud le plus profond
{
    if (racine != nullptr)
    {
        chercher(racine->gauche, ++level, maxLevel, res);
 
        // mettre à jour les vals
        if (level > maxLevel)
        {
            res = racine->valeur;
            maxLevel = level;
        }
 
        chercher(racine->droit, level, maxLevel, res);
    }
}


int get_feuille(element *racine)
{
    // Initialisation
    int res = -1;
    int maxLevel = -1;
 

    chercher(racine, 0, maxLevel, res);
    return res;
}



//visualization basique de l'arbre binaire 

void traverser_arbre_ordonne(struct element* racine){ //afficher l'arbre binaire en ordre 
    if(racine != nullptr){
        traverser_arbre_ordonne(racine->gauche);
        cout <<racine->valeur<<" ";
        traverser_arbre_ordonne(racine->droit);
    }
}

void traverser_arbre_preordonne(struct element* racine){ //afficher l'arbre binaire en ordre 
    if(racine != nullptr){
        cout <<racine->valeur<<endl;
        traverser_arbre_preordonne(racine->gauche);
        traverser_arbre_preordonne(racine->droit);
    }
}

void traverser_arbre_postordonne(struct element* racine){ //afficher l'arbre binaire en ordre 
    if(racine != nullptr){
        traverser_arbre_postordonne(racine->gauche);
        traverser_arbre_postordonne(racine->droit);
        cout <<racine->valeur<<endl;
    }
}

void traverser_par_niveau(element *racine)
{
    // cas de base
    if (racine == nullptr) return;
 
    // on utilise une file pour traverser
    queue<element *> q;
 
    // enfiler la racine 
    q.push(racine);
 
    while (q.empty() == false)
    {
        // Le nombre de noeuds par niveau
        int nombre_noeuds = q.size();
 
        // defiler tous les noeuds d'un niveau et enfiler les noeuds du niveau prochain
        while (nombre_noeuds > 0)
        {
            element *element = q.front();
            cout << element->valeur << " ";
            q.pop();
            if (element->gauche != nullptr)
                q.push(element->gauche);
            if (element->droit != nullptr)
                q.push(element->droit);
            nombre_noeuds--;
        }
        cout << endl;
    }
}

