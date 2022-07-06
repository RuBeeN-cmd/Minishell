/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_parenthesis.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrollin <rrollin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 15:04:22 by rrollin           #+#    #+#             */
/*   Updated: 2022/07/04 16:45:34 by rrollin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../minishell.h"

int	got_parenthesis(t_cmd_element *input)
{
	return (input->type == PARENTHESIS
		&& !ft_strcmp((const char *) input->str, "("));
}

void	remove_parenthesis(t_cmd_element **input)
{
	t_cmd_element	*tmp;
	t_cmd_element	*tmp_tmp;
	int				nb_parenthesis;

	tmp = (*input)->next;
	destroy_element(*input);
	*input = tmp;
	nb_parenthesis = 1;
	while (tmp->next)
	{
		if (tmp->next->type == PARENTHESIS)
		{
			if (!ft_strcmp((const char *) tmp->next->str, "("))
				nb_parenthesis++;
			else
				nb_parenthesis--;
		}
		if (!nb_parenthesis)
		{
			tmp_tmp = tmp->next;
			tmp->next = tmp_tmp->next;
			destroy_element(tmp_tmp);
			return ;
		}
		tmp = tmp->next;
	}
}

void	remove_pipe_parenthesis(t_cmd_element **input)
{
	t_cmd_element	*tmp;

	tmp = *input;
	while (*input)
	{
		if ((*input)->type == PIPE)
			if (got_parenthesis((*input)->next))
				remove_parenthesis(&((*input)->next));
		*input = (*input)->next;
	}
	*input = tmp;
}
