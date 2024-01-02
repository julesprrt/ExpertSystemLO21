//
// Created by tomfr on 18/12/2023.
//

#ifndef PROJET_LO21_TEMPLATE_SDL_H
#define PROJET_LO21_TEMPLATE_SDL_H
#include "SDL.h"
#include "SDL_image.h"
#include <stdbool.h>
#include <stdio.h>
#include "SDL_ttf.h"
#define SCREEN_WIDTH 800
bool init_window(SDL_Window **window,SDL_Renderer **renderer,char *window_name);
void changement(int x,int y,int w,int l,SDL_Renderer *prenderer,SDL_Texture *pstart,SDL_Texture *background);
SDL_Texture * load_image(SDL_Renderer *window_renderer,char *file_path);
void affichage_ecran(TTF_Font *font, char *text_buffer,SDL_Renderer *w_renderer,SDL_Texture *background,int y_pos);
#endif //PROJET_LO21_TEMPLATE_SDL_H
