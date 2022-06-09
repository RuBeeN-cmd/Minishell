/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrollin <rrollin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 13:57:38 by johrober          #+#    #+#             */
/*   Updated: 2022/06/09 16:29:39 by rrollin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# define BUFFER_SIZE 256

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}				t_list;

/** Part 1 **/
int		ft_isalnum(int character);
int		ft_isalpha(int character);
int		ft_isascii(int character);
int		ft_isdigit(int character);
int		ft_isprint(int character);
size_t	ft_strlen(const char *str);
void	*ft_memset(void *pt, int value, size_t length);
void	*ft_bzero(void *pt, size_t size);
void	*ft_memcpy(void *dest, const void *src, size_t length);
void	*ft_memmove(void *dest, const void *src, size_t length);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);
size_t	ft_strlcat(char *dest, const char *src, size_t size);
int		ft_toupper(int character);
int		ft_tolower(int character);
char	*ft_strchr(const char *str, int character);
char	*ft_strrchr(const char *str, int character);
int		ft_strcmp(const char *s1, const char *s2);
int		ft_strncmp(const char *s1, const char *s2, size_t size);
void	*ft_memchr(const void *pt, int character, size_t size);
int		ft_memcmp(const void *s1, const void *s2, size_t size);
char	*ft_strnstr(const char *src, const char *search, size_t size);
int		ft_atoi(const char *str);
void	*ft_calloc(size_t nb, size_t size);
char	*ft_strdup(const char *str);

/** Part 2 **/
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char const *s1, char const *s2);
char	**ft_split(char const *s, char c);
char	*ft_itoa(long long n);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);

/** Bonus **/
t_list	*ft_lstnew(void *content);
void	ft_lstadd_front(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

/** String utils **/
char	*ft_strrev(char *str);
char	*ft_itoa_base(long long nbrm, char *base);
char	*ft_itoa_base_ull(unsigned long long nbrm, char *base);
int		ft_atoi_base(char *str, char *base);
int		ft_str_equals_any(const char *s1, int nb, ...);

/** Global utils **/
void	ft_free_all(int nbr, ...);
void	**ft_free_tab(void **tab);
void	**ft_add_row(void **tab);
size_t	ft_tablen(const void **tab);

/******************* Printf ******************************/
typedef struct s_arg	t_arg;
struct		s_arg {
	int		precision;
	int		width;
	char	*flags;
	char	type;
	char	*str;
	char	*formatted_str;
};

/**			    ft_printf.c			**/
int		ft_printf(const char *input, ...);
t_arg	**get_tab_arg(char *input, t_arg **tab_arg, va_list arg_value);
t_arg	*parse_arg(char *input, int *i, va_list arg_value);
void	format(t_arg *arg);
void	check_format(t_arg *arg);

/**				printing.c			**/
int		print_output(t_arg **tab_arg, char *input);
int		print_arg(t_arg *arg, int length);
int		print_other(char *input, int i, t_arg *arg, int length);

/**			    parsing.c		**/
t_arg	*build_arg(char *str, int *start, va_list arg_value);
int		parse_flags(char *str, int i, t_arg *arg, va_list arg_value);
int		handle_precision_and_width(char *str, t_arg *arg, int i);
int		handle_star(char *str, t_arg *arg, int i, va_list av);

/**				arg_utils.c	**/
t_arg	**add_arg(t_arg **tab_arg, t_arg *arg);
t_arg	*init_arg(void);
t_arg	**free_tab_arg(t_arg **tab_arg);
t_arg	*free_arg(t_arg *arg);

/**			    string_utils.c		**/
char	*ft_stradd(char *str, char c);
int		ft_strcontains_any(char *str, char *set);
char	*ft_strremove(char *str, char *set);
char	*ft_strremove_one(char *str, char c);
char	*ft_strjoin_free(char *s1, char *s2);

/**			    formatting.c		**/
char	*apply_sign(t_arg *arg);
char	*apply_width(t_arg *arg);
char	*apply_precision_string(t_arg *arg);
char	*apply_precision_int(t_arg *arg);
char	*apply_prefix(t_arg *arg);

/**				value_to_str.c		**/
char	*arg_to_str(t_arg *arg, va_list arg_value);
char	*build_char(va_list arg_value);
char	*build_string(t_arg *arg, va_list arg_value);
char	*build_pointer(t_arg *arg, va_list arg_value);

/************************** get_next_line *****************************/
typedef struct s_lstfd	t_lstfd;
struct s_lstfd {
	int				fd;
	ssize_t			ret;
	ssize_t			index;
	char			*buf;
	struct s_lstfd	*next;
};

/** get_next_line **/
char	*get_next_line(int fd);
t_lstfd	*get_current_fd(t_lstfd *l_fd, int fd);
t_lstfd	*init_fd(t_lstfd **fd_list, int fd);
char	*read_buf(char *str, t_lstfd *l_fd);
char	*read_file(char *str, t_lstfd *l_fd);

/** get_next_line_utils **/
char	*ft_strjoin_until(char *s1, char const *s2, ssize_t start, ssize_t end);
int		ft_strchr_from(const char *str, int start, int character);
void	add_back(t_lstfd **fd_list, t_lstfd *new_fd);
void	delete_fd(t_lstfd **fd_list, int fd);
#endif
