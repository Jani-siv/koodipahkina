#include <iostream>
#include "../include/Window.h"
#define SCREEN_WIDTH 1200
#define SCREEN_HEIGHT 1200
int main()
{
    Window win(SCREEN_WIDTH,SCREEN_HEIGHT);

    win.initWindow();
 std::cout<<"Koodipahkina"<<std::endl;

    return 0;
}
