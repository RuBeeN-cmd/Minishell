/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johrober <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 13:04:17 by johrober          #+#    #+#             */
/*   Updated: 2022/04/18 13:01:27 by johrober         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_base_length(char *base);
static char	*itoa_base_ll(long long nbr, char *base, int base_length);
static char	*itoa_base_ull(unsigned long long nbr, char *base, int base_length);

char	*ft_itoa_base(long long nbrm, char *base)
{
	int		int_base;

	int_base = get_base_length(base);
	if (int_base == -1)
		return (NULL);
	return (itoa_base_ll(nbrm, base, int_base));
}

char	*ft_itoa_base_ull(unsigned long long nbrm, char *base)
{
	int		int_base;

	int_base = get_base_length(base);
	if (int_base == -1)
		return (NULL);
	return (itoa_base_ull(nbrm, base, int_base));
}

static int	get_base_length(char *base)
{
	unsigned int	int_base;
	unsigned int	count;

	int_base = 0;
	while (base[int_base])
	{
		count = 0;
		while (base[count])
		{
			if (count != int_base && base[count] == base[int_base])
				return (-1);
			count++;
		}
		if (base[int_base] == '-' || base[int_base] == '+')
			return (-1);
		int_base++;
	}
	if (int_base <= 1)
		return (-1);
	return (int_base);
}

static char	*itoa_base_ll(long long nbr, char *base, int base_length)
{
	char	rev_nbr[70];
	int		count;
	int		sign;

	sign = 1;
	if (nbr < 0)
		sign = -1;
	nbr *= sign;
	count = 0;
	while (nbr >= 0)
	{
		rev_nbr[count] = base[nbr % base_length];
		nbr /= base_length;
		count++;
		if (nbr == 0)
			break ;
	}
	if (sign == -1)
		rev_nbr[count++] = '-';
	rev_nbr[count] = 0;
	return (ft_strdup(ft_strrev(rev_nbr)));
}

static char	*itoa_base_ull(unsigned long long nbr, char *base, int base_length)
{
	char	rev_nbr[70];
	int		count;

	count = 0;
	if (nbr == 0)
		rev_nbr[count++] = base[0];
	while (nbr != 0)
	{
		rev_nbr[count] = base[nbr % base_length];
		nbr /= base_length;
		count++;
	}
	rev_nbr[count] = 0;
	return (ft_strdup(ft_strrev(rev_nbr)));
}
