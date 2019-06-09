

CC = clang++
FLAGS = -lncurses
NAME = ft_retro
FILE = test.cpp Player.class.cpp Game.class.cpp Bullet.class.cpp


all : $(NAME)

$(NAME) :
	@$(CC) $(FLAGS) $(FILE) -o $(NAME)

clean :

fclean : clean
	@rm -rf $(NAME)

re : fclean all

