/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johrober <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 13:30:36 by johrober          #+#    #+#             */
/*   Updated: 2022/07/13 13:51:19 by johrober         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	print_output(int fd, t_arg **tab_arg, char *input)
{
	int		length;
	size_t	i;
	size_t	arg_count;
	t_arg	*arg;

	i = -1;
	arg_count = 0;
	length = 0;
	arg = NULL;
	while (input[++i])
	{
		if (input[i] == '%' && tab_arg[arg_count])
		{
			arg = tab_arg[arg_count++];
			if (arg == NULL)
				return (-1);
			length += print_arg(fd, arg);
			while (arg->type != 0 && input[++i] && input[i] != arg->type)
				;
		}
		else
			length += print_other(fd, input, i, arg);
	}
	return (length);
}

int	print_arg(int fd, t_arg *arg)
{
	int length;

	ft_putstr_fd(arg->formatted_str, 1);
	length = ft_strlen(arg->formatted_str);
	if (arg->type == 'c' && arg->str[0] == 0)
	{
		ft_putchar_fd(0, fd);
		length++;
		if (arg->formatted_str[0] == 0 && arg->width > 1)
		{
			ft_putstr_fd(&(arg->formatted_str[1]), fd);
			length += ft_strlen(&(arg->formatted_str[1]));
		}
	}
	return (length);
}

int	print_other(int fd, char *input, int i, t_arg *arg)
{
	int length;

	length = 0;
	if (input[i] == '*' && arg && ft_strchr(arg->flags, '*'))
	{
		ft_putstr_fd(ft_itoa(arg->width), fd);
		arg->flags = ft_strremove_one(arg->flags, '*');
		length += ft_strlen(ft_itoa(arg->width));
	}
	else
	{
		ft_putchar_fd(input[i], fd);
		length++;
	}
	return (length);
}
