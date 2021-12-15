#include <iostream>
#include <stdlib.h>
#include <bits/stdc++.h>

using namespace std;

//fonction qui remplie le tableau avec des valeurs aléatoire
void remplirTabRandom(int *tab, unsigned long long n)
{
    auto R = n * 10;

    int *liste = (int *)malloc(R * sizeof(int));

    //srand(time(NULL));
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

    free(liste);
}

//L'algo de dichotomie nécessitant que le tableau soit trier nous utilisons une fonction de trie afin d'éviter toute erreur
// On applique l'algo de tri fusion
void Fusion(int *tab, unsigned long long const gauche, unsigned long long const mid, unsigned long long const droite)
{
    auto const subtab1 = mid - gauche + 1;
    auto const subtab2 = droite - mid;

    // Création de tableau temporaire
    int *tabG = (int *)malloc(subtab1 * sizeof(int)),
        *tabD = (int *)malloc(subtab1 * sizeof(int));

    // On copie le contenue du tableau dans tabG et tabD
    for (auto i = 0; (unsigned)i < subtab1; ++i)
        tabG[i] = tab[gauche + i];

    for (auto j = 0; (unsigned)j < subtab2; ++j)
        tabD[j] = tab[mid + 1 + j];

    auto subtab1_index = 0, // Index initial du premier sous tableau
        subtab2_index = 0; // Index initial du second sous tableau
    int tabfusion_index = gauche; // Index initial du tableau fusionné

    // On fusionne les 2 tableau en prennant a chaque fois la valeur le plus petite des 2 tableaux
    while ((unsigned)subtab1_index < subtab1 && (unsigned)subtab2_index < subtab2) {
        if (tabG[subtab1_index] <= tabD[subtab2_index]) {
            tab[tabfusion_index] = tabG[subtab1_index];
            subtab1_index++;
        }
        else {
            tab[tabfusion_index] = tabD[subtab2_index];
            subtab2_index++;
        }
        tabfusion_index++;
    }
    // On copie le contenue du restant du tableau tabG
    while ((unsigned)subtab1_index < subtab1) {
        tab[tabfusion_index] = tabG[subtab1_index];
        subtab1_index++;
        tabfusion_index++;
    }
    // On copie le contenue du restant du tableau tabD
    while ((unsigned)subtab2_index < subtab2) {
        tab[tabfusion_index] = tabD[subtab2_index];
        subtab2_index++;
        tabfusion_index++;
    }
}

// On divive le tableau en 2 de manière recursive puis on les tri avant de les fusionner
void TriFusion(int *tab, unsigned long long const debut, unsigned long long const fin)
{
    if (debut >= fin)
        return;

    auto mid = debut + (fin - debut) / 2;
    TriFusion(tab, debut, mid);
    TriFusion(tab, mid + 1, fin);
    Fusion(tab, debut, mid, fin);
}

