#include "../include/Window.h"

Window::Window(unsigned int win_width,unsigned int win_height)
{
 this->u_height = win_height;
 this->u_width = win_width;
 this->world.createNodes();
}

Window::~Window()
{
    SDL_DestroyWindow(this->gameWindow);
    SDL_Quit();
}

void Window::initWindow()
{
    this->makeWindow();
    SDL_Delay(2000);

}

int Window::makeWindow()
{
    if( SDL_Init( SDL_INIT_VIDEO) < 0)
    {
        std::cerr<<"sdl could not init video: "<<SDL_GetError()<<std::endl;
        return -1;
    }
    this->gameWindow = SDL_CreateWindow("Koodi pahkina 2", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, this->u_width, this->u_height, SDL_WINDOW_SHOWN);
    if (this->gameWindow == NULL)
    {
        std::cout<<"Could not create window: "<<SDL_GetError()<<std::endl;
        return -1;
    }
    this->gRenderer = SDL_CreateRenderer(this->gameWindow, -1, SDL_RENDERER_ACCELERATED);
    if (this->gRenderer == NULL)
    {
        std::cerr<<"Renderer could not be created: "<<SDL_GetError()<<std::endl;
        return -1;
    }
    //color
    SDL_SetRenderDrawColor(this->gRenderer, 0xFF,0xFF,0xFF,0xFF);
    SDL_RenderClear(this->gRenderer);
    if (this->drawWindow() < 0)
    {
        std::cerr<<"Error to draw window"<<std::endl;
        return -1;
    }
    return 0;

}

int Window::drawWindow()
{
    SDL_Rect fillRect = {(int)this->u_width / 2, (int)this->u_height / 4, (int)this->u_width / 2, (int)this->u_height / 2};
    SDL_SetRenderDrawColor(this->gRenderer, 0xFF,0xFF,0xFF,0xFF);
    SDL_RenderFillRect( this->gRenderer, &fillRect);
    SDL_RenderPresent( this->gRenderer);
    return 0;
}
