/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_destroy_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johrober <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 12:20:43 by johrober          #+#    #+#             */
/*   Updated: 2022/07/07 12:26:06 by johrober         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_destroy_tab(void ***tab, void (*destroy)(void *))
{
	int	count;

	count = 0;
	while ((*tab)[count])
	{
		destroy((*tab)[count]);
		count++;
	}
	free(*tab);
	*tab = NULL;
}
