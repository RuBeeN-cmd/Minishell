/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_contains.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrollin <rrollin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 12:33:02 by johrober          #+#    #+#             */
/*   Updated: 2022/06/30 12:53:05 by johrober         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_str_contains(const char *str, char c)
{
	int	count;

	count = -1;
	while (str[++count])
	{
		if (str[count] == c)
			return (1);
	}
	if (c == 0)
		return (1);
	return (0);
}
