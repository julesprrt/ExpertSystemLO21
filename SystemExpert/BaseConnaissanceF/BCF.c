#include "BCF.h"
#include "../RegleF/RPremisse.h"
#include "stdlib.h"

BaseCO creerBase() {
    BaseCO *tetebc = (BaseCO *)malloc(sizeof (BaseCO));
    tetebc->next = NULL;
    tetebc->before = NULL;
    return *tetebc;
}
Proposition creerProposition() {
    Proposition prop;
    prop.phrase = (char *)malloc(sizeof(char) * 100);
    return prop;
}
/*!
 * \fn BaseCO ReadBaseCOFile()
 * \brief lire le fichier BaseConnaissance.txt et creer une base de connaissance. Dans le fichier les premisses sont separees par des + et les propositions par des =.
 * @return
 */
BaseCO ReadBaseCOFile() {
    BaseCO baseCO = creerBase();
    FILE *fichier = NULL;
    fichier = fopen("BaseConnaissance.txt", "r");
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

        }
        fclose(fichier);
    }
    return baseCO;
}

BaseCO ajoutregle(BaseCO *base, Regle *regle) {
    if (base == NULL) {
        base->regle = regle ;
        base->next = NULL;
        base->before = NULL;
    }
    else {
        BaseCO *tmp = (BaseCO *)malloc(sizeof(BaseCO));
        if (tmp != NULL) {
            tmp->regle = regle;
            tmp->next = NULL;
            tmp->before = base;

            while (base->next != NULL) {
                base = base->next;
            }
            base->next = tmp;
        }
    }
}

