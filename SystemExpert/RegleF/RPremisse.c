#include "RPremisse.h"

Regle *creerRegle() {
    Regle *regle = (Regle *)malloc(sizeof(Regle));
    regle->prem = NULL;
    regle->conclusion = NULL;
    return regle;
}

void ajouterqP(premisse *prem, Proposition prop)
{
    premElement *nvprop = (premElement *)malloc(sizeof(premElement));
    if (nvprop == NULL) {
        exit(EXIT_FAILURE);
    }
    nvprop->proposition = prop;
    nvprop->next = NULL;

    if (prem == NULL) {
        prem = nvprop;
    } else {
        // parcours de la premisse
        premElement *tmp = prem;
        while (tmp->next != NULL) {
            tmp = tmp->next;
        }
        tmp->next = nvprop;
        nvprop->before = tmp;
    }
}

Regle *ajouterprop(Regle *regle, Proposition prop) {
    ajouterqP(&(regle->premisse), prop);
    return regle;
}

bool appartient(premisse *prem, Proposition prop) {
    if (prem == NULL) {
        return false;
    }
    else if (strcmp(premisse->proposition.phrase, prop.phrase) == 0) {
        return true;
    } else {
        return appartient(prem->next, prop);
    }
}
// SUPPRIME QUE EN QUEUE PR INSTANT
Regle *suppprop(Regle *regle) {
    if (regle->prem == NULL) {
        return regle;
    }
    else if (regle->prem->next == NULL) {
        free(regle->prem);
        return NULL;
    }
    else {
        Regle *tmp = regle;
        while (tmp->prem->next != NULL) {
            tmp = tmp->prem->next;
        }
        tmp->prem->before->next = NULL; // fais pointer avant dernier sur null
        free(tmp->prem); // supp dernier

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
