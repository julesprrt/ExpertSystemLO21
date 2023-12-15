#include "stdio.h"
#include "stdlib.h"
#include "BaseFait.h"
/*!
 * \file BaseFait.c
 * \brief creer une base de Fait
 * @return
 */
BaseF creerBaseF() {
    BaseF *tetebf = (BaseF *)malloc(sizeof(BaseF));
    tetebf->prop.phrase = NULL;
    tetebf->next = NULL;
    return *tetebf;
}

 /*!
 * \fn BaseF ajoutprop(BaseF *tetebf, Proposition prop)
 * \brief ajouter une proposition dans la base de fait
 * @param tetebf
 * @param prop
 * @return
 */
 void ajoutprop(BaseF *tetebf, Proposition prop) {
     if (tetebf->prop.phrase == NULL) {
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

/*!
 * \fn void afficheBF(BaseF *tetebf)
 * \brief afficher la base de fait
 * @param tetebf
 */
void afficheBF(BaseF *tetebf) {
    if (tetebf == NULL) {
        printf("Base de fait vide.\n");
    }
    else {
        printf("La base de faits est : \n");
        while (tetebf != NULL) {
            printf("%s\n", tetebf->prop.phrase);
            tetebf = tetebf->next;
        }
    }
}
/*!
 * \fn void lireFait(BaseF *tetebf)
 * \brief lire les faits
 * @param tetebf
 */
void lireFait(BaseF *tetebf) {
    for (int i = 0; i < 2; i++) {
        printf("Veuillez entrer une proposition : \n");
        char *phrase = (char *) malloc(sizeof(char) * 100);
        scanf("%s", phrase);
        Proposition prop;
        prop.phrase = phrase;
        ajoutprop(tetebf, prop);
    }
}