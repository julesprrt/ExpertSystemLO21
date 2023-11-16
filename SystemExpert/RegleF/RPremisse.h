#include "stdbool.h"

#ifndef PROJETLO21_RPRÉMISSE_H
#define PROJETLO21_RPRÉMISSE_H

typedef struct Prop {
    char phrase[255];
}Proposition;

typedef struct LP {
    Proposition proposition;
    struct LP *next;
    struct LP *before;
}ListeProp;

typedef ListeProp *premisse;

typedef struct R{
    ListeProp *premisse;
    Proposition *conclusion;
}Regle;

Regle *creerRegle();
void ajouterqP(ListeProp **premisse, Proposition prop);
Regle *ajouterprop(Regle *regle, Proposition prop);
bool appartient(ListeProp *premisse, Proposition prop);
Regle *suppprop(Regle *regle);
bool estVidePremisse(Regle *regle);
Proposition teteregle (Regle *regle);
Proposition *conclusion(Regle *regle);










#endif //PROJETLO21_RPRÉMISSE_H