//
// Created by tomfr on 18/11/2023.
//
#include "regle.h"
#include "string.h"
regle *creerRegle(){
    regle *R = (regle*) malloc(sizeof(regle));
    R->conclusion=NULL;
    R->tete=NULL;
    R->queue=NULL;
    return R;
}
regle *ajoutPremisse(regle *R,prop ajout){
    premElement *newProp= (premElement *)  malloc(sizeof(premElement));
    newProp->next=NULL;
    newProp->pred=NULL;
    newProp->proposition=ajout;
    if(premisseVide(R->tete)){
        R->tete= newProp;
        R->queue= newProp;
    }
    else{
        if(R->tete==R->queue){
            (R->tete)->next=newProp;
            newProp->pred=R->tete;
            R->queue=newProp;
        }
        else{
            (R->queue)->next=newProp;
            newProp->pred=R->queue;
            R->queue=newProp;
        }
    }
    return R;
}
regle *creeConclusion(regle *R,char *titre){
    if(R->conclusion==NULL && titre){
        prop *concl =(prop*) malloc(sizeof(prop));
        concl->name=titre;
        R->conclusion=concl;
        return R;
    }
    else{
        return NULL;
    }
}
bool pDansRegle(premisse p,prop verifProp){
    if(!p){
        return false;
    }
    else{
        if(strcmp(p->proposition.name,verifProp.name)==0){
            return true;
        }
        else{
            return pDansRegle(p->next,verifProp);
        }
    }
}
bool premisseVide(premisse p){
    if(p==NULL){
        return true;
    }
    else{
        return false;
    }
}
//
//à modifier
//
regle *suppProp(regle *R, prop verifProp){
    if(R) {
        if (!premisseVide((R->tete))) {
            premElement *cp = R->tete;
            while ((strcmp(cp->proposition.name,verifProp.name)!=0) && cp->next) {
                cp = cp->next;
            }
            if ((strcmp(cp->proposition.name,verifProp.name)==0)) {
                if(R->tete==R->queue){
                    R->queue=NULL; R->tete=NULL;
                    free(cp);
                }
                else{
                    if((strcmp((cp->proposition).name,((R->tete)->proposition).name)==0)){
                        (cp->next)->pred=NULL;
                        R->tete=cp->next;
                        free(cp);
                    }
                    else{
                        if(strcmp((cp->proposition).name,((R->queue)->proposition).name)==0){
                            (cp->pred)->next=NULL;
                            R->queue=cp->pred;
                            free(cp);
                        }
                        else{
                            (cp->pred)->next =cp->next;
                            (cp->next)->pred= cp->pred;
                            free(cp);
                        }
                    }
                }
            }
        }
        else{
            printf("Erreur lors de la suppression: premisse vide \n");
        }
    }
    else{
        printf("Erreur lors de la suppression: regle indefini\n");
    }
    return R;
}
prop *accesTete(regle *R){
    if(R){
        if(!premisseVide(R->tete)) {
            return &(R->tete)->proposition;
        }
        else{
            printf("Impossible d'acceder à la tete : premisse Null ");
            return NULL;
        }
    }
    else{
        printf("Impossible d'acceder à la tete : Regle Null ");
        return NULL;
    }
}
prop *accesConclusion(regle *R){
    if(R){
        if(R->conclusion){
            return R->conclusion;
        }
        else{
            printf("Impossible d'acceder à la tete : conclusion Null ");
            return NULL;
        }
    }
    else{
        printf("Impossible d'acceder à la tete : regle Null ");
        return NULL;
    }
}