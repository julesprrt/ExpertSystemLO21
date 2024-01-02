//
// Created by tomfr on 10/12/2023.
//
#include "template SDL.h"
bool init_window(SDL_Window **window,SDL_Renderer **renderer,char *window_name){
    if(SDL_Init(SDL_INIT_VIDEO) < 0){
        printf("Impossible d'initialiser la fenêtre : %s \n",SDL_GetError());
        return -1;
    }
    *window= SDL_CreateWindow(window_name,SDL_WINDOWPOS_UNDEFINED,SDL_WINDOWPOS_UNDEFINED,SCREEN_WIDTH,SCREEN_WIDTH,0);
    if(!*window){
        printf(" Impossible de creer la fenêtre : %s \n",SDL_GetError());
        return -1;
    }
    *renderer= SDL_CreateRenderer(*window,-1,SDL_RENDERER_ACCELERATED);
    if(!*renderer){
        printf(" Impossible de creer la surface : %s \n",SDL_GetError());
        return -1;
    }
    int imgFlags = IMG_INIT_JPG;
    if(! (IMG_Init( imgFlags )  & imgFlags)){
        printf("Erreur lors de l'intialisation : %s \n",IMG_GetError());
        return -1;
    }
    if (TTF_Init() == -1) {
        fprintf(stderr, "SDL_ttf could not initialize! SDL_ttf Error: %s\n", TTF_GetError());
        return -1;
    }

}
SDL_Texture *load_image(SDL_Renderer *window_renderer,char *file_path){
    SDL_Surface *optimize_surface= IMG_Load(file_path);
    SDL_Texture *texture=NULL;
    if(!optimize_surface){
        printf("Impossible de recuperer l'image : %s \n",SDL_GetError());
        return false;
    }
    texture=SDL_CreateTextureFromSurface(window_renderer,optimize_surface);
    if(!texture){
        printf("Impossible de creer la texture : %s \n",SDL_GetError());
        return false;
    }
    SDL_FreeSurface(optimize_surface);
    return texture;
}
void changement(int x,int y,int w,int l,SDL_Renderer *prenderer,SDL_Texture *pstart,SDL_Texture *background){
    SDL_RenderClear(prenderer);
    SDL_Rect back = {0,0,SCREEN_WIDTH,SCREEN_WIDTH};
    SDL_RenderCopy(prenderer,background,NULL,&back);
    if(pstart || background) {
        SDL_Rect coord = {x, y, w, l}; // coordonées où l'image est collée
        SDL_RenderCopy(prenderer, pstart, NULL, &coord); // Copiage de l'image dans la surface de notre fenetre
        SDL_RenderPresent(prenderer); // Mise à jour de la surface de notre fenetre
    }
}
void affichage_ecran(TTF_Font *font, char *text_buffer,SDL_Renderer *w_renderer,SDL_Texture *background,int y_pos){
    if(background){
        SDL_RenderClear(w_renderer);
        changement(0,0,SCREEN_WIDTH,SCREEN_WIDTH,w_renderer,NULL,background);
    }
    if(text_buffer) {
        SDL_Color textColor = {0, 0, 0, 255};
        SDL_Surface *textSurface = TTF_RenderText_Solid(font, text_buffer, textColor);
        if(textSurface) {
            SDL_Rect textRect = {120, y_pos, textSurface->w, textSurface->h};
            SDL_Texture *textTexture = SDL_CreateTextureFromSurface(w_renderer, textSurface);
            SDL_RenderCopy(w_renderer, textTexture, NULL, &textRect);
            SDL_DestroyTexture(textTexture);
            textTexture = NULL;
            SDL_RenderPresent(w_renderer);
        }
        SDL_FreeSurface(textSurface);
        textSurface = NULL;
    }
}

