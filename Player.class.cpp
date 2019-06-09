#include "Player.hpp"

Player::Player()
{
    this->posX = 5;
    this->posY = 5;
}

Player::~Player()
{
}

void    Player::mvLeft()
{
    this->posX--;
}

void    Player::mvRight()
{
    this->posX++;
}

void    Player::mvDown()
{
    this->posY++;
}

void    Player::mvUp()
{
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