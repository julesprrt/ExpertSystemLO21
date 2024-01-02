//
// Created by tomfr on 23/11/2023.
//

#ifndef PROJET_LO21_BASEFAIT_H
#define PROJET_LO21_BASEFAIT_H
#include "regle.h"
typedef struct queue{
    prop *input;
    struct queue *next;
}bfElement;
typedef bfElement *baseFait;
baseFait ajoutFile(baseFait Fait, prop *ajout);
baseFait creerBaseFait();
void afficherBaseFait(baseFait Fait);
baseFait lireEntrerUser(baseFait Fait);
#endif //PROJET_LO21_BASEFAIT_H
