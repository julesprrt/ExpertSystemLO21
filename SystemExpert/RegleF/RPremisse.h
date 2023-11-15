#ifndef PROJETLO21_RPRÉMISSE_H
#define PROJETLO21_RPRÉMISSE_H
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

typedef struct Prop {
    char *phrase;
}Proposition;

typedef struct pElem {
    Proposition proposition;
    struct pElem *next;
    struct pElem *before;
}premElement;

typedef premElement *premisse;

typedef struct {
    premisse prem;
    Proposition *conclusion;
}Regle;

Regle *creerRegle();
void ajouterqP(preElement *premisse, Proposition prop);
Regle *ajouterprop(Regle *regle, Proposition prop);
bool appartient(preElement *premisse, Proposition prop);
Regle *suppprop(Regle *regle);
bool estVidePremisse(Regle *regle);











#endif //PROJETLO21_RPRÉMISSE_H
