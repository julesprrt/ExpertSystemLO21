#include <stdio.h>
#include "baseCo.h"
#include "baseFait.h"
#include "inference.h"
#include <io.h>
#include "interface.h"
int main (int argc, char **argv){
    baseFait Fait=creerBaseFait();
    BC baseco=creerBase();
    int verif_run = menu_acceuil();
    switch (verif_run) {
        case -1:
            return -1;
            break;
        case 0:
            baseco=base_personnaliser();
            if(!baseco){
                return -1;
            }
            break;
            // recuperation des base de connaissance associer
        case 1:
            baseco= lire_base_fichier("sport.txt");
            break;
        case 2:
            baseco= lire_base_fichier("ville.txt");
            break;
        case 3:
            baseco= lire_base_fichier("musique.txt");
            break;
        case 4:
            baseco= lire_base_fichier("ingredientplat.txt");
            break;
        case 5:
            baseco= lire_base_fichier("meteo.txt");
            break;
        case 6:
            baseco= lire_base_fichier("problemesante.txt");
            break;
        case 7:
            baseco= lire_base_fichier("couleur.txt");
            break;
    }
    Fait=recup_fait();
    if(!Fait) {
        return -1;
    }
    run_inference(&Fait, &baseco);
    return 0;
}
/*
int main() {
    _setmode(_fileno(stdout), 0x00020000);
    int response;
    wprintf(L"  ┌───────────────────────────────────────┐  \n");
    wprintf(L"  |            Systeme Expert             |  \n");
    wprintf(L"  |                                       |  \n");
    wprintf(L"  |    1- ESSAI 1                         |  \n");
    wprintf(L"  |    2- ESSAI 2                         |  \n");
    wprintf(L"  |    0- Quitter                         |  \n");
    wprintf(L"  └───────────────────────────────────────┘  \n \n");
    scanf("%1d",&response);
    fflush(stdin);
    while(response <0 || response>2){
        scanf("%1d",&response);
        fflush(stdin);
    }
    if(!response){
        return 0;
    }
    else{
        BC baseCo;
        baseFait fait=creerBaseFait();
        //obention de la base de connaissance
        if(response==1){
            baseCo=getSavedBC("");
        }
        else{
            baseCo=getSavedBC("ESSAI2_FILE");
        }
        fait= lireEntrerUser(fait); // creation de la base de fait
        fait= inference(baseCo,fait); // moteur d'inference
        afficherBaseFait(fait);  // affichages des faits déduis
    }
    return 0;
}

/* Test viable
   baseFait fait=creerBaseFait();
    fait=lireEntrerUser(fait);

    BC baseCo=creerBase();
    regle *R=creerRegle();
    prop propostion;
    propostion.name="A";
    propostion.etat=true;
    R= ajoutPremisse(R,propostion);
    propostion.name="B";
    propostion.etat=true;
    R= ajoutPremisse(R,propostion);
    propostion.name="C";
    propostion.etat=true;
    R= creeConclusion(R,"C",true);
    baseCo=ajoutRegle(baseCo,R);
    fait=inference(baseCo,fait);
    afficherBaseFait(fait);
 */
