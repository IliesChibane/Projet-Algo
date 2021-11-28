#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <bits/stdc++.h>

using namespace std;

//fonction qui remplie le tableau avec des valeurs aléatoire
void remplirTabRandom(int *tab, unsigned long long n)
{
    auto R = n * 10;

    int *liste = (int *)malloc(R * sizeof(int));

    srand(time(NULL));
    //On remplie une liste contenant une liste de nombre de 1 a R

    for (auto i = 0; (unsigned)i < R; ++i) {
        liste[i] = i;
    }

    //On mélange par la suite l'ordre des nombres dans la liste aléatoirement
    for (auto i = 0; (unsigned)i < R; ++i) {
        auto j = i + rand() % (R - i);
        int temp = liste[i];
        liste[i] = liste[j];
        liste[j] = temp;
    }

    //On remplie notre tableau avec les n première valeur de la liste mélangée
    for (auto i = 0; (unsigned)i < n; ++i) {
        tab[i] = liste[i];
    }
    system("cls");

    //On informe l'utilisateur que le tableau a été créer avec succès
    cout << "Tableau de "<< n << " creer avec succes"<< endl;

    free(liste);
}


void AffichTab(int *tab, unsigned long long n)
{
    //Afin de ne pas surchargé la console nous n'afficheront que les 1000 premières valeurs du tableau
    cout << "[";
    for(auto i = 0; (unsigned)i < 1000; ++i)
    {
        cout << tab[i];
        if((unsigned)i != (n - 1))
            cout << ", ";
        if(((unsigned)i==999)&&(n!=1000))
            cout << ".......";
        else if((unsigned)i == (n - 1))
            break;
    }
    cout << "]" << endl;
}
