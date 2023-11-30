#ifndef PROJETLO21_BASEFAIT_H

#include "../RegleF/RPremisse.h"

typedef struct BF {
    premElement prop;
    struct BF *next;
}BaseF;
typedef BaseF *teteBF;

BaseF creerBaseF();
BaseF ajoutprop(BaseF *tetebf, premElement prop);
void afficheBF(BaseF *tetebf);










#define PROJETLO21_BASEFAIT_H

#endif //PROJETLO21_BASEFAIT_H
