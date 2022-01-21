#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <vector>
#include <time.h>

#include "Affiichage.hpp"

using namespace std;

struct Dep
{
    int o, d;
};

//variable globale afin de sauvegarder le nombre de deplacements et de disques
int deplacement = 0, NDisque = 0;

//resolution recursif des tours d'hanoi
void HanoiRecursif(int n, int origine,int destination, Pilier TH[])
{
    if (n != 0)
    {
        //on determine le pilier intermediaire
        int auxiliaire = autre(origine, destination);
        //premier appel recursif ou on deplace le disque de son pilier actuel au pilier intermediaire
        HanoiRecursif(n-1, origine, auxiliaire, TH);
        //on effectue le deplacement
        deplacement++;
        deplacer(TH[origine], TH[destination],NDisque);
        //second appel recursif ou on deplace le disque du pilier intermediaire au pilier destiination
        HanoiRecursif(n-1, auxiliaire, destination, TH);
    }
}

//resolution recursif des tours d'hanoi + affichage
void HanoiRecursifAffichage(int n, int origine,int destination, Pilier TH[])
{
    if (n != 0)
    {
        //on determine le pilier intermediaire
        int auxiliaire = autre(origine, destination);
        //premier appel recursif ou on deplace le disque de son pilier actuel au pilier intermediaire
        HanoiRecursifAffichage(n-1, origine, auxiliaire, TH);
        //on effectue le deplacement
        deplacement++;
        deplacer(TH[origine], TH[destination],NDisque);
        //affichage intermediaire des tours
        AfficheLesTours(TH, NDisque);
        //second appel recursif ou on deplace le disque du pilier intermediaire au pilier destiination
        HanoiRecursifAffichage(n-1, auxiliaire, destination, TH);
    }
}

/*
Afin de resoudre ce problème iterativement on applique les regles suivantes :
- déplacer le plus petit disque d'un emplacement à l'emplacement suivant (de TH[0] vers TH[1], de TH[1] vers TH[2], de TH[2] vers TH[0]) ;
- déplacer un autre disque ;
*/
void HanoiIteratif(int n, int origine,int destination, Pilier TH[])
{ 
    //on initialise le pilier d'origine ainsi que le pilier destination du premier deplacement
    int op = 0, dp;
    if (n % 2 == 0)
        dp = 1;
    else
        dp = 2;
    while(TH[2].Pilier[0] == 0)
    {
        //on effectue le deplacement du plus petit disque
        deplacer(TH[op], TH[dp],NDisque);
        deplacement++;
        //on determine les 2 piliers n'occupant pas le plus petit disque 
        Chemin ep = pilierInter(dp);
        //si le pilier destination n'est pas deja remplie 
        if(TH[2].Pilier[0] == 0)
        {
            //on recupere les disques se trouvant au sommet des 2 piliers 
            int a = sommet(TH[ep.o],NDisque), b = sommet(TH[ep.d],NDisque);

            /*ensuite on compare lequel des 2 piliers possedent le disque le plus petit ce dernier sera par la suite
            deplacer vers le second, dans le cas ou un des piliers est vide on deplace le disque de l'autre pilier
            automatique*/
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
        //on determine le pilier actuel du plus petit disque ainsi que sa destination
        op = dp;
        if (n % 2 == 0) 
            dp = dp == 2 ? 0 : dp + 1;
        else
            dp = dp == 0 ? 2 : dp - 1;
    }
}

//meme chose que la procedure precedente avec ajout des procedure d'affichage
void HanoiIteratifAffichage(int n, int origine,int destination, Pilier TH[])
{ 
    int op = 0, dp;
    if (n % 2 == 0)
        dp = 1;
    else
        dp = 2;
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
    op = dp;
    if (n % 2 == 0) 
        dp = dp == 2 ? 0 : dp + 1;
    else
        dp = dp == 0 ? 2 : dp - 1;
    }
}

//fonction generant des deplacement aleatoire
vector<Dep> Aleatoire(int n, Pilier TH[])
{
    // le nombre de deplacements a generer est 2^n - 1
    vector<Dep> solution;
    srand(time(NULL));
    Dep dep;
    int top_o, top_d;
    bool dep_autorise;
    for (int i = 0; i < pow(2, n) - 1; ++i)
    {
        dep_autorise = false;
        //on genere un deplacement aleatoire valide
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
        //on l'ajoute a la liste de deplacement
        solution.push_back(dep);

        cout << "on deplace le disque de taille "<< TH[dep.o].Pilier[sommet(TH[dep.o], n)] 
             <<" du pilier "<< dep.o <<" au pilier "<< dep.d << endl;

        deplacer(TH[dep.o], TH[dep.d], n); 
    }
    cout << "la solution contient " << solution.size() << " deplacements" << endl;

    return solution;
}

//verifiation de la solution aleatoire
bool Verification(int n, Pilier TH[])
{
    for (int i = 0; i < n; ++i)
    {
        AfficheLesTours(TH, n);
        //si le pilier final ne contient pas tout les disque dans le bon ordre alors on retourne false
        if (TH[2].Pilier[i] != i + 1)
            return false;
    }
    return true;
}
