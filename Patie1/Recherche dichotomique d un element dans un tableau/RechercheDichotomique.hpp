#include <iostream>
#include <stdlib.h>
#include <bits/stdc++.h>

#include "CreationTableau.hpp"

using namespace std;

//Algorithme de Recherche dichotomique d'un élément dans un tableau compléxité O(Log(n))
int dichotomie(int *tab, unsigned long long n, int r)
{

    unsigned long long debut = 0; //Indice du premier élément du sous-tableau analysé
    unsigned long long fin = n; //Indice du dernier élément du sous-tableau analysé
    unsigned long long i; //Indice de l'élément du milieu du sous-tableau analysé

    //Dans le cas ou la valeur recherché est plus grande ou plus petite que les bornes du tableau on retourne -1
    if((r < tab[0])||(r > tab[n-1]))
        return -1;
    //Dans le cas ou la valeur recherché est égale a la valeur de la borne inférieur du tableau on retourne la position 0
    if(tab[0] == r)
        return 0;
    //Dans le cas ou la valeur recherché est égale a la valeur de la borne supérieur du tableau on retourne la position (n-1)
    if(tab[n-1] == r)
        return (n - 1);

    //on réitére la boucle tant qu'il existe des valeur entre le premier et dernier élément du sous tableau
    while ((fin >= debut))
    {
        //Calcul de la position de l'élément du milieu
        i = (debut + fin) / 2;
        /*cout << i << " " << tab[i] <<endl;
        cout << "debut = " << debut <<" fin = "<< fin <<endl;*/
        //Si l'élément du milieu est l'élément recherché on retourne sa position
        if(tab[i] == r)
            return i;
        /*Si la valeur recherchée est plus petite que la valeur du l'élément du milieu alors on regarde le sous-tableau
        de gauche*/
        else if ( tab[i] > r)
            fin = i - 1;
        //sinon on regarde le sous-tableau de droite
        else
            debut = i + 1;
    }
    //Dans le cas ou la valeur n'a pas été trouvé dans le tableau on retourne la valeur -1

    return -1;
}
