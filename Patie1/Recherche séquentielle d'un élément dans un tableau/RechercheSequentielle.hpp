#include <iostream>
#include <stdlib.h>
#include <bits/stdc++.h>
#include <vector>
#include <sys/types.h>
#include <unistd.h>
#include <wait.h>
#include <signal.h>

#include "CreationTableau.hpp"

using namespace std;

int sequentielle(int *tab, unsigned long long n, int r)
{
  unsigned long long i=0;
  bool trouve = false;
  do
  {
      if (tab[i] == r) //si la valeur recherchée est égale à l'élément actuel
      {
          trouve = true;// on met la variable trouve à vrai
      }
     i++; 
      
  } while (trouve == false && i != n);

  if (trouve == true) return i-1; //si la valeur est trouvée on renvoie sa position
  else return -1;//sinon, on renvoie -1
     
}

int sequentielle_processus(int *tab, unsigned long long n, int r)
{
    int  pos,status;
    bool f = false;
    pid_t pid1, pid2, pid;

    int debut = 0, fin = n/ 2;
    switch (pid1 = fork()) {//on crée le fils 1
        case -1: //dans le cas où y'a un problème lors de la création
            break;
        case 0: // le fils 1 est créé avec succès
            for (int i = debut; i <= fin; i++) {//on commence la recheche du début jusqu'au milieu du tableau
                if (tab[i] == r) {
                    f = true;
                    pos = i;
                    break;
                }
            }
            cout << "la valeur cherchée se trouve a la position " << pos << endl;  
            //si le fils 1 trouve la valeur cherchée il affichera sa position sinon il affiche
            //un nombre négatif
            exit( f ? pos : -1);//si le fils 1 a trouvé la valeur on renvoie sa position
            //sinon on revoie -1
        default:
            break;
    }
    debut = n/ 2 + 1, fin = n - 1;
    switch (pid2 = fork()) {//on crée le fils 2
        case -1://dans le cas où y'a un problème lors de la création
            break;
        case 0:// le fils 2 est créé avec succès
            for (int i = debut; i <= fin; i++) {//on commence la recheche du milieu jusqu'à la fin du tableau
                if (tab[i] == r) {
                    f = true;
                    pos = i;
                    break;
                }
            }
            cout << "la valeur cherchée se trouve a la position " << pos << endl;  
            //si le fils 2 trouve la valeur cherchée il affichera sa position sinon il affiche
            //un nombre négatif
            exit(f ? pos : -1);//si le fils 2 a trouvé la valeur on renvoie sa position
            //sinon on revoie -1
        default:
            break;
    }
    
    while ((pid = wait(&status)) != -1) {//le père attend l'arrivée du premier fils
        if (WIFEXITED(status))
            if (WEXITSTATUS(status)) {
                f = true;
                if (pid == pid1) {
                    kill(pid2, SIGTERM);//si le fils 1 arrive on tue le fils 2
                } else {
                    kill(pid1, SIGTERM);//si le fils 2 arrive on tue le fils 1
                }
            }
    }

    if (f) return 0;
    else{
        //si aucun fils n'a trouvé la valeur recherché on affiche le message suivant:
        cout << "la valeur cherchée n'existe pas dans le tableau" << endl;
        return -1;
    }


}