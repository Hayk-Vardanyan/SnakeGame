#include "SnakeGame.h"
#include <iostream>
#include <conio.h>
Snake::Snake()
{
GameOver = false;
dir = STOP;
x = width / 2;
y = height / 2;

fruitX = rand() % width;
fruitY = rand() %  height; 
score = 0;
}

void Snake::Draw()
{
    system("cls");

    for(int i = 0; i < width + 2; ++i)
        {
            std::cout << "#";
        }
        std::cout << std::endl;

    for(int i = 0; i < height; ++i)
        {
            for(int j = 0; j < width; ++j)
                {
                    if(j == 0)
                        {
                            std::cout << "#";
                        }
                    if(i == y && j == x)
                        {
                            std::cout << "O";
                        }

                    else if(i == fruitY && j == fruitX)
                        {
                            std::cout << "F";
                        }
                    else {

                        bool print = false;

                        for(int k = 0; k < nTail; ++k)
                            {
                                if(tailX[k] == j && tailY[k] == i)
                                    {
                                        std::cout << "o";
                                        print = true;
                                    }
                            }

                    if(!print) std::cout << " ";
                        }

                    if(j == width - 1)
                        {
                            std::cout << "#";
                        }
                }
                    std::cout << std::endl;
        }
    
    for(int i = 0; i < width + 2; ++i)
        {
            std::cout << "#";
        }
        std::cout << std::endl;

    std::cout << "Score: " << score << std::endl;

}

void Snake::Input()
{
    if(kbhit())
    {
            switch(getch())
                {
                    case 'a':
                     dir = LEFT;
                     break;
                

                    case 'd':
                     dir = RIGHT;
                     break;

                    case 'w':
                     dir = UP;
                     break;

                    case 's':
                     dir = DOWN;
                     break;

                    case 'x':
                     GameOver = true;
                     break;
                }
        }
}

void Snake::Logic()
{
    int prevX = tailX[0];
    int prevY = tailY[0];

    tailX[0] = x;
    tailY[0] = y;

    for(int i = 1; i < nTail; ++i)
    {
        std::swap(tailX[i], prevX);
        std::swap(tailY[i], prevY);
    }

    switch(dir)
    {   
        case UP:
        --y;
        break;
        
        case DOWN:
        ++y;
        break;
        
        case LEFT:
        --x;
        break;
        
        case RIGHT:
        ++x;
        break;
        
        default:
        break;
    }
    
    if(x >= width) x = 0;
     else if(x < 0) x = width - 1;

     if(y >= height) y = 0;
      else if(y < 0) y = height - 1;

    for (int i = 0; i < nTail; ++i)
    {
        if(tailX[i] == x && tailY[i] == y)
        {
            GameOver = true;
        }
    }
    

    if(x == fruitX && y == fruitY)
    {
        score += 10;
        fruitX = rand() % width;
        fruitY = rand() % height; 
        nTail++;
    }

    
}
