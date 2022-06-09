/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johrober <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 11:19:23 by johrober          #+#    #+#             */
/*   Updated: 2022/04/02 16:00:24 by johrober         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *src, const char *search, size_t size)
{
	size_t	count;
	char	*tmp;

	tmp = (char *)src;
	if (!*search)
		return (tmp);
	while (*tmp && (tmp - src) + ft_strlen(search) <= size)
	{
		count = 0;
		while (tmp[count] == search[count] && search[count])
			count++;
		if (!search[count])
			return (tmp);
		tmp++;
	}
	return (NULL);
}
