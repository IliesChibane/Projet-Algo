#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif

#include <iostream>
#include <cstdlib>


using namespace std;

int deplacement = 0, NDisque = 0;

struct Pilier
{
  int *Pilier;
};

void init(Pilier TH[], int n)
{
  for (auto i = 0; i < 3; ++i)
    TH[i].Pilier = (int *)malloc(n * sizeof(int));
  for (auto i = 0; i < n; ++i)
  {
    TH[0].Pilier[i] = i+1;
    TH[1].Pilier[i] = 0;
    TH[2].Pilier[i] = 0;
  }
}

int sommet(Pilier p, int n)
{
  int top;
  for (top = 0; (top < n) && (p.Pilier[top] == 0); ++top);
    return top;
}

void deplacer(Pilier &origine, Pilier &destination, int n)
{
  int top1 = sommet(origine, n);

  if (top1 < n)
  {

    int top2 = sommet(destination,n);
    if ((top2 < n) && (destination.Pilier[top2] < origine.Pilier[top1])) {
      cerr << "ERREUR : on ne peut pas deplacer une disque de taille "
           << origine.Pilier[top1] << " sur un disque de taille "
           << destination.Pilier[top2] << " !" << endl;
      return;
    }

    destination.Pilier[top2-1] = origine.Pilier[top1];
    origine.Pilier[top1] = 0;
  }
}

int autre(int p1, int p2)
{
  return 3 - p1 -p2;
}

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
    Sleep(100);
    AfficherTour(TH[1].Pilier[i], n);
    Sleep(100);
    AfficherTour(TH[2].Pilier[i], n);
    Sleep(100);
    cout << endl;
  }

  affiche('#', 6*n-1);
  cout << endl << endl;
  Sleep(1000);
}


void hanoi(int n, int origine,int destination, Pilier TH[])
{
  if (n != 0)
  {
    int auxiliaire = autre(origine, destination);
    hanoi(n-1, origine, auxiliaire, TH);
    deplacement++;
    deplacer(TH[origine], TH[destination],NDisque);
    AfficheLesTours(TH, NDisque);
    hanoi(n-1, auxiliaire, destination, TH);
  }
}

int main()
{
  int NbrDisque;
  Pilier TourHanoi[3];

  cout << "Choisissez le nombre de disque" << endl;
  cin >> NbrDisque;
  NDisque = NbrDisque;
  init(TourHanoi, NbrDisque);
  AfficheLesTours(TourHanoi, NbrDisque);
  Sleep(1000);
  hanoi(NbrDisque, 0, 2, TourHanoi);
  cout << "Tour d'hanoi resolu en " << deplacement << " deplacements";

  return 0;
}