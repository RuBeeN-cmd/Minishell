/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johrober <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 12:16:09 by johrober          #+#    #+#             */
/*   Updated: 2022/04/04 15:25:27 by johrober         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	handle_isspace(const char *str)
{
	size_t	count;

	count = 0;
	while (str[count] == ' ' || str[count] == '\f' || str[count] == '\n'
		|| str[count] == '\r' || str[count] == '\t' || str[count] == '\v')
		count++;
	return (count);
}

static int	handle_sign(const char *str, size_t *count)
{
	int	sign;

	sign = 1;
	if (str[*count] == '+' || str[*count] == '-')
	{
		if (str[*count] == '-')
			sign *= -1;
		(*count)++;
	}
	return (sign);
}

int	ft_atoi(const char *str)
{
	size_t		count;
	int			sign;
	long long	total;

	count = handle_isspace(str);
	sign = handle_sign(str, &count);
	total = 0;
	while (str[count] >= '0' && str[count] <= '9')
	{
		if (total * 10 + (str[count] - '0') < total)
		{
			if (sign == -1)
				return (0);
			else
				return (-1);
		}
		total = total * 10 + (str[count] - '0');
		count++;
	}
	return (total * sign);
}
