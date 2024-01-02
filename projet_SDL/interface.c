//
// Created by tomfr on 23/12/2023.
//
#include "interface.h"
int menu_acceuil() {
    //Declaration variable elementaire de la fenetre
    SDL_Window *window = NULL;
    SDL_Renderer *w_renderer = NULL;
    SDL_Texture *background_texture = NULL;
    SDL_Texture *w_texture = NULL;
    //initialisation de la fenetre
    init_window(&window, &w_renderer, "Système Expert");
    background_texture = load_image(w_renderer, "../image/1.jpg");
    changement(0, 0, SCREEN_WIDTH, SCREEN_WIDTH, w_renderer, NULL, background_texture);

    // Récuperation de l'emplacement des boutons de la fenètre
    SDL_Rect baseco[8]={{84, 475, 159, 65}, //coord sport
                        {297, 475, 159, 65}, // coord ville
                        {513, 475, 159, 65}, // coord musique
                        {64, 590, 196, 79}, // coord plat
                        {297, 604, 159, 66}, // coord meteo
                        {496, 591, 192, 79}, // coord santé
                        {196, 707, 154, 64}, // coord couleur
                        {429, 707, 161, 64}}; // coord perso

    SDL_Point cursor = {0, 0};
    bool motion = false;
    bool quit=false;
    int return_value=0;
    SDL_Event menu;
    while (!quit) {
        while(SDL_PollEvent(&menu) != 0) {
            SDL_GetMouseState(&cursor.x, &cursor.y);
            switch (menu.type) {
                case SDL_QUIT:
                    quit=true;
                    return_value=-1;
                    break;
                case SDL_MOUSEMOTION:
                    if(motion && !SDL_PointInRect(&cursor,&baseco[7]) && !SDL_PointInRect(&cursor,&baseco[0]) && !SDL_PointInRect(&cursor,&baseco[1])
                    && !SDL_PointInRect(&cursor,&baseco[2])&& !SDL_PointInRect(&cursor,&baseco[3])&& !SDL_PointInRect(&cursor,&baseco[4])
                    && !SDL_PointInRect(&cursor,&baseco[5]) && !SDL_PointInRect(&cursor,&baseco[6])) {
                        if (w_texture) {
                            SDL_DestroyTexture(w_texture);
                            w_texture = NULL;
                            SDL_RenderClear(w_renderer);
                            changement(0, 0, SCREEN_WIDTH, SCREEN_WIDTH, w_renderer, NULL, background_texture);
                            SDL_RenderPresent(w_renderer);
                            motion = false;
                        }
                    }else{

                        if (SDL_PointInRect(&cursor, &baseco[0])) {
                                if ((w_texture = load_image(w_renderer, "../image/sport.jpg"))) {
                                    changement(baseco[0].x, baseco[0].y, baseco[0].w, baseco[0].h, w_renderer, w_texture,
                                               background_texture);
                                    motion = true;
                                    break;
                                }
                        } else if (SDL_PointInRect(&cursor, &baseco[1])) {
                            if ((w_texture = load_image(w_renderer, "../image/ville.jpg"))) {
                                changement(baseco[1].x, baseco[1].y, baseco[1].w, baseco[1].h, w_renderer, w_texture,
                                           background_texture);
                                motion = true;
                                break;
                            }
                        } else if (SDL_PointInRect(&cursor, &baseco[2])) {
                            if ((w_texture = load_image(w_renderer, "../image/musique.jpg"))) {
                                changement(baseco[2].x, baseco[2].y, baseco[2].w, baseco[2].h, w_renderer, w_texture,
                                           background_texture);
                                motion = true;
                                break;
                            }
                        } else if (SDL_PointInRect(&cursor, &baseco[3])) {
                            if ((w_texture = load_image(w_renderer, "../image/ingred.jpg"))) {
                                changement(baseco[3].x, baseco[3].y, baseco[3].w, baseco[3].h, w_renderer,
                                           w_texture,
                                           background_texture);
                                motion = true;
                                break;
                            }
                        } else if (SDL_PointInRect(&cursor, &baseco[4])) {
                            if ((w_texture = load_image(w_renderer, "../image/meteo.jpg"))) {
                                changement(baseco[4].x, baseco[4].y, baseco[4].w, baseco[4].h, w_renderer, w_texture,
                                           background_texture);
                                motion = true;
                                break;
                            }
                        } else if (SDL_PointInRect(&cursor, &baseco[5])) {
                            if ((w_texture = load_image(w_renderer, "../image/probleme.jpg"))) {
                                changement(baseco[5].x, baseco[5].y, baseco[5].w, baseco[5].h, w_renderer, w_texture,
                                           background_texture);
                                motion = true;
                                break;
                            }
                        } else if (SDL_PointInRect(&cursor, &baseco[6])) {
                            if ((w_texture = load_image(w_renderer, "../image/couleur.jpg"))) {
                                changement(baseco[6].x, baseco[6].y, baseco[6].w, baseco[6].h, w_renderer,w_texture, background_texture);
                                motion = true;
                                break;
                            }
                        }else if(SDL_PointInRect(&cursor, &baseco[7])){
                            if ((w_texture = load_image(w_renderer, "../image/base.jpg"))) {
                                changement(baseco[7].x, baseco[7].y, baseco[7].w, baseco[7].h, w_renderer,w_texture, background_texture);
                                motion = true;
                                break;
                            }
                        }
                    }
                break;
                case SDL_MOUSEBUTTONUP:
                    if(SDL_PointInRect(&cursor,&baseco[7])){
                        quit=true;
                        return_value=0;
                    }
                    if (SDL_PointInRect(&cursor, &baseco[0])) {
                        quit=true;
                        return_value=1;
                    } else if (SDL_PointInRect(&cursor, &baseco[1])) {
                        quit=true;
                        return_value=2;
                    } else if (SDL_PointInRect(&cursor, &baseco[2])) {
                        quit=true;
                        return_value=3;
                    } else if (SDL_PointInRect(&cursor, &baseco[3])) {
                        quit=true;
                        return_value=4;
                    } else if (SDL_PointInRect(&cursor, &baseco[4])) {
                        quit=true;
                        return_value=5;
                    } else if (SDL_PointInRect(&cursor, &baseco[5])) {
                        quit=true;
                        return_value=6;
                    } else if (SDL_PointInRect(&cursor, &baseco[6])) {
                        quit=true;
                        return_value=7;
                    }
            }
        }
        SDL_Delay(50);
    }
    clean_data(window,w_renderer,background_texture,w_texture);
    return return_value;
}

