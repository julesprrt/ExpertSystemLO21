#include "BCF.h"
#include "../RegleF/RPremisse.h"
#include "stdlib.h"

BaseCO *creerBase() {
    BaseCO *tetebc = (BaseCO *)malloc(sizeof (BaseCO));
    tetebc->next = NULL;
    tetebc->before = NULL;
    return tetebc;
}
Proposition *ajouterPhrase(Proposition *prop, char *phrase) {
    prop->phrase = phrase;
    return prop;
};
/*void ecrirebaseCO() {
    printf("Veuillez ecrire 5 regles.\n");
    printf("Voici le format a respecter :\n");
    printf("Exemple dune regle : {A+B=C}.\n");
    FILE *fichier = NULL;
    fichier = fopen("basefichier/baseCO.txt", "w");
    if (fichier != NULL)
    {
        for (int i = 0; i < 5 ; i++) {
            char ligne[100];
            printf("Veuillez saisir la %deme regle :\n",i+1);
            scanf("%s",ligne);
            if (strlen(ligne) > 5) {
                printf("Erreur, la regle est trop longue.\n");
                exit(EXIT_FAILURE);
            }
            fprintf(fichier,ligne);
            fprintf(fichier,"\n");
            printf("Merci. %deme bien saisie.",i+1);

        }
    }
    fclose(fichier);


}*/
BaseCO *ReadBaseCOFile() {
    BaseCO *baseCO = creerBase();
    FILE *fichier = NULL;
    fichier = fopen("../basefichier/baseCO.txt", "r");
    printf("Ouverture du fichier baseCO.txt...\n");
    if (fichier != NULL) {
        char ligne[100];
        printf("Lecture du fichier baseCO.txt...\n");
        while (fgets(ligne, 100, fichier) != NULL) {

            Regle *regle = creerRegle();
            Proposition prop1 = creerProposition();
            Proposition prop2 = creerProposition();
            Proposition conclusion = creerProposition();

            if (ligne[1] == '+' && ligne[3] == '=') {
                prop1.phrase = strtok(ligne, "+");
                prop2.phrase = strtok(NULL, "=");
                conclusion.phrase = strtok(NULL, "\n");
                regle = ajouterprop(regle, prop1);
                regle = ajouterprop(regle, prop2);
                regle->conclusion = &conclusion;
                printf("Nouvelle regle enregistrée : \n");
                printf("Premisse : %s + %s\n", prop1.phrase, prop2.phrase);

                }
            else {
                perror("Fichier BaseCO.txt mal formé.");
            }
            ajoutregle(baseCO,regle);
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
void afficherBC(BaseCO *tetebc) {
    if (tetebc == NULL) {
        printf("Base de connaissance vide.\n");
    }
    else {
        while (tetebc != NULL) {
            printf("Premisse : ");
            premElement *tmp = tetebc->regle->prem;
            while (tmp != NULL) {
                printf("%s ", tmp->proposition.phrase);
                tmp = tmp->next;
            }
            printf("\nConclusion : %s\n", tetebc->regle->conclusion->phrase);
            tetebc = tetebc->next;
        }
    }
}

