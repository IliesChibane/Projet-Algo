#include <iostream> 
#include <bits/stdc++.h>
#include <stdlib.h> 
#include "suppression.hpp"
using namespace std;





int main(){
    int n = 10;
    // test alétoire 
	/*cout << "----------------------------Supression d'un arbre quelconque----------------------------" << endl;
	int *arr = (int *)malloc(n * sizeof(int));
    remplirTabRandom(arr, n);
    element* arbre_aleatoire = creer_arbre(arr, n);
    cout<<"Arbre avant"<<endl;
    traverser_par_niveau(arbre_aleatoire);
	
	cout << "choisissez le nombre que vous voulez supprimer dans l'arbre " << endl;
    int val;
    cin >> val;
	
    CalculateTimeRecursive(arbre_aleatoire, val);
    CalculateTimeIterative(arbre_aleatoire, val);
    cout<<"Arbre après"<<endl;
    traverser_par_niveau(arbre_aleatoire);


	
    // test sur un arbre équilibré
	cout << "----------------------------Supression d'un arbre équilibré----------------------------" << endl;
    TriFusion(arr, 0, n - 1); //il faut trier le tableau avant de créer un arbre equilibré
    element* arbre_equilibree = creer_arbre_equilibree(arr,0,n-1); 
    cout<<"Arbre avant"<<endl;
    traverser_par_niveau(arbre_equilibree);
		

	
    CalculateTimeRecursive(arbre_equilibree, val);
    CalculateTimeIterative(arbre_equilibree, val);
    cout<<"Arbre après"<<endl;
    traverser_par_niveau(arbre_equilibree);


	
    // test sur un arbre completement non équilibré, arr est déja trié donc on crée normalement l'arbre et tous les noeud vont etre à droite
	cout << "----------------------------Supression d'un arbre complètement déséquilibré----------------------------" << endl;
    element* arbre_non_equilibree = creer_arbre(arr, n); //arr est déjà trié
    cout<<"Arbre avant"<<endl;
    traverser_par_niveau(arbre_non_equilibree);
		

	
    CalculateTimeRecursive(arbre_non_equilibree, val);
    CalculateTimeIterative(arbre_non_equilibree, val);
    cout<<"Arbre après"<<endl;
    traverser_par_niveau(arbre_non_equilibree);
*/
	
	int *arr = (int *)malloc(n * sizeof(int));
	int i = 0, val, tem = 0, exet;
	element* arbre_aleatoire;
    
	
	//for (i = 0; i<10; i++){
		
        remplirTabRandom(arr, n);
        arbre_aleatoire = creer_arbre(arr, n);
        //cout<<"Arbre avant"<<endl;
        //traverser_par_niveau(arbre_aleatoire);

    
        CalculateTimeIterative(arbre_aleatoire, arbre_aleatoire->valeur);
        CalculateTimeRecursive(arbre_aleatoire, arbre_aleatoire->valeur);
		//tem = tem + exet;

        //cout<<"Arbre après"<<endl;
        //traverser_par_niveau(arbre_aleatoire);

	//}
    //printf("Le temps d'execution moyen est : %f \n",(float)(tem/10));

	return 0;
}

