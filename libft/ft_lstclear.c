/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johrober <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 18:01:44 by johrober          #+#    #+#             */
/*   Updated: 2022/04/02 19:48:41 by johrober         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*tmp_cur;
	t_list	*tmp_next;

	if (lst == NULL || *lst == NULL)
		return ;
	tmp_cur = *lst;
	while (tmp_cur)
	{
		tmp_next = tmp_cur->next;
		ft_lstdelone(tmp_cur, del);
		tmp_cur = tmp_next;
	}
	*lst = NULL;
}
