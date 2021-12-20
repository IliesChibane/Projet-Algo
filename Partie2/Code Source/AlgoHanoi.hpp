#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <vector>
#include <time.h>


#include "Affiichage.hpp"
#include "pile.hpp"

int deplacement = 0, NDisque = 0;
Pile *p = NULL;

void HanoiRecursif(int n, int origine,int destination, Pilier TH[])
{
    if (n != 0)
    {
        int auxiliaire = autre(origine, destination);
        HanoiRecursif(n-1, origine, auxiliaire, TH);
        deplacement++;
        deplacer(TH[origine], TH[destination],NDisque);
        HanoiRecursif(n-1, auxiliaire, destination, TH);
    }
}

void HanoiRecursifAffichage(int n, int origine,int destination, Pilier TH[])
{
    if (n != 0)
    {
        int auxiliaire = autre(origine, destination);
        HanoiRecursifAffichage(n-1, origine, auxiliaire, TH);
        deplacement++;
        deplacer(TH[origine], TH[destination],NDisque);
        AfficheLesTours(TH, NDisque);
        HanoiRecursifAffichage(n-1, auxiliaire, destination, TH);
    }
}

void HanoiIteratif(int n, int origine,int destination, Pilier TH[])
{ 
    int op = 0, dp = 1;
    while(TH[2].Pilier[0] == 0)
    {
    deplacer(TH[op], TH[dp],NDisque);
    deplacement++;
    Chemin ep = pilierInter(dp);
    if(TH[2].Pilier[0] == 0)
    {
        int a = sommet(TH[ep.o],NDisque), b = sommet(TH[ep.d],NDisque);

        if(a== NDisque)
        {
        deplacer(TH[ep.d], TH[ep.o],NDisque);
        deplacement++;
        }
        else if (b == NDisque)
        {
        deplacer(TH[ep.o], TH[ep.d],NDisque);
        deplacement++;
        }
        else if(TH[ep.o].Pilier[a] > TH[ep.d].Pilier[b])
        {
        deplacer(TH[ep.d], TH[ep.o],NDisque);
        deplacement++;
        }
        else
        {
        deplacer(TH[ep.o], TH[ep.d],NDisque);
        deplacement++;
        }
    }
    op = op == 2 ? 0 : op+1; 
    dp = dp == 2 ? 0 : dp+1;
    }
}

void HanoiIteratifAffichage(int n, int origine,int destination, Pilier TH[])
{ 
    int op = 0, dp = 1;
    while(TH[2].Pilier[0] == 0)
    {
    deplacer(TH[op], TH[dp],NDisque);
    AfficheLesTours(TH, NDisque);
    deplacement++;
    Chemin ep = pilierInter(dp);
    if(TH[2].Pilier[0] == 0)
    {
        int a = sommet(TH[ep.o],NDisque), b = sommet(TH[ep.d],NDisque);

        if(a == NDisque)
        {
        deplacer(TH[ep.d], TH[ep.o],NDisque);
        deplacement++;
        }
        else if (b == NDisque)
        {
        deplacer(TH[ep.o], TH[ep.d],NDisque);
        deplacement++;
        }
        else if(TH[ep.o].Pilier[a] > TH[ep.d].Pilier[b])
        {
        deplacer(TH[ep.d], TH[ep.o],NDisque);
        deplacement++;
        }
        else
        {
        deplacer(TH[ep.o], TH[ep.d],NDisque);
        deplacement++;
        }
        AfficheLesTours(TH, NDisque);
    }
    op = op == 2 ? 0 : op+1; 
    dp = dp == 2 ? 0 : dp+1;
    }
}

std::vector<Dep> Aleatoire(int n, Pilier TH[])
{
    // le nombre de deplacements a generer est 2^n - 1
    std::vector<Dep> solution;
    srand(time(NULL));
    Dep dep;
    int top_o, top_d;
    bool dep_autorise;
    for (int i = 0; i < pow(2, n) - 1; ++i)
    {
        dep_autorise = false;
        while (!dep_autorise)
        {
            dep.o = rand() % 3;
            if ((top_o = sommet(TH[dep.o], n)) == n) // origine vide
                continue;
            dep.d = rand() % 3;
            if (dep.d == dep.o) // destination meme que origine
                continue;
            top_d = sommet(TH[dep.d], n);
            if (top_d == n || TH[dep.o].Pilier[top_o] < TH[dep.d].Pilier[top_d])
                dep_autorise = true;
        }
        solution.push_back(dep);

        cout << "on deplace le disque de taille "<< TH[dep.o].Pilier[sommet(TH[dep.o], n)] 
             <<" du pilier "<< dep.o <<" au pilier "<< dep.d << endl;

        deplacer(TH[dep.o], TH[dep.d], n); 
    }
    cout << "la solution contient " << solution.size() << " deplacements" << endl;

    return solution;
}

bool Verification(int n, Pilier TH[])
{
    AfficheLesTours(TH, n);
    for (int i = 0; i < n; ++i)
    {
        if (TH[2].Pilier[i] != i + 1)
            return false;
    }
    return true;
}
