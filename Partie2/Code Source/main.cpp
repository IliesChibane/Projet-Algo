#include <iostream>
#include <stdlib.h>
#include<time.h>
#include <bits/stdc++.h>

#include "AlgoHanoi.hpp"

using namespace std;

int main()
{
    srand(time(0));
    cout <<"\t\t\tBienvenu dans la partie 2 du projet de Conception, analyse et complexite des algorithmes"<<endl;
    cout <<"Veuille choisir l'une des options suivante :"<<endl;
    cout <<"1) Algorithme des d'Hanoi recursif"<<endl;
    cout <<"2) Algorithme des d'Hanoi recursif avec affichage"<<endl;
    cout <<"3) Algorithme des d'Hanoi iteratif"<<endl;
    cout <<"4) Algorithme des d'Hanoi iteratif avec affichage"<<endl;
    cout <<"5) Solution aleatoire"<<endl;

    int ch, NbrDisque;
    Pilier TourHanoi[3];
    cin >> ch;

    switch(ch)
    {
        case 1:
            cout << "Choisissez le nombre de disque" << endl;
            cin >> NbrDisque;
            NDisque = NbrDisque;
            init(TourHanoi, NbrDisque);
            chrono::time_point<chrono::steady_clock> start = chrono::steady_clock::now(), stop;
            HanoiRecursif(NbrDisque, 0, 2, TourHanoi);
            stop = chrono::steady_clock::now();
            chrono::duration<double, nano> duration = stop - start;
            cout << "Tour d'hanoi resolu en " << deplacement << " deplacements" <<endl;
            cout << "la fonction de resolution de la tour d'hanoi aura prit " << duration.count()
                 << "ns afin de terminer son execution" <<endl;
            break;

        case 2:
            cout << "Choisissez le nombre de disque" << endl;
            cin >> NbrDisque;
            NDisque = NbrDisque;
            init(TourHanoi, NbrDisque);
            AfficheLesTours(TourHanoi, NbrDisque);
            Sleep(1000);
            HanoiRecursifAffichage(NbrDisque, 0, 2, TourHanoi);
            cout << "Tour d'hanoi resolu en " << deplacement << " deplacements" <<endl;
            break;

        case 3:
            cout << "Choisissez le nombre de disque" << endl;
            cin >> NbrDisque;
            NDisque = NbrDisque;
            init(TourHanoi, NbrDisque);
            chrono::time_point<chrono::steady_clock> start = chrono::steady_clock::now(), stop;
            HanoiIteratif(NbrDisque, 0, 2, TourHanoi);
            stop = chrono::steady_clock::now();
            chrono::duration<double, nano> duration = stop - start;
            cout << "Tour d'hanoi resolu en " << deplacement << " deplacements" <<endl;
            cout << "la fonction de resolution de la tour d'hanoi aura prit " << duration.count()
                 << "ns afin de terminer son execution" <<endl;
            break;

        case 4:
            cout << "Choisissez le nombre de disque" << endl;
            cin >> NbrDisque;
            NDisque = NbrDisque;
            init(TourHanoi, NbrDisque);
            AfficheLesTours(TourHanoi, NbrDisque);
            Sleep(1000);
            HanoiIteratifAffichage(NbrDisque, 0, 2, TourHanoi);
            cout << "Tour d'hanoi resolu en " << deplacement << " deplacements" <<endl;
            break;

        case 5:
            cout << "Choisissez le nombre de disque" << endl;
            cin >> NbrDisque;
            NDisque = NbrDisque;
            init(TourHanoi, NbrDisque);
            Aleatoire(NbrDisque, TourHanoi);
            Verification(NbrDisque, TourHanoi);
            break;

        default:
            cout << "erreur "<<endl;
    }
}