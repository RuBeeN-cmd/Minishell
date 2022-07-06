/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_contains_any.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johrober <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 12:24:43 by johrober          #+#    #+#             */
/*   Updated: 2022/06/21 12:49:20 by johrober         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_str_contains_any(const char *str, char *charset)
{
	int	count;

	count = -1;
	while (charset[++count])
	{
		if (ft_str_contains(str, charset[count]))
			return (1);
	}
	return (0);
}
