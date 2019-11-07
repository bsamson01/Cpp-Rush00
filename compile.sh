g++ -Wall -Wextra -Werror -o Shooter -g $(pkg-config --cflags ncurses)  *.cpp $(pkg-config --libs ncurses)
