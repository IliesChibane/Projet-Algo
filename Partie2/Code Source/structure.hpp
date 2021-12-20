#include <iostream>

using namespace std;

struct Pilier
{
  int *Pilier;
};

struct Chemin
{
    int o,d;
};

void init(Pilier TH[], int n)
{
  for (int i = 0; i < 3; ++i)
    TH[i].Pilier = (int *)malloc(n * sizeof(int));
  for (int i = 0; i < n; ++i)
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
    if ((top2 < n) && (destination.Pilier[top2] < origine.Pilier[top1])) 
    {
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

Chemin pilierInter(int a)
{
  Chemin ep;
  switch(a)
  {
    case 1 :
      ep.o = 0;
      ep.d = 2;
      break;
    case 0 :
      ep.o = 1;
      ep.d = 2;
      break;
    case 2 :
      ep.o = 0;
      ep.d = 1;
      break;
  }

  return ep;
}