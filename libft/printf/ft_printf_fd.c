/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johrober <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 13:39:53 by johrober          #+#    #+#             */
/*   Updated: 2022/07/13 13:40:52 by johrober         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_printf_fd(int fd, const char *input, ...)
{
	va_list	arg_value;
	t_arg	**tab_arg;
	size_t	length;

	va_start(arg_value, input);
	tab_arg = malloc(sizeof(t_arg *) * 1);
	if (!tab_arg)
		return (-1);
	tab_arg[0] = NULL;
	tab_arg = get_tab_arg((char *)input, tab_arg, arg_value);
	va_end(arg_value);
	if (tab_arg == NULL)
		return (-1);
	length = print_output(fd, tab_arg, (char *)input);
	free_tab_arg(tab_arg);
	return (length);
}
