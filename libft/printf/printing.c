/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johrober <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 13:30:36 by johrober          #+#    #+#             */
/*   Updated: 2022/04/26 11:57:27 by johrober         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	print_output(t_arg **tab_arg, char *input)
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
			length = print_arg(arg, length);
			while (arg->type != 0 && input[++i] && input[i] != arg->type)
				;
		}
		else
			length = print_other(input, i, arg, length);
	}
	return (length);
}

int	print_arg(t_arg *arg, int length)
{
	ft_putstr_fd(arg->formatted_str, 1);
	length += ft_strlen(arg->formatted_str);
	if (arg->type == 'c' && arg->str[0] == 0)
	{
		ft_putchar_fd(0, 1);
		length++;
		if (arg->formatted_str[0] == 0 && arg->width > 1)
		{
			ft_putstr_fd(&(arg->formatted_str[1]), 1);
			length += ft_strlen(&(arg->formatted_str[1]));
		}
	}
	return (length);
}

int	print_other(char *input, int i, t_arg *arg, int length)
{
	if (input[i] == '*' && arg && ft_strchr(arg->flags, '*'))
	{
		ft_putstr_fd(ft_itoa(arg->width), 1);
		arg->flags = ft_strremove_one(arg->flags, '*');
		length += ft_strlen(ft_itoa(arg->width));
	}
	else
	{
		ft_putchar_fd(input[i], 1);
		length++;
	}
	return (length);
}
