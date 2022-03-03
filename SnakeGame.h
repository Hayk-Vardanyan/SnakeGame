#ifndef _SNAKE_GAME
#define _SNALKE_GAME


class Snake
{
 public:
    Snake();

 public:
    void Draw();
    void Input();
    void Logic();
    bool get_flag() {return GameOver;}

 private:
    const int height = 20;
    const int width = 20;
    bool GameOver = false;
    int x; 
    int y;
    int fruitX;
    int fruitY;
    int score;
    enum eDirection {STOP = 0, LEFT, RIGHT, UP , DOWN};
    eDirection dir;
    int tailX[100] {};
    int tailY[100] {};
    int nTail = 0;
};

#endif
