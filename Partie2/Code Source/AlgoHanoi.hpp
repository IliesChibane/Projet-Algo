#include <iostream>
#include <stdlib.h>
#include <math.h>


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

void Aleatoire(int n, Pilier TH[])
{
    p = ( Pile*) malloc(sizeof(Pile));
    p->sommet = NULL;
    for(int i =0; i < (pow(2,n)-2); ++i)
    {
        int o = rand()%3, f =rand()%3;
        if(o == f)
        {
            if(f == 0)
                f += rand() % 2 == 0 ? 1 : 2;
            else if (f == 2)
                f -= rand() % 2 == 0 ? 1 : 2;
            else
                f += rand() % 2 == 0 ? 1 : (-1);
        }

        while(TH[o].Pilier[0] == 0)
        {
            if(o == 0)
                o += rand() % 2 == 0 ? 1 : 2;
            else if (o == 2)
                o -= rand() % 2 == 0 ? 1 : 2;
            else
                o += rand() % 2 == 0 ? 1 : (-1);
        }

        emPiler(p, o, f);
    }
    emPiler(p, 0, rand()%2 + 1);
}

void Verification(int n, Pilier TH[])
{
    for(int i =0; i < (pow(2,n)-1); ++i)
    {
        Dep d = dePiler(p);
        cout << "on deplace le disque de taille "<< TH[d.o].Pilier[sommet(TH[d.o], n)] 
             <<" du pilier "<< d.o <<" au pilier "<< d.d << endl;
        deplacer(TH[d.o], TH[d.d],NDisque);
    }

    if(TH[2].Pilier[0] == 0)
    {
        cout << "Solution invalide" << endl;
    }
    else
    {
        cout << "Solution valide" << endl;
        cout << "Tour d'hanoi resolu en " << deplacement << " deplacements" <<endl;
    }
}