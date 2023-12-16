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
        if (strcmp(premisse->proposition.phrase, prop.phrase) == 0) {
            return true;
        }
        else {
            return appartient(premisse->next, prop);
        }
    }
}
void suppprop(Regle *regle, Proposition asuppProp) {
    if(regle) {

        if (!estVidePremisse(regle)) {
            premElement *current = regle->prem;
            premElement *previous = NULL;
            while (current != NULL && strcmp(current->proposition.phrase, asuppProp.phrase) != 0) {
                previous = current;
                current = current->next;
            }
            if (current != NULL) {
                if (previous == NULL) {
                    regle->prem = current->next;
                } else {
                    previous->next = current->next;
                }
                current->proposition.phrase = NULL;
                current->next = NULL;
                free(current);
            }
        } else {
            printf("Erreur lors de la suppression: premisse vide \n");
        }
    } else {
        printf("Erreur lors de la suppression: regle indefini\n");
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
