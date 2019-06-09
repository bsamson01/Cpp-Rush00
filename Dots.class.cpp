#include "Dots.hpp"

Dots::Dots()
{
    this->posX = rand() % 67 + 2;
    this->posY = 2;
}

Dots::~Dots()
{
}

int     Dots::getPosX()
{
    return (this->posX);
}

int     Dots::getPosY()
{
    return (this->posY);
}

void    Dots::reset()
{
    this->posX = rand() % 67 + 2;
    this->posY = 2;
}

void    Dots::move()
{
    this->posY++;
}

void    Dots::setY(int  x)
{
    this->posY += x;
}