/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johrober <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 11:34:04 by johrober          #+#    #+#             */
/*   Updated: 2022/04/17 20:07:35 by johrober         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t		ft_intlen(long long n);
static long long	ft_abs(long long n);

char	*ft_itoa(long long n)
{
	int		length;
	int		count;
	char	*str;

	length = ft_intlen(n);
	str = malloc(sizeof(char) * (length + 1));
	if (str == NULL)
		return (NULL);
	str[length] = 0;
	count = 1;
	if (n == 0)
		str[0] = '0';
	else if (n < 0)
		str[0] = '-';
	while (n % 10 != 0 || n / 10 != 0)
	{
		str[length - count] = ft_abs(n % 10) + '0';
		n /= 10;
		count++;
	}
	return (str);
}

static long long	ft_abs(long long n)
{
	if (n < 0)
		return (-n);
	return (n);
}

static size_t	ft_intlen(long long n)
{
	int	length;

	length = 1;
	if (n < 0)
		length++;
	while (n / 10 != 0)
	{
		n /= 10;
		length++;
	}
	return (length);
}
