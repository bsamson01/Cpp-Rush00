
#include "Game.hpp"

#define WIDTH (50)
#define HEIGHT (60)

Game::Game() {
	setlocale(LC_CTYPE, "");
	width = WIDTH;
	height = HEIGHT;
    initscr();
    keypad(stdscr, TRUE);
    noecho();
    init_pair(1, COLOR_YELLOW, COLOR_YELLOW);
    curs_set(FALSE);
    cbreak();
    this->win = newwin(height, width, 1, 1);
    refresh();
    wrefresh(this->win);
}

WINDOW  *Game::gameWin()
{
    return (this->win);
}

Game::~Game() {
}

