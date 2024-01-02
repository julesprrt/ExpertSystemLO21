//
// Created by tomfr on 18/11/2023.
//
#include "inference.h"

baseFait inference(BC base,baseFait Fait){
    if (Fait){
        if(base){
            bfElement *cmpFait = Fait;
            BC cmpBc = NULL;

            while (cmpFait){
                cmpBc=base;
                while (cmpBc){
                    if(!premisseVide( cmpBc->regleBc->tete)) {
                        if (pDansRegle(cmpBc->regleBc->tete, *cmpFait->input) == true) {
                            suppProp(cmpBc->regleBc, *cmpFait->input);
                            if (premisseVide(cmpBc->regleBc->tete)) {
                                Fait = ajoutFile(Fait, cmpBc->regleBc->conclusion);
                            }
                        }
                    }
                    cmpBc= cmpBc->next;
                }
                cmpFait = cmpFait->next;
            }
        }
        else{
            printf("Erreur, base de connaissance Vide \n");
        }
    }
    else{
        printf("Erreur, base de fait Vide \n");
    }
    return Fait;
}