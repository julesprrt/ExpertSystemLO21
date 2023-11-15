#include "../RegleF/RPremisse.h"


#ifndef PROJETLO21_BCF_H
#define PROJETLO21_BCF_H

typedef struct BC {
    Regle regle;
    struct BC *next;
    struct BC *before;
}BaseCO;

typedef BaseCO *teteBC;



BaseCO creerBase();
BaseCO ajoutregle(BaseCO *tetebc, Regle regle);



#endif //PROJETLO21_BCF_H
