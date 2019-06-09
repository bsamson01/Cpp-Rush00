#ifndef GAME_HPP
# define GAME_HPP

#include <ncurses.h>
#include "Bullet.hpp"
#include "Player.hpp"

class Game
{
private:

public:
	int width;
	int height;
    WINDOW  *win;
    Player player;

    Bullet mybullets[100];
    WINDOW *gameWin();

	Game();
	Game( const Game& cc );
	Game& operator= ( const Game& cc );
	~Game();

};







#endif