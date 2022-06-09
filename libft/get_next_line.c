/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johrober <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 17:22:27 by johrober          #+#    #+#             */
/*   Updated: 2022/05/11 18:11:58 by johrober         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*get_next_line(int fd)
{
	static t_lstfd	*fd_list;
	t_lstfd			*current_fd;
	char			*str;

	str = NULL;
	if (fd == -1)
		return (NULL);
	current_fd = get_current_fd(fd_list, fd);
	if (current_fd && current_fd->index < current_fd->ret)
		str = read_buf(str, current_fd);
	else if (current_fd == NULL)
		current_fd = init_fd(&fd_list, fd);
	if (current_fd == NULL)
		return (NULL);
	if (!str || str[ft_strlen(str) - 1] != '\n')
		str = read_file(str, current_fd);
	if (current_fd->ret == 0 || current_fd->index == current_fd->ret)
		delete_fd(&fd_list, fd);
	return (str);
}

t_lstfd	*get_current_fd(t_lstfd *l_fd, int fd)
{
	t_lstfd	*tmp;

	tmp = l_fd;
	while (tmp != NULL)
	{
		if (tmp->fd == fd)
			return (tmp);
		tmp = tmp->next;
	}
	return (NULL);
}

t_lstfd	*init_fd(t_lstfd **fd_list, int fd)
{
	t_lstfd	*new;

	new = malloc(sizeof(t_lstfd));
	if (new == NULL)
		return (NULL);
	new->index = -1;
	new->ret = -1;
	new->buf = malloc(sizeof(char) * (BUFFER_SIZE + 2));
	if (new->buf == NULL)
	{
		free(new);
		return (NULL);
	}
	new->next = NULL;
	new->fd = fd;
	add_back(fd_list, new);
	return (new);
}

char	*read_buf(char *str, t_lstfd *l_fd)
{
	int	end_read;

	end_read = ft_strchr_from(l_fd->buf, l_fd->index, '\n');
	if (end_read > l_fd->ret || end_read == -1)
		end_read = l_fd->ret;
	else
		end_read++;
	str = ft_strjoin_until(str, l_fd->buf, l_fd->index, end_read);
	if (str == NULL)
		return (NULL);
	l_fd->index = end_read;
	return (str);
}

char	*read_file(char *str, t_lstfd *l_fd)
{
	int	end_read;

	l_fd->index = -1;
	while (l_fd->index == -1 || (l_fd->index == l_fd->ret && l_fd->ret > 0
			&& l_fd->buf[l_fd->index - 1] != '\n'))
	{
		l_fd->index = 0;
		l_fd->ret = read(l_fd->fd, l_fd->buf, BUFFER_SIZE);
		if (l_fd->ret > 0)
		{
			l_fd->buf[l_fd->ret] = 0;
			end_read = ft_strchr_from(l_fd->buf, 0, '\n');
			if (end_read == -1)
				end_read = l_fd->ret - 1;
			end_read++;
			if (l_fd->ret > 0)
			{
				str = ft_strjoin_until(str, l_fd->buf, l_fd->index, end_read);
				if (str == NULL)
					return (NULL);
				l_fd->index = end_read;
			}
		}
	}
	return (str);
}
