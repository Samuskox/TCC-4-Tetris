#include "tetris.h"

class Game{
    public:
        Game();
        ~Game();

        void update();
        void draw();
        void inputs();
        void test();
        
        int score;
        Tetris tetris;        
};