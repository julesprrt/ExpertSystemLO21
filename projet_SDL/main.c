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
    TTF_Quit();
    IMG_Quit();
    SDL_Quit();
    return 0;
}