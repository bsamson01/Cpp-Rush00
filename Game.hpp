#ifndef GAME_HPP
# define GAME_HPP
#include <ncurses.h>

class Game
{
private:
    WINDOW  *win;

public:
    Game();
    WINDOW *gameWin();
};

#endif