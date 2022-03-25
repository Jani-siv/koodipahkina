#pragma once
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_video.h>
#include <iostream>
#include <SDL2/SDL.h>
#include <vector>

class Window {
    public:
        Window(unsigned int win_width, unsigned int win_height);
        ~Window();
        void initWindow();
    private:
        int makeWindow();
        int drawWindow();
        SDL_Window* gameWindow = NULL;
        SDL_Surface* sceenSurface = NULL;
        SDL_Renderer* gRenderer = NULL;
        unsigned int u_width;
        unsigned int u_height;
};
