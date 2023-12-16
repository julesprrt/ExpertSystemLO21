#include "BCF.h"
#include "../RegleF/RPremisse.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

BaseCO *creerBase() {
    BaseCO *tetebc = (BaseCO *)malloc(sizeof(BaseCO));
    if (tetebc == NULL) {
        perror("Erreur lors de l'allocation mémoire");
        exit(EXIT_FAILURE);
    }
    tetebc->next = NULL;
    tetebc->before = NULL;
    tetebc->regle = NULL;
    return tetebc;
}

Proposition *ajouterPhrase(Proposition *prop, const char *phrase) {
    prop->phrase = strdup(phrase);
    if (prop->phrase == NULL) {
        perror("Erreur");
        exit(EXIT_FAILURE);
    }
    return prop;
}

BaseCO *ReadBaseCOFile(const char *nomFichier) {
    BaseCO *baseCO = creerBase();
    char cheminComplet[256];
    sprintf(cheminComplet, "../basefichier/%s", nomFichier);
    FILE *fichier = fopen(cheminComplet, "r");
    if (fichier != NULL) {
        char ligne[100];
        printf("Ouverture du fichier %s...\n", nomFichier);

        while (fgets(ligne, sizeof(ligne), fichier) != NULL) {

            Regle *regle = creerRegle();
            Proposition *prop1 = (Proposition *)malloc(sizeof(Proposition));
            Proposition *prop2 = (Proposition *)malloc(sizeof(Proposition));
            Proposition *conclusion = (Proposition *)malloc(sizeof(Proposition));

            if (regle != NULL && prop1 != NULL && prop2 != NULL && conclusion != NULL) {
                char *token = strtok(ligne, "+");
                ajouterPhrase(prop1, token);

                token = strtok(NULL, "=");
                ajouterPhrase(prop2, token);

                token = strtok(NULL, "\n");
                ajouterPhrase(conclusion, token);

                regle->conclusion = conclusion;
                ajouterproparegle(&regle->prem, *prop1);
                ajouterproparegle(&regle->prem, *prop2);
            } else {
                printf("Fichier %s mal forme.\n", nomFichier);
            }

            baseCO = ajoutregle(baseCO, regle);
        }

        fclose(fichier);
    } else {
        perror("Erreur lors de l'ouverture du fichier");
    }

    return baseCO;
}

BaseCO *ajoutregle(BaseCO *tetebc, Regle *regle) {
    BaseCO *newElem = (BaseCO *)malloc(sizeof(BaseCO));
    if (newElem == NULL) {
        perror("Erreur lors de l'allocation mémoire pour une nouvelle règle");
        exit(EXIT_FAILURE);
    }
    newElem->regle = regle;
    newElem->next = NULL;
    newElem->before = NULL;

    if (tetebc->regle == NULL) {
        tetebc = newElem;
    } else {
        BaseCO *tmp = tetebc;
        while (tmp->next != NULL) {
            tmp = tmp->next;
        }
        tmp->next = newElem;
        newElem->before = tmp;
    }
    return tetebc;
}

void afficherBC(BaseCO *tetebc) {
    if (tetebc == NULL) {
        printf("Base de connaissance vide.\n");
    } else {
        while (tetebc != NULL) {
            printf("Regle : %s + %s = %s\n", tetebc->regle->prem->proposition.phrase,tetebc->regle->prem->next->proposition.phrase, tetebc->regle->conclusion->phrase);
            tetebc = tetebc->next;
        }
    }
}

