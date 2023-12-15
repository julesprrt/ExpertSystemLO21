#include "RPremisse.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"

Regle *creerRegle() {
    Regle *regle = (Regle *)malloc(sizeof(Regle));
    regle->prem = NULL;
    regle->conclusion = NULL;
    return regle;
}
void ajouterproparegle(premElement **prem, Proposition prop) {
    premElement *newElem = (premElement *)malloc(sizeof(premElement));
    newElem->proposition = prop;
    newElem->next = NULL;
    newElem->before = NULL;

    if (*prem == NULL) {
        *prem = newElem;
    } else {
        premElement *tmp = *prem;
        while (tmp->next != NULL) {
            tmp = tmp->next;
        }
        tmp->next = newElem;
        newElem->before = tmp;
    }
}
Proposition creerProposition() {
    Proposition prop;
    prop.phrase = (char *)malloc(sizeof(char) * 100);
    return prop;
}


bool appartient(premElement *premisse, Proposition prop){
    if (premisse == NULL) {
        return false;
    }
    else {
        while (premisse->next != NULL) {
            if (strcmp(premisse->proposition.phrase, prop.phrase) == 0) {
                return true;
            }
            premisse = premisse->next;
        }
    }
    return false;
}

Regle *suppprop(Regle *regle,Proposition asuppProp){
    if (regle->prem == NULL) {
        return regle;
    }
    else if (strcmp(regle->prem->proposition.phrase, asuppProp.phrase) == 0) {
        premElement *tmp = regle->prem;
        regle->prem = regle->prem->next;
        free(tmp);
        return regle;
    } else {
        return suppprop(regle->prem->next, asuppProp);
    }
}
bool estVidePremisse(Regle *regle)
{
    if (regle->prem == NULL) {
        return true;
    }
    else
        return false;
}

Proposition tetepremisse(Regle *regle) {
    if (regle->prem== NULL) {
        Proposition Vide;
        Vide.phrase[0] = '\0'; //Vide
        return Vide;
    } else {
        return regle->prem->proposition; // phrase
    }
}

Proposition conclusion(Regle *regle) {
    if (regle->prem == NULL) {
        Proposition Vide;
        Vide.phrase[0] = '\0'; //Vide
        return Vide;
    }
    else {
        return *regle->conclusion;
    }
}
