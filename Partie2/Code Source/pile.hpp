#include <iostream>
#include <stdlib.h>

using namespace std;

struct Dep
{
    int o, d;
};

struct ElementPile
{
    int val1, val2;
    struct ElementPile *svt;
};

struct Pile
{
    ElementPile *sommet;
};

void emPiler(Pile *&Pile, int v1, int v2)
{
    ElementPile *nouveau = ( ElementPile*) malloc(sizeof(ElementPile));
    if (Pile == NULL || nouveau == NULL)
    {
        exit(EXIT_FAILURE);
    }

    nouveau->val1 = v1;
    nouveau->val2 = v2;
    nouveau->svt = Pile->sommet;
    Pile->sommet = nouveau;
}

Dep dePiler(Pile *&Pile)
{
    if (Pile == NULL)
    {
        exit(EXIT_FAILURE);
    }

    Dep valDePile; 
    valDePile.o = 0, valDePile.d = 0;
    ElementPile *ElementPileDePile = Pile->sommet;

    if (Pile != NULL && Pile->sommet != NULL)
    {
        valDePile.o = ElementPileDePile->val1;
        valDePile.d = ElementPileDePile->val2;
        Pile->sommet = ElementPileDePile->svt;
        if(ElementPileDePile->svt == NULL)
            Pile = NULL;
        free(ElementPileDePile);
    }

    return valDePile;
}