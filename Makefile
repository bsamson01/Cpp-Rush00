

CC = g++
FLAGS = -Wall -Wextra -Werror -lncurses -ltinfo
NAME = ft_retro
FILE = main.cpp Player.class.cpp Game.class.cpp Collider.class.cpp


all : $(NAME)

$(NAME):
	@$(CC) $(FLAGS) $(FILE) -o $(NAME)

clean :

fclean : clean
	@rm -rf $(NAME)

re : fclean all
