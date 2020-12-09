NAME = sastantua
SRC = main.c ex00/sastantua.c

all: $(NAME)

$(NAME):
	gcc -o $(NAME) -Wall -Werror -Wextra $(SRC) -I

clean:
	/bin/rm -f $(NAME)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
