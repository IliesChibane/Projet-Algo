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

//initalisation du pilier
void init(Pilier TH[], int n)
{
  //creation des 3 piliers
  for (int i = 0; i < 3; ++i)
    TH[i].Pilier = (int *)malloc(n * sizeof(int));
  
  // chaque pilier est representer par sa taille le plus petit est representer par l'indice 1 et le plus grand par l'indice n
  // on represente l'abscence de pilier par l'indice 0 
  for (int i = 0; i < n; ++i)
  {
    TH[0].Pilier[i] = i+1; // premier pilier contient l'integralite des disque dans l'odre de leur taille variant de 1 a n
    TH[1].Pilier[i] = 0; // pilier vide
    TH[2].Pilier[i] = 0; // pilier vide
  }
}

//on retourne le disque se trouvant au sommet du pilier
int sommet(Pilier p, int n)
{
  int top;
  //on parcourt le pilier jusqu'a atteindre le premier disque du tableau 
  for (top = 0; (top < n) && (p.Pilier[top] == 0); ++top);
    return top;
}

//on deplace un disque d'un pilier a un autre
void deplacer(Pilier &origine, Pilier &destination, int n)
{
  //on recupere le disque a deplacer
  int top1 = sommet(origine, n);

  if (top1 < n)
  {
    /*on verifie que le disque a deplacer n'est pas plus grand que le disque se rouvant au sommet du pilier destination
    et que le pilier destination n'est pas autrement on retourne une erreur*/
    int top2 = sommet(destination,n);
    if ((top2 < n) && (destination.Pilier[top2] < origine.Pilier[top1])) 
    {
      cerr << "ERREUR : on ne peut pas deplacer une disque de taille "
           << origine.Pilier[top1] << " sur un disque de taille "
           << destination.Pilier[top2] << " !" << endl;
      return;
    }

    //on ajoute le disque au pilier destination et on l'enleve du pilier origine
    destination.Pilier[top2-1] = origine.Pilier[top1];
    origine.Pilier[top1] = 0;
  }
}

//defini le pilier intermediaire
int autre(int p1, int p2)
{
  return 3 - p1 -p2;
}

//retoune les 2 piliers ne contenant pas le plus petit disque
Chemin pilierInter(int a)
{
  Chemin ep;
  //la variable 'a' contient la position pilier contenant le plus petit disque on retourne par consequent les 2 autres piliers
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