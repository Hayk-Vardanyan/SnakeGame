#include "SnakeGame.h"
#include <windows.h>
int main()
{
    Snake ob;

    while(!ob.get_flag()) 
    {
    ob.Draw();
    ob.Input();
    ob.Logic();
    Sleep(10);
    }
}

