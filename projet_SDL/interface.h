//
// Created by tomfr on 23/12/2023.
//

#ifndef PROJET_LO21_INTERFACE_H
#define PROJET_LO21_INTERFACE_H
#include "template SDL.h"
#include "baseCo.h"
#include "baseFait.h"
#include "inference.h"
int menu_acceuil();
BC base_personnaliser();
baseFait recup_fait();
void run_inference(baseFait *Fait, BC *connaissance);
void clean_data(SDL_Window *window,SDL_Renderer *w_renderer,SDL_Texture *background_texture,SDL_Texture *w_texture);
#endif //PROJET_LO21_INTERFACE_H
