/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johrober <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 18:58:58 by johrober          #+#    #+#             */
/*   Updated: 2022/07/21 20:20:17 by johrober         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	copy_pipe_from(int *dest, int *src)
{
	dest[0] = src[0];
	dest[1] = src[1];
}

void	init_pipe(int *pipe)
{
	pipe[0] = -1;
	pipe[1] = -1;
}

void	close_fd(int *fd)
{
	close(*fd);
	*fd = -1;
}

int	count_pipes(t_cmd_element *list)
{
	int				pipes;
	t_cmd_element	*current;

	pipes = 0;
	current = list;
	while (current)
	{
		if (current->type == PIPE)
			pipes++;
		current = current->next;
	}
	return (pipes);
}
