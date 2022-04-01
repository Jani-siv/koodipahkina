#include "../include/Window.h"
#include <SDL2/SDL_pixels.h>
#include <SDL2/SDL_render.h>

Window::Window(const unsigned int& win_width, const unsigned int& win_height) : u_width(win_width), u_height(win_height), world()
{
 this->world.jsonParser("koodipahkina-data.json");
 world.getEdgesCoordinates(this->edgeStartCoordinates,this->edgeEndCoordinates);
 world.getNodesCoordinates(this->nodeCoordinates);
}

Window::~Window()
{
    SDL_DestroyWindow(this->gameWindow);
    SDL_Quit();
}

void Window::initWindow()
{
    this->makeWindow();
    //test lines
    this->drawEdges();
    this->drawNodes();
   SDL_RenderPresent(this->gRenderer);
    SDL_Delay(10000);

}

void Window::drawNodes()
{
   SDL_SetRenderDrawColor(this->gRenderer,0xFF,0x00,0x00,SDL_ALPHA_OPAQUE);
   for (auto it = this->nodeCoordinates.begin(); it != this->nodeCoordinates.end(); it++)
   {
       auto c = it->second.begin();
      this->setNodeModel(c->first, c->second);
   }
 //  SDL_RenderPresent(this->gRenderer);
}

void Window::setNodeModel(int x, int y)
{

    SDL_RenderDrawPoint(this->gRenderer,x-1,y);
    SDL_RenderDrawPoint(this->gRenderer,x+1,y);
    SDL_RenderDrawPoint(this->gRenderer,x,y-1);
    SDL_RenderDrawPoint(this->gRenderer,x,y+1);

    SDL_RenderDrawPoint(this->gRenderer,x-2,y);
    SDL_RenderDrawPoint(this->gRenderer,x+2,y);
    SDL_RenderDrawPoint(this->gRenderer,x,y-2);
    SDL_RenderDrawPoint(this->gRenderer,x,y+2);
}

void Window::drawEdges()
{
    auto itStart = this->edgeStartCoordinates.begin();
    SDL_SetRenderDrawColor(this->gRenderer,0x00,0xFF,0x00,SDL_ALPHA_OPAQUE);
    while (itStart != this->edgeStartCoordinates.end())
    {
        auto coordStart = itStart->second.begin();
        auto itEnd = this->edgeEndCoordinates.find(itStart->first);
        auto coordEnd = itEnd->second.begin();
      int ret = SDL_RenderDrawLine(this->gRenderer,int(coordStart->first), int(coordStart->second), int(coordEnd->first), int(coordEnd->second));
      if (ret < 0) {std::cout<<"error to set line"<<std::endl;}
#ifdef MY_DEBUG
      std::cout<<"coord: "<<coordStart->first<<":"<<coordStart->second<<" "<<coordEnd->first<<":"<<coordEnd->second<<std::endl;
#endif
      itStart++;
    
    }
    //SDL_RenderPresent(this->gRenderer);
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
    SDL_SetRenderDrawColor(this->gRenderer, 0x00,0x00,0x00,0x00);
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
    SDL_Rect fillRect = {(int)this->u_width, (int)this->u_height, (int)this->u_width, (int)this->u_height};
    SDL_SetRenderDrawColor(this->gRenderer, 0xFF,0xFF,0xFF,0xFF);
    SDL_RenderFillRect( this->gRenderer, &fillRect);
    SDL_RenderPresent( this->gRenderer);
    return 0;
}
