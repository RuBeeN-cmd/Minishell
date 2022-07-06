SRC		=	main.c						signal_handler.c		tshell.c						\
			builtin/builtin_basics.c 	builtin/builtin_env.c	builtin/builtin_handler.c		\
			tenv/tenv_init.c			tenv/tenv_destroy.c		tenv/tenv_utils.c				\
			file/file_utils.c																	\
			execution/exec.c			execution/check_parenthesis.c	execution/split_cmd.c	\
			cmdparsing/t_cmd_element.c	cmdparsing/cmd_splitting.c	cmdparsing/cmd_wildcards.c	\
			cmdparsing/cmd_syntax_check.c	
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
	ctags -R * **/*

fclean	:	clean
	rm -rf $(NAME)
	make -C libft fclean

re		:	fclean all

.PHONY	:	all bonus clean fclean re
