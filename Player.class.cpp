#include "Player.hpp"

Player::Player()
{
    this->posX = 33;
    this->posY = 48;
}

Player::~Player()
{
}

void    Player::mvLeft()
{
    if (this->posX > 1)
        this->posX--;
}

void    Player::mvRight()
{
    if (this->posX < 66)
        this->posX++;
}

void    Player::mvDown()
{
    if (this->posY < 48)
        this->posY++;
}

void    Player::mvUp()
{
    if (this->posY > 1)
        this->posY--;
}

int     Player::getPosX()
{
    return this->posX;
}

int     Player::getPosY()
{
    return this->posY;
}