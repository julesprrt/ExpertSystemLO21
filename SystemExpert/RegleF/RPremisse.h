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
Proposition creerProposition(); // Pour creer prop ET conclusion
Regle *ajouterprop(Regle *regle, Proposition prop);
bool appartient(premElement *premisse, Proposition prop);
Regle *suppprop(Regle *regle,Proposition asuppProp);
bool estVidePremisse(Regle *regle);
Proposition tetepremisse (Regle *regle);
Proposition conclusion(Regle *regle);










#endif //PROJETLO21_RPRÉMISSE_H
