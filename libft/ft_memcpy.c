/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johrober <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 14:17:13 by johrober          #+#    #+#             */
/*   Updated: 2022/04/01 18:40:37 by johrober         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t length)
{
	char		*tab_dest;
	char		*tab_src;
	size_t		count;

	count = 0;
	if (dest == NULL && src == NULL)
		return (dest);
	tab_dest = (char *)dest;
	tab_src = (char *)src;
	while (count < length)
	{
		tab_dest[count] = tab_src[count];
		count++;
	}
	return (dest);
}
