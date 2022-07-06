/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsubstr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johrober <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 15:44:33 by johrober          #+#    #+#             */
/*   Updated: 2022/07/02 15:53:21 by johrober         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsubstr(const char *src, const char *search, size_t to_search)
{
	size_t	count;
	char	*tmp;

	tmp = (char *)src;
	if (!*search || !to_search)
		return (tmp);
	to_search = ft_lower(to_search, ft_strlen(search));
	while (*tmp && (tmp - src) + to_search <= ft_strlen(src))
	{
		count = 0;
		while (tmp[count] == search[count] && count < to_search)
			count++;
		if (count >= to_search)
			return (tmp);
		tmp++;
	}
	return (NULL);
}
