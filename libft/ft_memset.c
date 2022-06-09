/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johrober <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 13:25:21 by johrober          #+#    #+#             */
/*   Updated: 2022/03/30 16:44:12 by johrober         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *pt, int value, size_t length)
{
	size_t	count;
	char	*tab;

	count = 0;
	tab = (char *)pt;
	while (count < length)
	{
		tab[count] = value;
		count++;
	}
	return (pt);
}
