#include "InferenceF.h"
#include "../BaseFaitF/BaseFait.h"
#include "../BaseConnaissanceF/BCF.h"
#include "../RegleF/RPremisse.h"

/*!
 * \file InferenceF.c
 * \brief Module qui gère l'inférence des règles trouve dans le fichier baseCo.txt et ecris des conclusions dans le fichier baseF.txt
 * @param baseF
 * @param baseCo
 * @return
 */
BaseF inference(BaseF *baseF, BaseCO *baseCo) {
if (baseF != NULL && baseCo != NULL) {
        BaseCO *tmp = baseCo;
        while (tmp != NULL) {
            if (appartient(tmp->regle->prem, baseF->prop) == true) {
                suppprop(tmp->regle, baseF->prop);
                if (estVidePremisse(tmp->regle->prem) == true) {
                    ajoutprop(baseF, *tmp->regle->conclusion);
                }
            }
            tmp = tmp->next;
        }
    }
    else {
        printf("Erreur, base de connaissance ou base de fait Vide \n");
    }
    return *baseF;
}