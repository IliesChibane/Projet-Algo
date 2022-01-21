#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif

#include <iostream>
#include <cstdlib>

#include "structure.hpp"

using namespace std;

//affiche un char n fois
void affiche(char c, int n)
{
  for (int i = 0; i < n; ++i)
    cout << c;
}

//affiche une tour
void AfficherTour(int d, int n)
{
  //pas disque affihe la poutre du pilier
  if (d == 0) {
    affiche(' ', n-1);
    cout << '|';
    affiche(' ', n);
  }
  //affichage du pilier selon sa taille
  else {
    affiche(' ', n-d);
    affiche('-', 2*d-1);
    affiche(' ', n-d+1);
  }
}

//affiche des 3 tours
void AfficheLesTours(Pilier TH[], int n)
{
  for (int i = 0; i < n; ++i) {
    AfficherTour(TH[0].Pilier[i], n);
    AfficherTour(TH[1].Pilier[i], n);
    AfficherTour(TH[2].Pilier[i], n);
    cout << endl;
  }

  affiche('#', 6*n-1);
  cout << endl << endl;
  //Sleep(500);
}
