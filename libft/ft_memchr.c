/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johrober <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 11:03:56 by johrober          #+#    #+#             */
/*   Updated: 2022/04/07 13:15:21 by johrober         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *pt, int character, size_t size)
{
	size_t	count;
	char	*str;

	character %= 256;
	str = (char *)pt;
	count = 0;
	while (count < size)
	{
		if (str[count] == character)
			return (&(str[count]));
		count++;
	}
	return (NULL);
}
