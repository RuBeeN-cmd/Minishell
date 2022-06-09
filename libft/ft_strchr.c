/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johrober <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 10:43:28 by johrober          #+#    #+#             */
/*   Updated: 2022/04/20 17:11:59 by johrober         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

char	*ft_strchr(const char *str, int character)
{
	char	*to_return;

	character %= 256;
	to_return = (char *)str;
	while (*to_return)
	{
		if (*to_return == character)
			return (to_return);
		to_return++;
	}
	if (character == 0)
		return (to_return);
	return (NULL);
}
