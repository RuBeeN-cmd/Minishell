/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrollin <rrollin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 12:22:45 by rrollin           #+#    #+#             */
/*   Updated: 2022/07/11 18:01:45 by johrober         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../minishell.h"

/* int	exec(t_cmd_element *cmd) */
/* { */
/* 	int	res; */

/* 	res = !(!ft_strcmp((const char *) cmd->str, "echo")); */
/* 	print_element(cmd); */
/* 	destroy_element(cmd); */
/* 	return (res); */
/* } */

int	exec(t_shell *shell, t_cmd_element *list)
{
	t_cmd	**cmd_tab;

	cmd_tab = parse_final(list);
	execute(shell, cmd_tab);
	ft_destroy_tab((void ***)&cmd_tab, (void (*)(void *))destroy_cmd);
	return (1);
}

int	is_single_cmd(t_cmd_element *cmd)
{
	while (cmd)
	{
		if (cmd->type == OPERATOR)
			return (0);
		cmd = cmd->next;
	}
	return (1);
}

int	ft_exec_bloc(t_shell *shell, t_cmd_element *input)
{
	if (got_parenthesis(input))
		remove_parenthesis(&input);
	remove_pipe_parenthesis(&input);
	if (is_single_cmd(input))
		return (exec(shell, input));
	else
		return (ft_split_cmd(shell, input));
}
