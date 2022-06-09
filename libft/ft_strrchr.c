/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johrober <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 10:48:12 by johrober          #+#    #+#             */
/*   Updated: 2022/03/31 19:09:01 by johrober         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int character)
{
	char	*tmp;

	character %= 256;
	tmp = (char *)str;
	while (*tmp)
		tmp++;
	if (character == 0)
		return (tmp);
	while (--tmp != str - 1)
	{
		if (*tmp == character)
			return (tmp);
	}
	return (NULL);
}
