#include <stdio.h>
#include <stdlib.h>

char* getNomFichier(int numeroSujet) {
    char* nomFichier = (char*)malloc(50 * sizeof(char));

    switch (numeroSujet) {
        case 1:
            sprintf(nomFichier, "problemesante.txt");
            break;
        case 2:
            sprintf(nomFichier, "couleur.txt");
            break;
        case 3:
            sprintf(nomFichier, "ville.txt");
            break;
        case 4:
            sprintf(nomFichier, "ingredientplat.txt");
            break;
        case 5:
            sprintf(nomFichier, "meteo.txt");
            break;
        case 6:
            sprintf(nomFichier, "sport.txt");
            break;
        case 7:
            sprintf(nomFichier, "baseCO.txt");
            break;
        default:
            printf("Numéro de sujet invalide.\n");
            free(nomFichier);
            return NULL;
    }

    return nomFichier;
}