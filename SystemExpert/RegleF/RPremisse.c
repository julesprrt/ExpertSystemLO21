#include "RPremisse.h"
#include <stdlib.h>
#include <stdio.h>
#include "stdbool.h"
#include "string.h"


Regle *creerRegle() {
    Regle *regle = (Regle *)malloc(sizeof(Regle));
    regle->premisse = NULL;
    regle->conclusion = NULL;
    return regle;
}

void ajouterqP(ListeProp **premisse, Proposition prop)
{
    ListeProp *nvprop = (ListeProp *)malloc(sizeof(ListeProp));
    if (nvprop == NULL) {
        exit(EXIT_FAILURE);
    }
    nvprop->proposition = prop;
    nvprop->next = NULL;

    if (*premisse == NULL) {
        *premisse = nvprop;
    } else {
        // parcours de la premisse
        ListeProp *tmp = *premisse;
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

bool appartient(ListeProp *premisse, Proposition prop) {
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
    if (regle->premisse == NULL) {
        return regle;
    }
    else if (regle->premisse->next == NULL) {
        return NULL;
    }
    else {
        Regle *tmp = regle;
        while (tmp->premisse->next != NULL) {
            tmp = tmp->premisse->next;
        }
        tmp->premisse->before->next = NULL; // fais pointer avant dernier sur null
        free(tmp->premisse); // supp dernier

    }
}

bool estVidePremisse(Regle *regle)
{
    if (regle->premisse == NULL) {
        return true;
    }
    else
        return false;
}
Proposition teteregle(Regle *regle) {
    if (regle->premisse == NULL) {
        Proposition Vide;
        Vide.phrase[0] = '\0'; //Vide
        return Vide;
    } else {
        return regle->premisse->proposition; // phrase
    }
}

Proposition *conclusion(Regle *regle) {
    if (regle == NULL) {
        Proposition Vide;
        Vide.phrase[0] = '\0'; //Vide
    }
    else {
        return regle->conclusion;
    }
}
