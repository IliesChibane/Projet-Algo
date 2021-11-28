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
      if (tab[i] == r)
      {
          trouve = true;
      }
     i++; 
      
  } while (trouve == false && i != n);

  if (trouve == true) return i-1;
  else return -1;
     
}

int sequentielle_processus(int *tab, unsigned long long n, int r)
{
    int  pos,status;
    bool f = false;
    pid_t pid1, pid2, pid;

    int debut = 0, fin = n/ 2;
    switch (pid1 = fork()) {
        case -1:
            break;
        case 0:
            for (int i = debut; i <= fin; i++) {
                if (tab[i] == r) {
                    f = true;
                    pos = i;
                    break;
                }
            }
            return f ? pos : -1;
        default:
            break;
    }
    debut = n/ 2 + 1, fin = n - 1;
    switch (pid2 = fork()) {
        case -1:
            break;
        case 0:
            for (int i = debut; i <= fin; i++) {
                if (tab[i] == r) {
                    f = true;
                    pos = i;
                    break;
                }
            }
            return f ? pos : -1;
        default:
            break;
    }
    
    while ((pid = wait(&status)) != -1) {
        if (WIFEXITED(status))
            if (WEXITSTATUS(status)) {
                f = true;
                if (pid == pid1) {
                    kill(pid2, SIGTERM);
                } else {
                    kill(pid1, SIGTERM);
                }
            }
    }

    if (f) return pos;
    else return -1;
    

}