/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrollin <rrollin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 12:22:45 by rrollin           #+#    #+#             */
/*   Updated: 2022/07/13 17:08:29 by johrober         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../minishell.h"

int	exec(t_shell *shell, t_cmd_element *list)
{
	shell->cmd_tab = parse_final(list);
	if (ft_tablen((const void **)shell->cmd_tab) == 1
		&& !ft_strcmp(shell->cmd_tab[0]->argv[0], "exit"))
		exit_builtin(shell, shell->cmd_tab[0]->argc, shell->cmd_tab[0]->argv);
	shell->exit_status = execute(shell, shell->cmd_tab);
	ft_destroy_tab((void ***)&shell->cmd_tab, (void (*)(void *))destroy_cmd);
	shell->cmd_tab = NULL;
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
