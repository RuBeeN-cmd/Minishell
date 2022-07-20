/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johrober <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 13:49:20 by johrober          #+#    #+#             */
/*   Updated: 2022/07/13 13:41:52 by johrober         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_printf(const char *input, ...)
{
	va_list	arg_value;
	t_arg	**tab_arg;
	size_t	length;

	va_start(arg_value, input);
	tab_arg = malloc(sizeof(t_arg *) * 1);
	if (!tab_arg)
		return (-1);
	tab_arg[0] = NULL;
	tab_arg = get_tab_arg((char *)input, tab_arg, arg_value);
	va_end(arg_value);
	if (tab_arg == NULL)
		return (-1);
	length = print_output(1, tab_arg, (char *)input);
	free_tab_arg(tab_arg);
	return (length);
}

t_arg	**get_tab_arg(char *input, t_arg **tab_arg, va_list arg_value)
{
	int		i;
	t_arg	*arg;

	i = -1;
	while (input[++i])
	{
		if (input[i] == '%')
		{
			i++;
			arg = parse_arg((char *)input, &i, arg_value);
			if (arg == NULL)
				return (free_tab_arg(tab_arg));
			tab_arg = add_arg(tab_arg, arg);
			if (tab_arg == NULL)
				return (NULL);
			i--;
		}
	}
	return (tab_arg);
}

t_arg	*parse_arg(char *input, int *i, va_list arg_value)
{
	t_arg	*arg;

	arg = build_arg((char *)input, i, arg_value);
	if (arg != NULL)
	{
		arg->str = arg_to_str(arg, arg_value);
		if (arg->str == NULL)
			return (free_arg(arg));
		format(arg);
		if (arg->formatted_str == NULL)
			return (free_arg(arg));
	}
	return (arg);
}

void	format(t_arg *arg)
{
	if (!arg->str || !arg)
		return ;
	check_format(arg);
	arg->formatted_str = ft_strdup(arg->str);
	if (arg->type == 0 || arg->type == '%')
		return ;
	if (arg->precision >= 0 && arg->type == 's')
		arg->formatted_str = apply_precision_string(arg);
	else if (arg->precision >= 0 && ft_strchr("diupxX", arg->type))
		arg->formatted_str = apply_precision_int(arg);
	if (ft_strcontains_any(arg->flags, "#"))
		arg->formatted_str = apply_prefix(arg);
	if (ft_strcontains_any(arg->flags, " +"))
		arg->formatted_str = apply_sign(arg);
	if (arg->width > 0)
		arg->formatted_str = apply_width(arg);
}

void	check_format(t_arg *arg)
{
	if (ft_strchr("diuxXp", arg->type) && arg->precision >= 0
		&& ft_strchr(arg->flags, '0'))
		arg->flags = ft_strremove(arg->flags, "0");
	if (ft_strchr("diuxXp", arg->type) && arg->width != 0
		&& ft_strchr(arg->flags, '0') && !ft_strchr(arg->flags, '-'))
		arg->precision = arg->width;
	if (!ft_strchr("pdiu", arg->type))
		arg->flags = ft_strremove(arg->flags, "+ ");
}
