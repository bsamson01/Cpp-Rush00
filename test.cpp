#include <ncurses.h>
#include <string>
#include <iostream>
#include <time.h>
#include <thread>
#include <unistd.h>
#include <sys/time.h>
#include <locale.h>
#include "Player.hpp"
#include "Game.hpp"
#include "Bullet.hpp"

int diff_ms(timeval t1, timeval t2)
{
    return (((t1.tv_sec - t2.tv_sec) * 1000000) + 
            (t1.tv_usec - t2.tv_usec))/1000;
}

long currentTimeMicro() {
    struct timeval currentTime;
    gettimeofday(&currentTime, NULL);
    return currentTime.tv_sec * (int)1e6 + currentTime.tv_usec;
}

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

    (void)av;
    (void)ac;
    Game    game;
    Bullet mybullets[46];

    char gun[4] = "<^>";
    char blank[4] = "   ";
    char bullet[2] =  "0";

    std::string stars = "";
    for (int i = 0; i < game.width * game.height; ++i)
        for (int j = 0; j < game.height; ++j)
            stars += (rand() % 50 > 30) ? "." : " ";
    for (int i = 0; i < 46; i++)
        game.mybullets[i].setPos(game.player.getPosX(), game.player.getPosY() - i);

    long ggg = 0;
    int n = 1;



    long now = currentTimeMicro();
    start_color();

    while (1)
    {

        //Game.tick();
        //Game.render();
        ggg++;
        if (now - currentTimeMicro() < -20000)
        {
            mvprintw(0, 0, "times %d", ggg);
            mvprintw(0, 10, "ups %d", 50);
            mvprintw(0, 30, "times %d %d", game.player.getPosY(), game.player.getPosX());
            ggg = 0;

            now = currentTimeMicro();



            // GAMEPLAY
            // keyboard input
            if (kbhit())
            {
                int   c = getch();
                if (c == KEY_UP)
                    game.player.mvUp();
                else if (c == KEY_DOWN)
                    game.player.mvDown();
                else if (c == KEY_RIGHT)
                    game.player.mvRight();
                else if (c == KEY_LEFT)
                    game.player.mvLeft();
                else if (c == ' ')//spacebar
                    game.player.mvUp();
            
            }

            // draw box and starfield
            box(game.gameWin(), 0, 0);
            //wattron(game.gameWin(), COLOR_PAIR(1));
            for (int i = 1; i < game.height - 1; ++i)
                for (int j = 1; j < game.width - 1; ++j)
                    mvwprintw(game.gameWin(), i, j, "%c", stars[i * game.width + j]);
            //wattroff(game.gameWin(), COLOR_PAIR(1));

                //bullets
            for (int i = 0; i < 46; i++)
            {
                game.mybullets[i].move();
                if (game.mybullets[i].getPosY() <= 1)
                    game.mybullets[i].setPos(game.player.getPosX(), game.player.getPosY());
                mvwprintw(game.gameWin(), game.mybullets[i].getPosY(), game.mybullets[i].getPosX(), bullet);
            }

            mvwprintw(game.gameWin(), game.player.getPosY(), game.player.getPosX(), gun);
            //refresh();
            wrefresh(game.gameWin());
        }
        //usleep(50000);
    }
    endwin();
    return  0;
}