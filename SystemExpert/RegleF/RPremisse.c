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

void ajouterqP(premElement *premisse, Proposition prop)
{
    premElement *nvprop = (premElement *)malloc(sizeof(premElement));
    if (nvprop == NULL) {
        exit(EXIT_FAILURE);
    }
    nvprop->proposition = prop;
    nvprop->next = NULL;

    if (premisse == NULL) {
        premisse = nvprop;
    } else {
        // parcours de la premisse
        premElement *tmp = premisse;
        while (tmp->next != NULL) {
            tmp = tmp->next;
        }
        tmp->next = nvprop;
        nvprop->before = tmp;
    }
}

Regle *ajouterprop(Regle *regle, Proposition prop) {
    ajouterqP(&(regle->prem), prop);
    return regle;
}

bool appartient(premElement *premisse, Proposition prop){
    if (premisse == NULL) {
        return false;
    }
    else if (strcmp(premisse->proposition.phrase, prop.phrase) == 0) {
        return true;
    } else {
        return appartient(premisse->next, prop);
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
