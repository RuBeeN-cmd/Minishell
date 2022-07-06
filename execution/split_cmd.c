/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrollin <rrollin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 15:05:15 by rrollin           #+#    #+#             */
/*   Updated: 2022/07/04 16:49:24 by rrollin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../minishell.h"

void	ft_get_blocks(t_cmd_element *input, t_cmd_element **cmd,
	t_cmd_element **op, t_cmd_element **nxt_block)
{
	t_cmd_element	*tmp;
	int				is_in_parenthesis;

	is_in_parenthesis = 0;
	*cmd = input;
	if (input->type == PARENTHESIS)
		is_in_parenthesis++;
	while (input->next)
	{
		if (input->next->type == PARENTHESIS)
		{
			if (!ft_strcmp((const char *) input->next->str, "("))
				is_in_parenthesis++;
			else
				is_in_parenthesis--;
		}
		else if (input->next->type == OPERATOR && !is_in_parenthesis)
			tmp = input;
		input = input->next;
	}
	*op = tmp->next;
	tmp->next = NULL;
	*nxt_block = (*op)->next;
	(*op)->next = NULL;
}

int	ft_split_cmd(t_cmd_element *input)
{
	t_cmd_element	*op;
	t_cmd_element	*cmd;
	t_cmd_element	*nxt_block;

	ft_get_blocks(input, &cmd, &op, &nxt_block);
	if (!ft_strcmp(op->str, "&&"))
	{
		destroy_element(op);
		if (ft_exec_bloc(cmd))
			return (ft_exec_bloc(nxt_block));
		return (0);
	}
	else if (!ft_strcmp(op->str, "||"))
	{
		destroy_element(op);
		if (!ft_exec_bloc(cmd))
			return (ft_exec_bloc(nxt_block));
		return (0);
	}
	return (1);
}
