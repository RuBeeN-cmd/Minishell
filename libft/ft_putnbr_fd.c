/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johrober <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 13:38:20 by johrober          #+#    #+#             */
/*   Updated: 2022/04/20 17:12:44 by johrober         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_pow(int n, unsigned int p)
{
	if (p == 0)
		return (1);
	else if (p == 1)
		return (n);
	else
		return (ft_pow(n, p - 1) * n);
}

static void	ft_handle_negatives(int *n, int fd)
{
	if (*n < 0)
	{
		write(fd, "-", 1);
		if (*n == -2147483648)
		{
			write(fd, "2", 1);
			*n = -147483648;
		}
		*n *= -1;
	}
}

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	length;
	unsigned int	factor;
	char			c;
	int				tmp_n;

	ft_handle_negatives(&n, fd);
	length = 1;
	tmp_n = n;
	while (tmp_n / 10 != 0)
	{
		length++;
		tmp_n /= 10;
	}
	factor = ft_pow(10, length - 1);
	while (factor != 0)
	{
		c = (n / factor) + '0';
		write(fd, &c, 1);
		n %= factor;
		factor /= 10;
	}
}
