#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif

#include <iostream>
#include <cstdlib>

#include "structure.hpp"

using namespace std;

void affiche(char c, int n)
{
  for (int i = 0; i < n; ++i)
    cout << c;
}

void AfficherTour(int d, int n)
{
  if (d == 0) {
    affiche(' ', n-1);
    cout << '|';
    affiche(' ', n);
  }
  else {
    affiche(' ', n-d);
    affiche('-', 2*d-1);
    affiche(' ', n-d+1);
  }
}

void AfficheLesTours(Pilier TH[], int n)
{
  for (int i = 0; i < n; ++i) {
    AfficherTour(TH[0].Pilier[i], n);
    //sleep(100);
    AfficherTour(TH[1].Pilier[i], n);
    //sleep(100);
    AfficherTour(TH[2].Pilier[i], n);
    //sleep(100);
    cout << endl;
  }

  affiche('#', 6*n-1);
  cout << endl << endl;
  //sleep(1000);
}
