#include "tetris.h"

class Game{
    public:
        Game();
        ~Game();

        void update();
        void draw();
        void inputs();
        void test();

        bool gameOver;
        int score;
        Tetris tetris;        
};