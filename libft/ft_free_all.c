/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_all.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johrober <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 11:17:58 by johrober          #+#    #+#             */
/*   Updated: 2022/05/02 13:53:49 by johrober         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_free_all(int nbr, ...)
{
	void	*ptr;
	va_list	arg;
	int		count;

	va_start(arg, nbr);
	count = 0;
	while (count < nbr)
	{
		ptr = (void *)va_arg(arg, void *);
		if (ptr)
			free(ptr);
		count++;
	}
	va_end(arg);
}
