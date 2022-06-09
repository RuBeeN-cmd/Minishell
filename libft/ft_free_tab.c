/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johrober <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 15:21:40 by johrober          #+#    #+#             */
/*   Updated: 2022/05/04 17:12:53 by johrober         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	**ft_free_tab(void **tab)
{
	int	count;

	count = 0;
	while (tab[count] != NULL)
	{
		free(tab[count]);
		count++;
	}
	free(tab);
	return (NULL);
}
