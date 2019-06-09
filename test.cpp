#include <ncurses.h>
#include <string>
#include <iostream>
#include <time.h>
#include <thread>
#include <unistd.h>
#include "Player.hpp"
#include "Game.hpp"
#include "Dots.hpp"
#include "Bullet.hpp"

int kbhit(void) {
	int ch, r;

	nodelay(stdscr, TRUE);
	noecho();
	ch = getch();
	if (ch == ERR) {
		r = FALSE;
	}
	else{
		r = TRUE;
		ungetch(ch);
	}
	echo();
	nodelay(stdscr, FALSE);
	return r;
}

int main(int ac, char **av)
{
    Player  player;
    Game    game;
    Dots mydots[47][20];
    Bullet mybullets[46];

    char gun[4] = "<^>";
    char blank[4] = "   ";
    char enemy[2] = "#";
    char bullet[2] =  "0";

    for (int i = 0; i < 46; i++)
        mybullets[i].setPos(player.getPosX(), player.getPosY() - i);

    for (int i = 0; i < 47; i++)
        for (int y = 0; y < 20; y++)
            mydots[i][y].setY(i);

    mvwprintw(game.gameWin(), player.getPosY(), player.getPosX(), gun);

    while (1)
    {
        if (kbhit())
        {
            int   c = getch();
            switch(c)
            {
                case KEY_UP:
                    mvwprintw(game.gameWin(), player.getPosY(), player.getPosX(), blank);
                    player.mvUp();
                    break;
                case KEY_DOWN:
                    mvwprintw(game.gameWin(), player.getPosY(), player.getPosX(), blank);
                    player.mvDown();
                    break;
                case KEY_RIGHT:
                    mvwprintw(game.gameWin(), player.getPosY(), player.getPosX(), blank);
                    player.mvRight();
                    break;
                case KEY_LEFT:
                    mvwprintw(game.gameWin(), player.getPosY(), player.getPosX(), blank);
                    player.mvLeft();
                    break;
            }
        }

        for (int i = 0; i < 47; i++)
        {
            for (int x = 0; x < 20; x++)
            {
                mvprintw(mydots[i][x].getPosY(), mydots[i][x].getPosX(), " ");
                mydots[i][x].move();
                if (mydots[i][x].getPosY() > 49)
                    mydots[i][x].reset();
                mvprintw(mydots[i][x].getPosY(), mydots[i][x].getPosX(), ".");
            }
        }

        for (int i = 0; i < 46; i++)
        {
            mybullets[i].move();
            if (mybullets[i].getPosY() <= 1)
                mybullets[i].setPos(player.getPosX(), player.getPosY());
            mvprintw(mybullets[i].getPosY(), mybullets[i].getPosX(), bullet);
        }


        mvwprintw(game.gameWin(), player.getPosY(), player.getPosX(), gun);
        wrefresh(game.gameWin());
        usleep(50000);
    }

    endwin();
    return  0;
}