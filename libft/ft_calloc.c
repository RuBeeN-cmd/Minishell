/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johrober <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 12:43:32 by johrober          #+#    #+#             */
/*   Updated: 2022/04/11 13:24:05 by johrober         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nb, size_t size)
{
	char	*ptr;

	ptr = malloc(nb * size);
	if (ptr == NULL)
		return (NULL);
	ft_bzero(ptr, nb * size);
	return (ptr);
}
