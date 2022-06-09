/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_equals_any.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johrober <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 16:15:45 by johrober          #+#    #+#             */
/*   Updated: 2022/05/11 18:17:18 by johrober         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_str_equals_any(const char *s1, int nb, ...)
{
	va_list	args;
	char	*s2;

	if (nb < 1)
		return (1);
	va_start(args, nb);
	while (nb)
	{
		s2 = va_arg(args, char *);
		if (ft_strcmp(s1, s2) == 0)
			return (1);
		nb--;
	}
	return (0);
}
