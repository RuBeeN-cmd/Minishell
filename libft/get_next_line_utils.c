/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johrober <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 17:37:44 by johrober          #+#    #+#             */
/*   Updated: 2022/04/26 12:01:19 by johrober         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin_until(char *s1, char const *s2, ssize_t start, ssize_t end)
{
	size_t	length;
	char	*str;
	int		str_count;
	int		count;

	length = 0;
	while (s1 && s1[length])
		length++;
	length += end - start;
	str = malloc(sizeof(char) * (length + 1));
	if (str != NULL)
	{
		count = 0;
		str_count = 0;
		while (s1 && s1[count])
			str[str_count++] = s1[count++];
		while (start < end && s2[start])
			str[str_count++] = s2[start++];
		str[str_count] = 0;
	}
	if (s1 != NULL)
		free(s1);
	return (str);
}

int	ft_strchr_from(const char *str, int start, int character)
{
	while (str[start])
	{
		if (str[start] == character)
			return (start);
		start++;
	}
	if (character == 0)
		return (start);
	return (-1);
}

void	add_back(t_lstfd **fd_list, t_lstfd *new_fd)
{
	t_lstfd	*tmp;

	if (*fd_list == NULL)
		*fd_list = new_fd;
	else
	{
		tmp = *fd_list;
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = new_fd;
	}
}

void	delete_fd(t_lstfd **fd_list, int fd)
{
	t_lstfd	*current;
	t_lstfd	*previous;

	current = *fd_list;
	previous = NULL;
	while (current && current->fd != fd)
	{
		previous = current;
		current = current->next;
	}
	if (current != NULL)
	{
		if (previous == NULL)
			*fd_list = current->next;
		else
			previous->next = current->next;
		free(current->buf);
		free(current);
	}
}
