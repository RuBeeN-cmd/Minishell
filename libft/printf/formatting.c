/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   formatting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johrober <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 11:53:35 by johrober          #+#    #+#             */
/*   Updated: 2022/04/26 11:57:08 by johrober         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*apply_sign(t_arg *arg)
{
	char	*new;

	if (!arg || !arg->formatted_str || arg->formatted_str[0] == '-')
		return (arg->formatted_str);
	new = malloc(sizeof(char) * (ft_strlen(arg->formatted_str) + 2));
	if (new)
	{
		if (ft_strchr(arg->flags, '+'))
			new[0] = '+';
		else if (ft_strchr(arg->flags, ' '))
			new[0] = ' ';
		ft_memcpy(new + 1, arg->formatted_str, ft_strlen(arg->formatted_str));
		new[ft_strlen(arg->formatted_str) + 1] = 0;
	}
	free(arg->formatted_str);
	return (new);
}

char	*apply_width(t_arg *arg)
{
	char	*new;
	int		length;

	length = ft_strlen(arg->formatted_str);
	if (length == 0 && arg->type == 'c')
		length = 1;
	if (!arg->formatted_str || arg->width - length <= 0)
		return (arg->formatted_str);
	new = malloc(sizeof(char) * arg->width + 1);
	if (new)
	{
		new[arg->width] = 0;
		if (ft_strchr(arg->flags, '-'))
		{
			ft_memcpy(new, arg->formatted_str, length);
			ft_memset(new + length, ' ', arg->width - length);
		}
		else
		{
			ft_memcpy(new + arg->width - length, arg->formatted_str, length);
			ft_memset(new, ' ', arg->width - length);
		}
	}
	free(arg->formatted_str);
	return (new);
}

char	*apply_precision_string(t_arg *arg)
{
	char	*new;

	if (arg->precision >= (int)ft_strlen(arg->formatted_str))
		return (arg->formatted_str);
	new = malloc(sizeof(char) * (arg->precision + 1));
	if (new)
	{
		if (arg->precision > 0)
			ft_memcpy(new, arg->formatted_str, arg->precision);
		new[arg->precision] = 0;
	}
	free(arg->formatted_str);
	return (new);
}

char	*apply_precision_int(t_arg *arg)
{
	char	*new;
	int		dif;

	if (arg->str[0] == '-' && !ft_strchr(arg->flags, '0'))
		arg->precision++;
	dif = arg->precision - ft_strlen(arg->formatted_str);
	if (dif <= 0 && arg->precision == 0)
		return (apply_precision_string(arg));
	else if (dif <= 0)
		return (arg->formatted_str);
	new = malloc(sizeof(char) * (arg->precision + 1));
	if (new)
	{
		new[arg->precision] = 0;
		ft_memcpy(new + dif, arg->formatted_str, ft_strlen(arg->formatted_str));
		ft_memset(new, '0', dif);
		if (arg->str[0] == '-')
		{
			new[0] = '-';
			new[dif] = '0';
		}
	}
	free(arg->formatted_str);
	return (new);
}

char	*apply_prefix(t_arg *arg)
{
	char	*new;

	if (!arg || !arg->formatted_str || !ft_strchr("pxX", arg->type)
		|| (ft_strchr("xX", arg->type) && arg->str[0] == '0'))
		return (arg->formatted_str);
	new = malloc(sizeof(char) * (ft_strlen(arg->formatted_str) + 3));
	if (new)
	{
		new[0] = '0';
		if (arg->type == 'X')
			new[1] = 'X';
		else
			new[1] = 'x';
		ft_memcpy(new + 2, arg->formatted_str, ft_strlen(arg->formatted_str));
		new[ft_strlen(arg->formatted_str) + 2] = 0;
	}
	free(arg->formatted_str);
	return (new);
}
