#include <iostream>
#include "../include/Window.h"
#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600
int main()
{
    Window win(SCREEN_WIDTH,SCREEN_HEIGHT);

    win.initWindow();
 std::cout<<"Koodipahkina"<<std::endl;

    return 0;
}
