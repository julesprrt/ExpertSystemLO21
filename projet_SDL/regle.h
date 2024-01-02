//
// Created by tomfr on 18/11/2023.
//

#ifndef PROJET_LO21_REGLE_H
#define PROJET_LO21_REGLE_H
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
typedef struct{
    char *name;
}prop;
typedef struct pElem{
    prop proposition;
    struct pElem *next;
    struct pElem *pred;
}premElement;
typedef premElement *premisse;
typedef struct {
    premisse tete;
    premisse queue;
    prop *conclusion;
}regle;

regle *creerRegle();
regle *ajoutPremisse(regle *R,prop ajout);
regle *creeConclusion(regle *R,char *titre);
bool pDansRegle(premisse p,prop verifProp);
bool premisseVide(premisse p);
regle *suppProp(regle *R, prop verifProp);
prop *accesTete(regle *R);
prop *accesConclusion(regle *R);
#endif //PROJET_LO21_REGLE_H
