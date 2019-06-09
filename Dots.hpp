#ifndef DOTS_HPP
# define DOTS_HPP

#include <iostream>
#include <cstdlib>

class Dots
{
    private:
        int     posX;
        int     posY;
    public:
        Dots();
        ~Dots();
        int     getPosX();
        int     getPosY();
        void    reset();
        void    move();
        void    setY(int x);
};

#endif