#ifndef PROJETLO21_BASEFAIT_H

#include "../RegleF/RPremisse.h"

typedef struct BF {
    Proposition prop;
    struct BF *next;
}BaseF;
typedef BaseF *teteBF;

BaseF creerBaseF();
void ajoutprop(BaseF *tetebf, Proposition prop);
void afficheBF(BaseF *tetebf);
void lireFait(BaseF *tetebf, int nbFait);

#define PROJETLO21_BASEFAIT_H

#endif //PROJETLO21_BASEFAIT_H
