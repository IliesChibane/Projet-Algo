#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

//Algorithme de Recherche dichotomique d'un élément dans un tableau compléxité O(Log(n))
int dichotomie(int *tab, unsigned long long n, int r)
{
    unsigned long long debut = 0; //Indice du premier élément du sous-tableau analysé
    unsigned long long fin = n; //Indice du dernier élément du sous-tableau analysé
    unsigned long long i; //Indice de l'élément du milieu du sous-tableau analysé

    //Dans le cas ou la valeur recherché est plus grande ou plus petite que les bornes du tableau on retourne -1
    if((r<tab[0])||(r>tab[n-1]))
        return -1;
    //Dans le cas ou la valeur recherché est égale a la valeur de la borne inférieur du tableau on retourne la position 0
    if(tab[0]==r)
        return 0;
    //Dans le cas ou la valeur recherché est égale a la valeur de la borne supérieur du tableau on retourne la position (n-1)
    if(tab[n-1]==r)
        return (n-1);

    //on réitére la boucle tant qu'il existe des valeur entre le premier et dernier élément du sous tableau
    while ((fin>=debut))
    {
       // cout << i << " " << tab[i] <<endl;
       // cout << "debut = " << debut <<" fin = "<< fin <<endl;
        //Calcul de la position de l'élément du milieu
        i = (debut+fin)/2;

        //Si l'élément du milieu est l'élément recherché on retourne sa position
        if(tab[i]==r)
            return i;
        /*Si la valeur recherchée est plus petite que la valeur du l'élément du milieu Alors on regarde le sous-tableau
        de gauche*/
        else if (tab[i]>r)
            fin = i-1;
        //sinon on regarde le sous-tableau de droite
        else
            debut = i+1;
    }
    //Dans le cas ou la valeur n'a pas été trouvé dans le tableau on retourne la valeur -1
    return -1;
}

//L'algo de dichotomie nécessitant que le tableau soit trier nous utilisons une fonction de trie afin d'éviter toute erreur
void trierTab (int *tab,unsigned long long n)
{
    unsigned long long i,j;
    int x;
    for (i=1;i<n;i++)
    {
      for (j=0;j<n;j++)
      {
          if (tab[i]<tab[j])
          {
              x=tab[i];
              tab[i]=tab[j];
              tab[j]=x;
          }
      }
    }
}

//fonction qui remplie le tableau avec des valeurs aléatoire
void remplirTabRandom(int *tab, unsigned long long n)
{
    unsigned long long R = n*10, i;
    int list[R];
    srand(time(NULL));
    //On remplie une liste contenant une liste de nombre de 1 a R
    for (i = 0; i < R; ++i) {
        list[i] = i;
    }
    //On mélange par la suite l'ordre des nombres dans la liste aléatoirement
    for (i = 0; i < R; ++i) {
        unsigned long long j = i + rand() % (R - i);
        int temp = list[i];
        list[i] = list[j];
        list[j] = temp;
    }
    //On remplie notre tableau avec les n première valeur de la liste mélangée
    for (i = 0; i < n; ++i) {
        tab[i] = list[i];
    }

    //On finit la préparation du tableau en le triant par ordre croissant
    trierTab (tab,n);
    system("cls");

    //Afin de ne pas surchargé la console nous n'afficheront pas les tableaux ayant une taille au dessus de 1000
    if(n<1000)
    {
        cout << "[";
        for(i = 0; i<n; ++i)
        {
            cout << tab[i];
            if(i!=(n-1))
                cout << ", ";
        }
        cout << "]" << endl;
    }

    //On informe l'utilisateur que le tableau a été créer avec succès
    cout << "Tableau de "<< n << " creer avec succes"<< endl;
}

int main()
{
    cout << "choisissez la taille du tableau" << endl;

    unsigned long long n;
    cin >> n;

    int *t = (int *)malloc(n * sizeof(int));
    remplirTabRandom(t,n);

    cout << "choisissez le nombre que vous voulez rechercher dans le tableau" << endl;

    int val;
    cin >> val;

    int pos = dichotomie(t,n,val);

    if(pos!=-1)
        cout << "la valeur " << val << " se trouve a la position " << pos << endl;
    else
        cout << "la valeur " << val << " n'existe pas dans le tableau" << endl;

    return 0;
}
