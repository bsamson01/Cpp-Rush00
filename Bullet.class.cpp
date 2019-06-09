#include "Bullet.hpp"

Bullet::Bullet()
{
}

Bullet::~Bullet()
{
}

int     Bullet::getPosX()
{
    return (this->posX);
}

int     Bullet::getPosY()
{
    return (this->posY);
}

void     Bullet::move()
{
    this->posY--;
}

void    Bullet::setPos(int posX, int posY)
{
    this->posX = posX + 2;
    this->posY = posY;
}