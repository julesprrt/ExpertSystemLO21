//
// Created by tomfr on 18/11/2023.
//
#include "baseCo.h"
#include "regle.h"
BC creerBase(){
    BC base = (bcElement *) malloc(sizeof(bcElement));
    base->regleBc=NULL;
    base->next=NULL;
    return base;
}
BC ajoutRegle(BC base,regle *R){
    BC newel= creerBase();
    newel->regleBc=R;
    newel->next=NULL;
    if(!base->regleBc && R!=NULL){
        return newel;
    }
    else{
        BC cmp=base;
        while(cmp->next){
            cmp = cmp->next;
        }
        cmp->next=newel;
        return base;
    }
}
regle *accesTeteBc(BC base){
    if(base){
        if(base->regleBc){
            return base->regleBc;
        }
        else{
            return NULL;
        }
    }
    else{
        return NULL;
    }
}
BC getSavedBC(char *file_path){
    FILE *base_file= fopen(file_path,"r");
    BC recup_base=creerBase();
    char recup[1000];
    char get_element[100];
    int length_element;
    if(base_file){
        int i=0;
        while(fgets(recup,1000,base_file)){
            regle *ieme_regle=creerRegle();
            //Recupération d'une regle
            while(recup[i]!=':'){
                //recuperation d'un element;
                prop *element=(prop*) malloc(sizeof(prop));
                fprintf(base_file,"%s",get_element);
                length_element=(int) strlen(get_element);
                element->name= malloc(sizeof(char)*(length_element-1));
                for(int k=0; k<length_element-1;k++){
                    element->name[k]= get_element[k];
                }
                //Ajout dans la regle
                ieme_regle= ajoutPremisse(ieme_regle,*element);
            }
            recup_base= ajoutRegle(recup_base,ieme_regle);
        }
        return recup_base;
    }
    return NULL;
}
regle *create_Regle_from_SDL(char *input_text) {
    regle *newel=creerRegle();
    char *sep="+";
    char *token=strtok(input_text,sep);
    prop new_prop;
    while (token!=NULL){
        if(strchr(token,(int)'=')){
            token = strtok(token, "=");
            new_prop.name=(char*) malloc(sizeof(strlen(token)));
            strcpy(new_prop.name,token);
            newel = ajoutPremisse(newel, new_prop);
            token = strtok(NULL, "=");
            new_prop.name=(char*) malloc(sizeof(strlen(token)));
            strcpy(new_prop.name,token);
            newel= creeConclusion(newel,new_prop.name);
            token= strtok(NULL,"=");
        }else {
            new_prop.name=(char*) malloc(sizeof(strlen(token)));
            strcpy(new_prop.name,token);
            newel = ajoutPremisse(newel, new_prop);
            token = strtok(NULL, sep);
        }
        printf("%d \n",*new_prop.name);
    }
    return newel;
}
prop *ajouter_phrase(prop *proposition, const char *phrase) {
    proposition->name = strdup(phrase);
    if (proposition->name == NULL) {
        perror("Erreur");
        exit(EXIT_FAILURE);
    }
    return proposition;
}
BC lire_base_fichier(const char *nomFichier) {
    BC baseco = creerBase();
    char cheminComplet[256];
    sprintf(cheminComplet, "../basefichier/%s", nomFichier);
    FILE *fichier = fopen(cheminComplet, "r");
    if (fichier != NULL) {
        char ligne[100];

        while (fgets(ligne, sizeof(ligne), fichier) != NULL) {

            regle *rule = creerRegle();
            prop *prop1 = (prop *)malloc(sizeof(prop));
            prop *prop2 = (prop *)malloc(sizeof(prop));
            prop *conclusion = (prop *)malloc(sizeof(prop));

            if (rule != NULL && prop1 != NULL && prop2 != NULL && conclusion != NULL) {
                char *token = strtok(ligne, "+");
                ajouter_phrase(prop1, token);

                token = strtok(NULL, "=");
                ajouter_phrase(prop2, token);

                token = strtok(NULL, "\n");
                ajouter_phrase(conclusion, token);

                rule->conclusion = conclusion;
                ajoutPremisse(rule, *prop1);
                ajoutPremisse(rule, *prop2);
            } else {
                printf("Fichier %s mal forme.\n", nomFichier);
            }

            baseco = ajoutRegle(baseco, rule);
        }

        fclose(fichier);
    } else {
        perror("Erreur lors de l'ouverture du fichier");
    }

    return baseco;
}