void clean_data(SDL_Window *window,SDL_Renderer *w_renderer,SDL_Texture *background_texture,SDL_Texture *w_texture){
    SDL_DestroyTexture(background_texture);
    background_texture = NULL;
    SDL_DestroyTexture(w_texture);
    w_texture = NULL;
    SDL_DestroyRenderer(w_renderer);
    w_renderer = NULL;
    SDL_DestroyWindow(window);
    window=NULL;
}
BC base_personnaliser(){
    // declarationdes variables necéssaire
    SDL_Window *window = NULL;
    SDL_Renderer *w_renderer = NULL;
    SDL_Texture *background_texture = NULL;
    SDL_Texture *w_texture = NULL;
    SDL_Event event;

    //chargement de la police
    TTF_Font* font = TTF_OpenFont("../image/police.ttf", 18);
    if (font == NULL) {
        fprintf(stderr, "Failed to load font! SDL_ttf Error: %s\n", TTF_GetError());
        TTF_Quit();
        return NULL;
    }

    //initialisation de la fenetre
    init_window(&window, &w_renderer, "Base de connaissance");
    background_texture = load_image(w_renderer, "../image/2bis.jpg");
    changement(0, 0, SCREEN_WIDTH, SCREEN_WIDTH, w_renderer, NULL, background_texture);

    //objets de la fenètre :
    SDL_Point cursor={0,0};
    SDL_Rect end={598,692,160,67};
    bool motion = false;
    bool running;
    bool end_entry=false;
    BC baseco=creerBase();

    // boucle principale
    while(!end_entry) {
        running=true;
        char* inputText = NULL;
        char textBuffer[256] = { 0 };
        while (running) {
            while (SDL_PollEvent(&event) != 0) {
                SDL_GetMouseState(&cursor.x,&cursor.y);
                if (event.type == SDL_QUIT) {
                    return NULL;
                }else if(SDL_PointInRect(&cursor,&end)){
                    if(event.type == SDL_MOUSEMOTION){
                        if(!motion) {
                            if ((w_texture = load_image(w_renderer, "../image/fin.jpg"))) {
                                changement(end.x, end.y, end.w, end.h, w_renderer, w_texture, background_texture);
                                motion=true;
                                break;
                            }
                        }
                    }else if(event.type == SDL_MOUSEBUTTONUP){
                        end_entry=true;
                        running=false;
                    }
                }else if (event.type == SDL_TEXTINPUT) {
                    strcat(textBuffer, event.text.text);
                    affichage_ecran(font, textBuffer, w_renderer, NULL, 345);
                } else if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_RETURN) {
                    inputText = (char *) malloc(strlen(textBuffer) + 1);
                    strcpy(inputText, textBuffer);
                    running = false;
                    affichage_ecran(font,NULL,w_renderer,background_texture,345);
                } else if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_BACKSPACE &&
                           strlen(textBuffer) > 0) {
                    textBuffer[strlen(textBuffer) - 1] = 0;
                    affichage_ecran(font, textBuffer, w_renderer, background_texture, 345);
                }else{
                    motion=false;
                }
            }
            SDL_Delay(50);
        }
        if(!end_entry) {
            regle *newel = create_Regle_from_SDL(inputText);
            baseco = ajoutRegle(baseco, newel);
        }
        free(inputText);
    }
    clean_data(window,w_renderer,background_texture,w_texture);

    return baseco;
}
baseFait recup_fait(){
    SDL_Window *window = NULL;
    SDL_Renderer *w_renderer = NULL;
    SDL_Texture *background_texture = NULL;
    SDL_Texture *w_texture = NULL;
    SDL_Event event;

    //chargment de la police
    TTF_Font* font = TTF_OpenFont("../image/police.ttf", 18);
    if (font == NULL) {
        fprintf(stderr, "Failed to load font! SDL_ttf Error: %s\n", TTF_GetError());
        TTF_Quit();
        return NULL;
    }

    bool running;
    bool end_entry=false;
    baseFait Fait=creerBaseFait();

    //initialisation de la fenetre + chargement fond
    init_window(&window, &w_renderer, "Récuperation des faits");
    background_texture = load_image(w_renderer, "../image/2.jpg");
    changement(0, 0, SCREEN_WIDTH, SCREEN_WIDTH, w_renderer, NULL, background_texture);

    //objets de la fenètre :
    SDL_Point cursor={0,0};
    SDL_Rect end={598,692,160,67};

    // boucle principale
    while(!end_entry) {
        running=true;
        char* inputText = NULL;
        char textBuffer[256] = { 0 };
        prop *ajout=(prop *) malloc(sizeof(prop));
        while (running) {
            while (SDL_PollEvent(&event) != 0) {
                SDL_GetMouseState(&cursor.x,&cursor.y);
                if (event.type == SDL_QUIT) {
                    return NULL;
                }else if(SDL_PointInRect(&cursor,&end)){
                    if(event.type == SDL_MOUSEMOTION){
                        if ((w_texture = load_image(w_renderer, "../image/inference.jpg"))) {
                            changement(end.x,end.y, end.w, end.h, w_renderer,w_texture, background_texture);
                            break;
                        }
                    }else if(event.type == SDL_MOUSEBUTTONUP){
                        end_entry=true;
                        running=false;
                    }

                }else if (event.type == SDL_TEXTINPUT) {
                    strcat(textBuffer, event.text.text);
                    affichage_ecran(font, textBuffer, w_renderer, NULL, 345);
                } else if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_RETURN) {
                    inputText = (char *) malloc(strlen(textBuffer) + 1);
                    strcpy(inputText, textBuffer);
                    running = false;
                    affichage_ecran(font,NULL,w_renderer,background_texture,345);
                } else if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_BACKSPACE &&
                           strlen(textBuffer) > 0) {
                    textBuffer[strlen(textBuffer) - 1] = 0;
                    affichage_ecran(font, textBuffer, w_renderer, background_texture, 345);
                }
            }
            SDL_Delay(50);
        }
        if(!end_entry) {
            ajout->name=(char*) malloc(sizeof(strlen(inputText)));
            strcpy(ajout->name,inputText);
            Fait = ajoutFile(Fait,ajout);
        }
        free(inputText);
    }
    clean_data(window,w_renderer,background_texture,w_texture);

    return Fait;
}
void run_inference(baseFait *Fait, BC *connaissance){
    SDL_Window *window = NULL;
    SDL_Renderer *w_renderer = NULL;
    SDL_Texture *background_texture = NULL;
    SDL_Texture *w_texture = NULL;

    //initialisation de la fenetre + affichage fond
    init_window(&window, &w_renderer, "Récuperation des faits");
    background_texture = load_image(w_renderer, "../image/3.jpg");
    changement(0, 0, SCREEN_WIDTH, SCREEN_WIDTH, w_renderer, NULL, background_texture);

    // chargement de la police

    TTF_Font* font = TTF_OpenFont("../image/police.ttf", 18);
    if (font == NULL) {
        fprintf(stderr, "Failed to load font! SDL_ttf Error: %s\n", TTF_GetError());
        TTF_Quit();
        return;
    }

    int y_pos=305;
    SDL_Point cursor={0,0};
    SDL_Rect end={598,692,160,67};
    baseFait res_inference;

    //Recupération du resultat de l'inference
    res_inference= inference(*connaissance,*Fait);
    while(res_inference){
        affichage_ecran(font,res_inference->input->name,w_renderer,NULL,y_pos);
        y_pos+=20;
        res_inference=res_inference->next;
    }
    bool quit=false;
    SDL_Event event;
    while(!quit){
        SDL_GetMouseState(&cursor.x,&cursor.y);
        if(SDL_PollEvent(&event) != 0){
            if(event.type==SDL_QUIT){
                quit=true;
            }else if(SDL_PointInRect(&cursor,&end)){
                if(event.type==SDL_MOUSEBUTTONUP){
                    quit=true;
                }
            }

        }
        SDL_Delay(50);
    }
    clean_data(window,w_renderer,background_texture,w_texture);
}