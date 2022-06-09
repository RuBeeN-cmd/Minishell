/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johrober <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 18:24:30 by johrober          #+#    #+#             */
/*   Updated: 2022/04/26 11:57:03 by johrober         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

t_arg	**add_arg(t_arg **tab_arg, t_arg *arg)
{
	t_arg	**tmp;
	int		count;

	count = 0;
	while (tab_arg[count])
		count++;
	tmp = malloc(sizeof(t_arg *) * (count + 2));
	if (!tmp)
	{
		if (arg)
			free_arg(arg);
		return (free_tab_arg(tab_arg));
	}
	count = -1;
	while (tab_arg[++count])
		tmp[count] = tab_arg[count];
	tmp[count++] = arg;
	tmp[count] = NULL;
	free(tab_arg);
	return (tmp);
}

t_arg	*init_arg(void)
{
	t_arg	*arg;

	arg = malloc(sizeof(t_arg));
	if (arg == NULL)
		return (NULL);
	arg->precision = -1;
	arg->width = 0;
	arg->flags = malloc(sizeof(char) * 1);
	if (arg->flags == NULL)
	{
		free(arg);
		arg = NULL;
		return (NULL);
	}
	arg->flags[0] = 0;
	arg->type = 0;
	return (arg);
}

t_arg	**free_tab_arg(t_arg **tab_arg)
{
	int	count;

	count = -1;
	while (tab_arg[++count] != NULL)
		free_arg(tab_arg[count]);
	free(tab_arg);
	return (NULL);
}

t_arg	*free_arg(t_arg *arg)
{
	if (arg)
	{
		if (arg->flags)
			free(arg->flags);
		if (arg->str)
			free(arg->str);
		if (arg->formatted_str)
			free(arg->formatted_str);
		free(arg);
	}
	return (NULL);
}
