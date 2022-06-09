/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johrober <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 18:39:51 by johrober          #+#    #+#             */
/*   Updated: 2022/04/07 13:14:24 by johrober         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	count;
	size_t	length;

	count = 0;
	length = 0;
	while (src[length])
		length++;
	while (count + 1 < size && src[count])
	{
		dest[count] = src[count];
		count++;
	}
	if (size > 0)
		dest[count] = 0;
	return (length);
}
