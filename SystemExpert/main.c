#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "BaseFaitF/BaseFait.h"
#include "BaseConnaissanceF/BCF.h"
#include "RegleF/RPremisse.h"
#include "Inference/InferenceF.h"
#include "JeuF/JeuFonction.h"


int main() {
    int choixSujet;
    BaseCO *baseCo = creerBase();
    BaseF baseF = creerBaseF();

    printf("   _____            __                         ______                     __ \n");
    printf("  / ___/__  _______/ /____  ____ ___  ___     / ____/  ______  ___  _____/_/ \n");
    printf("  \\__ \\/ / / / ___/ __/ _ \\/ __ `__ \\/ _ \\   / __/ | |/_/ __ \\/ _ \\/ ___/ __/ \n");
    printf(" ___/ / /_/ (__  ) /_/  __/ / / / / /  __/  / /____>  </ /_/ /  __/ /  / /_  \n");
    printf("/____/\\__, /____/\\__/\\___/_/ /_/ /_/\\___/  /_____/_/|_/ .___/\\___/_/   \\__/  \n");
    printf("      /____/                                          /_/                     \n");
    printf("\n\n");
    printf("Bienvenue dans ce systeme expert.\n");
    printf("Ce systeme propose differents themes.\n");
    printf("Apres avoir choisi un theme, veuillez saisir un ou plusieurs propositions.\n");
    printf("Le systeme ferra ses propres deductions de vos propositions et vous les soumettras.\n");
    printf("Voici les themes disponibles:\n\n\n");
    printf(("1. Les problemes de sante          2. Les couleurs               3. Les villes\n"));
    printf(("4. Les plats/ingredients           5. La meteo                   6. Les sports\n"));
    printf("7. Vous souhaitez importer votre propre base de Connaissance.  \n");
    printf("\n\n");
    printf("Veuillez choisir un theme en renseignant le numero associe: ");
    scanf("%d", &choixSujet);
    char* nomFichier = getNomFichier(choixSujet);
    baseCo = ReadBaseCOFile(nomFichier);
    printf("\n\n");
    afficherBC(baseCo);
    printf("\n\n");
    printf("Combien de faits voulez-vous entrer ?\n ");
    int nbFait;
    scanf("%d", &nbFait);
    lireFait(&baseF, nbFait);
    afficheBF(&baseF);
    baseF = inference(baseCo, &baseF);
    printf("\n\n\n\nApres calcul du moteur d'inference, voici vos nouveaux faits:\n");
    afficheBF(&baseF);
    return 0;
}