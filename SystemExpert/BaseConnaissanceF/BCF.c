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

BaseCO *ReadBaseCOFile() {
    BaseCO *baseCO = creerBase();
    FILE *fichier = fopen("../basefichier/baseCO.txt", "r");

    if (fichier != NULL) {
        char ligne[100];
        printf("Ouverture du fichier baseCO.txt...\n");

        while (fgets(ligne, sizeof(ligne), fichier) != NULL) {
            printf("\nRaw input line: %s\n", ligne); // Debug print

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

                printf("Nouvelle regle enregistre:\n");
                printf("Premisse: %s + %s\n", prop1->phrase, prop2->phrase);
                printf("Conclusion: %s\n", conclusion->phrase);
            } else {
                printf("Fichier BaseCO.txt mal forme.\n");
            }

            baseCO = ajoutregle(baseCO, regle);
        }

        fclose(fichier);
    } else {
        perror("Erreur lors de l'ouverture du fichier baseCO.txt");
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

    if (tetebc == NULL) {
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

