SRC		=	main.c	signal_handler.c	tshell.c
OBJ 	=	$(SRC:%.c=%.o)
CC		=	gcc
CFLAGS	=	-g -Wall -Wextra -Werror -L/usr/local/lib -I/usr/local/include
NAME	=	minishell
LIBFT_FLAGS = -Llibft -lft -Ilibft
LIB_FLAGS	= -lreadline $(LIBFT_FLAGS)

all		: $(NAME)

%.o		: %.c
	$(CC) $(CFLAGS) -Ilibft -I/usr/local/include -c $< -o $@ 
	
$(NAME)	: $(OBJ)
	make -C libft
	$(CC) $(CFLAGS) $(OBJ) $(LIB_FLAGS) -o $(NAME)

clean	:
	rm -f $(OBJ)
	make -C libft clean

ctags	:
	ctags -R **/*

fclean	:	clean
	rm -rf $(NAME)
	make -C libft fclean

re		:	fclean all

.PHONY	:	all bonus clean fclean re
