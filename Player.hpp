#ifndef PLAYER_HPP
#define PLAYER_HPP
#include <iostream>

class Player
{
    private:
        int     posX;
        int     posY;
    public:
        Player();
        ~Player();
        void    mvLeft();
        void    mvRight();
        void    mvUp();
        void    mvDown();
        int     getPosX();
        int     getPosY();
};

#endif