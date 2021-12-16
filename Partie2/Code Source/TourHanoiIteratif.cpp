#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int deplacement = 0, NDisque = 0;

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
    TH[0].Pilier[i] = i + 1;
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

void deplacer(Pilier& origine, Pilier& destination, int n)
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

void hanoi(int n, int origine,int destination, Pilier TH[])
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


int main()
{
  int NbrDisque;
  Pilier TourHanoi[3];

  cout << "Choisissez le nombre de disque" << endl;
  cin >> NbrDisque;
  NDisque = NbrDisque;
  init(TourHanoi, NbrDisque);
  chrono::time_point<chrono::steady_clock> start = chrono::steady_clock::now(), stop;
  hanoi(NbrDisque, 0, 2, TourHanoi);
  stop = chrono::steady_clock::now();
  chrono::duration<double, nano> duration = stop - start;
  cout << "Tour d'hanoi resolu en " << deplacement << " deplacements" <<endl;
  cout << "la fonction de resolution de la tour d'hanoi aura prit " << duration.count()
         << "ns afin de terminer son execution" <<endl;
  return 0;
}