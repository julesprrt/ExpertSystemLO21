//
// Created by tomfr on 18/11/2023.
//

#ifndef PROJET_LO21_BASECO_H
#define PROJET_LO21_BASECO_H
#include "regle.h"
#include <string.h>
#include <ctype.h>
typedef struct bcElem{
    regle *regleBc;
    struct bcElem *next;
}bcElement;
typedef bcElement *BC;

BC creerBase();
BC ajoutRegle(BC base,regle *R);
regle *accesTeteBc(BC base);
regle *create_Regle_from_SDL(char *input_text);
prop *ajouter_phrase(prop *proposition, const char *phrase);
BC lire_base_fichier(const char *nomFichier);
#endif //PROJET_LO21_BASECO_H
