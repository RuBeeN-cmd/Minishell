/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johrober <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 11:58:20 by johrober          #+#    #+#             */
/*   Updated: 2022/04/26 11:57:23 by johrober         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

t_arg	*build_arg(char *str, int *start, va_list arg_value)
{
	t_arg	*arg;
	int		i;

	i = *start;
	arg = NULL;
	if (str[i])
		arg = init_arg();
	if (arg)
	{
		i = parse_flags(str, i, arg, arg_value);
		if (arg->flags == NULL)
		{
			free_arg(arg);
			arg = NULL;
		}
		else
			*start = i;
	}
	return (arg);
}

int	parse_flags(char *str, int i, t_arg *arg, va_list arg_value)
{
	int	tmp;

	tmp = i;
	while (str[i] && arg->type == 0)
	{
		if ((str[i] >= '1' && str[i] <= '9') && arg->width == 0)
			i = handle_precision_and_width(str, arg, i);
		if (str[i] == '.' && arg->precision == -1)
			i = handle_precision_and_width(str, arg, i);
		else if (ft_strchr("-#+ 0", str[i]))
			arg->flags = ft_stradd(arg->flags, str[i++]);
		else if (ft_strchr("cspdiuxX%", str[i]))
			arg->type = str[i++];
		else if (str[i] == '*')
			i = handle_star(str, arg, i, arg_value);
		else
			return (tmp);
	}
	return (i);
}

int	handle_precision_and_width(char *str, t_arg *arg, int i)
{
	int	prec;

	if (str[i] == '.')
	{
		prec = 1;
		i++;
		arg->precision = 0;
	}
	else
		prec = 0;
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		if (prec == 0)
			arg->width = (arg->width * 10) + str[i] - '0';
		else if (prec == 1)
			arg->precision = (arg->precision * 10) + str[i] - '0';
		i++;
	}
	return (i);
}

int	handle_star(char *str, t_arg *arg, int i, va_list av)
{
	int	value;

	value = (int) va_arg(av, int);
	if (str[i - 1] != '.')
	{
		if (value < 0)
		{
			value = -value;
			arg->flags = ft_stradd(arg->flags, '-');
		}
		arg->width = value;
	}
	else if (value >= 0)
		arg->precision = value;
	else
		arg->precision = -1;
	arg->flags = ft_stradd(arg->flags, '*');
	return (++i);
}
