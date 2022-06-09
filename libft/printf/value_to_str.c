/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   value_to_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johrober <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 13:30:00 by johrober          #+#    #+#             */
/*   Updated: 2022/04/26 11:57:39 by johrober         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*arg_to_str(t_arg *arg, va_list arg_value)
{
	if (!arg)
		return (NULL);
	if (arg->type == 0)
		return (ft_strdup("%"));
	else if (arg->type == 'c')
		return (build_char(arg_value));
	else if (arg->type == 's')
		return (build_string(arg, arg_value));
	else if (arg->type == 'p')
		return (build_pointer(arg, arg_value));
	else if (arg->type == 'd' || arg->type == 'i')
		return (ft_itoa((int) va_arg(arg_value, int)));
	else if (arg->type == 'u')
		return (ft_itoa((unsigned int) va_arg(arg_value, int)));
	else if (arg->type == 'x')
		return (ft_itoa_base((unsigned int) va_arg(arg_value, unsigned int),
				"0123456789abcdef"));
	else if (arg->type == 'X')
		return (ft_itoa_base((unsigned int) va_arg(arg_value, unsigned int),
				"0123456789ABCDEF"));
	else if (arg->type == '%')
		return (ft_strdup("%"));
	return (NULL);
}

char	*build_char(va_list arg_value)
{
	char	*str;

	str = malloc(sizeof(char) * 2);
	str[0] = (char) va_arg(arg_value, int);
	str[1] = 0;
	return (str);
}

char	*build_string(t_arg *arg, va_list arg_value)
{
	char	*str;

	str = (char *) va_arg(arg_value, char *);
	if (str == NULL)
	{
		if (arg->precision == -1 || arg->precision > 5)
			str = ft_strdup("(null)");
		else
			str = ft_strdup("");
	}
	else
		str = ft_strdup(str);
	return (str);
}

char	*build_pointer(t_arg *arg, va_list arg_value)
{
	char	*str;
	void	*p;

	p = (void *) va_arg(arg_value, void *);
	if (p == NULL)
		str = ft_strdup("(nil)");
	else
	{
		str = ft_itoa_base_ull((unsigned long long)p, "0123456789abcdef");
		arg->flags = ft_stradd(arg->flags, '#');
	}
	return (str);
}
