/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johrober <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 16:56:57 by johrober          #+#    #+#             */
/*   Updated: 2022/04/01 19:38:11 by johrober         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t size)
{
	size_t	count;
	char	*tab_dest;
	char	*tab_src;

	tab_dest = (char *)dest;
	tab_src = (char *)src;
	if (size == 0)
		return (dest);
	if (tab_dest > tab_src)
	{
		count = size;
		while (--count)
			tab_dest[count] = tab_src[count];
		tab_dest[0] = tab_src[0];
	}
	else if (tab_dest < tab_src)
	{
		count = -1;
		while (++count < size)
			tab_dest[count] = tab_src[count];
	}
	return (dest);
}
