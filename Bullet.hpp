#ifndef BULLET_HPP
# define BULLET_HPP

class Bullet
{
private:
    int     posX;
    int     posY;
public:
    Bullet();
    ~Bullet();
    int     getPosX();
    int     getPosY();
    void    setPos(int posX, int PosY);
    void     move();
};

#endif