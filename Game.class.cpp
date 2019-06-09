#include "Game.hpp"

Game::Game() {
    initscr();
    keypad(stdscr, TRUE);
    noecho();
    curs_set(FALSE);
    this->win = newwin(50, 70, 1, 1);
    refresh();
    box(this->win, 0 , 0);
    wrefresh(this->win);
}

WINDOW  *Game::gameWin()
{
    return (this->win);
}