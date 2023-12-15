#include "InferenceF.h"
#include "../BaseFaitF/BaseFait.h"
#include "../BaseConnaissanceF/BCF.h"
#include "../RegleF/RPremisse.h"

BaseF inference(BaseCO *baseCo, BaseF *baseF) {
    if (baseF != NULL) {
        if (baseCo != NULL) {
            BaseF *tmpFait = baseF;
            BaseCO *tmpBc = NULL;

            while (tmpFait != NULL) {
                tmpBc = baseCo;
                while (tmpBc != NULL) {
                    if (!estVidePremisse(tmpBc->regle)) {
                        if (appartient(tmpBc->regle->prem, tmpFait->prop)) {
                            suppprop(tmpBc->regle, tmpFait->prop);
                            if (estVidePremisse(tmpBc->regle)) {
                                ajoutprop(baseF, *tmpBc->regle->conclusion);
                            }
                        }
                    }
                    tmpBc = tmpBc->next;
                }
                tmpFait = tmpFait->next;
            }
        }
        else {
            printf("La base de connaissance est vide. \n");
        }
    }
    else {
        printf("La base de fait est vide.\n");
    }
    return *baseF;
}