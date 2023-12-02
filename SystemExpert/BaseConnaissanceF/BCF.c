#include "BCF.h"
#include "../RegleF/RPremisse.h"
#include "stdlib.h"

BaseCO creerBase() {
    BaseCO *tetebc = (BaseCO *)malloc(sizeof (BaseCO));
    tetebc->next = NULL;
    tetebc->before = NULL;
    return *tetebc;
}

void ecrirebaseCO() {
    printf("Veuillez ecrire 5 regles.\n");
    printf("Voici le format a respecter :\n");
    printf("Exemple dune regle : {A+B=C}.\n");
    FILE *fichier = NULL;
    fichier = fopen("basefichier/baseCO.txt", "w");
    if (fichier != NULL)
    {
        for (int i = 0; i < 6 ; i++) {
            char ligne[100];
            printf("Veuillez saisir la %deme regle :\n");
            scanf("%s",ligne);
            if (strlen(ligne) > 5) {
                printf("Erreur, la regle est trop longue.\n");
                exit(EXIT_FAILURE);
            }
            fputs(ligne,fichier);
            printf("Merci. %deme bien saisie.");

        }
    }
    fclose(fichier);


}

BaseCO ReadBaseCOFile() {
    BaseCO baseCO = creerBase();
    FILE *fichier = NULL;
    fichier = fopen("basefichier/baseCO.txt", "r");
    if (fichier != NULL) {
        char ligne[100];
        while (fgets(ligne, 100, fichier) != NULL) {
            Regle *regle = creerRegle();
            Proposition prop1 = creerProposition();
            Proposition prop2 = creerProposition();
            Proposition conclusion = creerProposition();
            if (sscanf(ligne, "%s+%s=%s\n", prop1.phrase, prop2.phrase, conclusion.phrase) == 3) {
                ajouterprop(regle, prop1);
                ajouterprop(regle, prop2);
                *regle->conclusion = conclusion;
            }
            else {
                perror("Fichier BaseCO.txt mal formé.");
            }
            ajoutregle(&baseCO,regle); // TO DO : a fixer

        }
        fclose(fichier);
    }
    return baseCO;
}

BaseCO ajoutregle(BaseCO *tetebc, Regle *regle) {
    if (tetebc == NULL) {
        tetebc->regle = regle ;
        tetebc->next = NULL;
        tetebc->before = NULL;
    }
    else {
        BaseCO *tmp = (BaseCO *)malloc(sizeof(BaseCO));
        if (tmp != NULL) {
            tmp->regle = regle;
            tmp->next = NULL;
            tmp->before = tetebc;

            while (tetebc->next != NULL) {
                tetebc = tetebc->next;
            }
            tetebc->next = tmp;
        }
    }
}

