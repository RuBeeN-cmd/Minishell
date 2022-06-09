/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_row.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johrober <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 12:27:33 by johrober          #+#    #+#             */
/*   Updated: 2022/05/04 17:12:42 by johrober         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	**ft_add_row(void **tab)
{
	int		count;
	void	**new;

	count = 0;
	while (tab && tab[count])
		count++;
	new = malloc(sizeof (void *) * (count + 2));
	if (!new)
		return (NULL);
	new[count + 1] = NULL;
	new[count] = NULL;
	count = -1;
	while (tab && tab[++count])
		new[count] = tab[count];
	if (tab)
		free(tab);
	return (new);
}
