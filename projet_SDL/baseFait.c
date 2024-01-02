//
// Created by tomfr on 23/11/2023.
//
#include "baseFait.h"
baseFait ajoutFile(baseFait Fait, prop *ajout){
    bfElement *newel=(bfElement*) malloc(sizeof(bfElement));
    newel->input= ajout;
    newel->next=NULL;
    if(!Fait){
        return NULL;
    }
    else{
        if(!Fait->input){
            return newel;
        }
        else {
            baseFait cmp = Fait;
            while (cmp->next) {
                cmp = cmp->next;
            }
            cmp->next = newel;
            return Fait;
        }
    }
}
void afficherBaseFait(baseFait Fait){
    if(Fait){
        baseFait cmp=Fait;
        while(cmp){
            printf("nom: %s",(cmp->input)->name);
            printf("\n");
            cmp=cmp->next;
        }
    }
}
baseFait creerBaseFait(){
    baseFait fait=(bfElement*) malloc(sizeof(bfElement));
    fait->next=NULL;
    fait->input=NULL;
    return fait;
}
baseFait lireEntrerUser(baseFait Fait){
    int number_fait=0;
    printf(" Veuillez entrez le nombre de faits observes :  ");
    scanf("%d",&number_fait);
    fflush(stdin);
    for(int i=0;i<number_fait;i++){
        prop *fait=(prop*) malloc(sizeof(prop));
        fait->name=(char *) malloc(sizeof(char)*20);
        printf("\n Fait numéro %d:   \n",i+1);
        printf("Nom : ");
        scanf("%s",fait->name);
        fflush(stdin);
        Fait= ajoutFile(Fait,fait);
    }
    return Fait;
}