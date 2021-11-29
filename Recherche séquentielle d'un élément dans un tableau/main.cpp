#include <iostream>
#include <stdlib.h>
#include <bits/stdc++.h>

#include "RechercheSequentielle.hpp"

using namespace std;

int main()
{
    cout << "choisissez la taille du tableau" << endl;

    unsigned long long n;
    cin >> n;

    int *t = (int *)malloc(n * sizeof(int));
    remplirTabRandom(t, n);

    AffichTab(t, n);

    cout << "choisissez le nombre que vous voulez rechercher dans le tableau" << endl;

    int val;
    cin >> val;
 cout << "fin de cin"<< endl;

    chrono::time_point<chrono::steady_clock> start = chrono::steady_clock::now(), stop;

    //TriFusion(t, 0, n - 1);
cout << "début de recherche"<< endl;
   // int pos = sequentielle(t, n, val);
    int pos = sequentielle_processus(t, n, val);
cout << "fin de recherche"<< endl;

    stop = chrono::steady_clock::now();
    chrono::duration<double, nano> duration = stop - start;

    if(pos!=-1)
        cout << "la valeur " << val << " apres avoir trier le tableau se trouve a la position " << pos << endl;
    else
        cout << "la valeur " << val << " n'existe pas dans le tableau" << endl;

    cout << "la fonction de recherche sequentielle apres le tri le tableau aura prit " << duration.count()
         << "ns afin de terminer son execution" <<endl;
    return 0;
}
