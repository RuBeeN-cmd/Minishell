SRC		=	ft_isalnum.c 		ft_isalpha.c	ft_isascii.c	ft_isdigit.c	\
			ft_isprint.c		ft_strlen.c		ft_memset.c		ft_bzero.c		\
			ft_memcpy.c			ft_memmove.c	ft_strlcpy.c	ft_strlcat.c	\
			ft_toupper.c		ft_tolower.c	ft_strchr.c		ft_strrchr.c	\
			ft_strncmp.c		ft_memchr.c		ft_memcmp.c		ft_strnstr.c	\
			ft_atoi.c			ft_calloc.c		ft_strdup.c		ft_substr.c		\
			ft_strjoin.c		ft_strtrim.c	ft_split.c		ft_itoa.c		\
			ft_strmapi.c		ft_striteri.c	ft_putchar_fd.c	ft_putstr_fd.c	\
			ft_putendl_fd.c		ft_putnbr_fd.c	ft_lstnew.c		ft_lstadd_front.c \
			ft_lstsize.c		ft_lstlast.c	ft_lstadd_back.c	ft_lstdelone.c		\
			ft_lstclear.c		ft_lstiter.c	ft_lstmap.c		ft_strrev.c		\
			ft_itoa_base.c		ft_atoi_base.c	ft_add_row.c	ft_free_tab.c \
			ft_free_all.c		ft_strcmp.c		ft_str_equals_any.c		ft_tablen.c \
			ft_str_contains.c	ft_str_contains_any.c			ft_tab_insert.c \
			ft_strchr_any.c		ft_strjoin_free.c				ft_strnjoin.c \
			ft_lower.c			ft_bigger.c		ft_strsubstr.c 	ft_destroy_tab.c\
			printf/parsing.c	printf/formatting.c		printf/ft_printf.c	\
			printf/arg_utils.c	printf/printing.c		printf/string_utils.c	\
			printf/value_to_str.c printf/ft_printf_fd.c \
			get_next_line.c		get_next_line_utils.c
CC		=	gcc
CFLAGS	=	-g -Wall -Wextra -Werror
NAME	=	libft.a
OBJ		=	$(SRC:.c=.o)

all		:	$(NAME)

$(NAME)	: $(OBJ)
	ar -rcs $(NAME) $(OBJ)

clean	:
	rm -rf $(OBJ)

ctags	:
	ctags **/**

fclean	:	clean
	rm -rf $(NAME)

list	:
	@echo $(OBJ)

re		:	fclean all

.PHONY	:	all bonus clean fclean re
