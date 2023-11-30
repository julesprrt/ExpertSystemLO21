#include "stdio.h"
#include "stdlib.h"
#include "BaseFait.h"

BaseF creerBaseF() {
    BaseF *tete = (BaseF *)malloc(sizeof (BaseF));
    tete->next = NULL;
    return *tete;
}

BaseF ajoutprop(BaseF *tetebf, Proposition prop) {
    if (tetebf == NULL) {
        tetebf->prop = prop;
        tetebf->next = NULL;
    }
    else {
        BaseF *tmp = (BaseF *)malloc(sizeof(BaseF));
        if (tmp != NULL) {
            tmp->prop = prop;
            tmp->next = NULL;

            while (tetebf->next != NULL) {
                tetebf = tetebf->next;
            }
            tetebf->next = tmp;
        }
    }
}

void afficheBF(BaseF *tetebf) {
    if (tetebf == NULL) {
        printf("La base de faits est vide.\n");
    }
    else {
        printf("La base de faits est :\n");
        while (tetebf != NULL) {
            printf("%s\n", tetebf->prop.phrase);
            tetebf = tetebf->next;
        }
    }
}