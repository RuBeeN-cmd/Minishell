/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrollin <rrollin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 10:09:00 by rrollin           #+#    #+#             */
/*   Updated: 2022/06/28 13:34:11 by rrollin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../minishell.h"

void	write_mode(char *path, char *str, int mode)
{
	int	fd;

	fd = open(path, mode, 0644);
	if (fd != -1)
	{
		write(fd, str, ft_strlen(str));
		close(fd);
	}
}

void	append_file(char *path, char *str)
{
	write_mode(path, str, O_APPEND | O_WRONLY | O_CREAT);
}

void	replace_file(char *path, char *str)
{
	write_mode(path, str, O_TRUNC | O_WRONLY | O_CREAT);
}
