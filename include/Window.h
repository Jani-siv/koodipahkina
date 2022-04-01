#pragma once
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_video.h>
#include <iostream>
#include <SDL2/SDL.h>
#include <vector>
#include <list>
#include "../include/World.h"

class Window :public World {

    public:
        Window(const unsigned int& win_width, const unsigned int& win_height);
        ~Window();
        void initWindow();
    private:
        std::map<int,std::map<int,int>>edgeStartCoordinates;
        std::map<int,std::map<int,int>>edgeEndCoordinates;
        std::map<int,std::map<int,int>>nodeCoordinates;
        void setNodeModel(int x,int y);
        void drawEdges();
        void drawNodes();
        int makeWindow();
        int drawWindow();
        SDL_Window* gameWindow = NULL;
        SDL_Surface* sceenSurface = NULL;
        SDL_Renderer* gRenderer = NULL;
        unsigned int u_width;
        unsigned int u_height;
        World world;
};
