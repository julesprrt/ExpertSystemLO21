#include "BCF.h"
#include "../RegleF/RPremisse.h"
#include "stdlib.h"

BaseCO creerBase() {
    BaseCO *tetebc = (BaseCO *)malloc(sizeof (BaseCO));
    tetebc->next = NULL;
    tetebc->before = NULL;
    return *tetebc;
}

BaseCO ajoutregle(BaseCO *base, Regle regle) {
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

