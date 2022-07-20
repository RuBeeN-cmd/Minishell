/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_handler.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrollin <rrollin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 14:42:07 by johrober          #+#    #+#             */
/*   Updated: 2022/07/13 17:22:10 by johrober         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../minishell.h"

t_builtin	*init_builtin(char *name,
		void (*f)(t_shell *shell, int argc, char **argv))
{
	t_builtin	*new;

	new = malloc(sizeof(t_builtin));
	new->name = name;
	new->f = f;
	return (new);
}

void	init_builtin_list(t_shell *shell)
{
	shell->builtin_list[0] = init_builtin("cd", &cd);
	shell->builtin_list[1] = init_builtin("pwd", &pwd);
	shell->builtin_list[2] = init_builtin("env", &env);
	shell->builtin_list[3] = init_builtin("export", &export);
	shell->builtin_list[4] = init_builtin("unset", &unset);
	shell->builtin_list[5] = init_builtin("echo", &echo);
	shell->builtin_list[6] = init_builtin("exit", &exit_builtin);
	shell->builtin_list[7] = NULL;
}

void	destroy_builtin_list(t_shell *shell)
{
	int	count;

	count = -1;
	while (shell->builtin_list[++count])
		free(shell->builtin_list[count]);
}

int	call_builtin_if_exists(t_shell *shell, t_cmd *cmd)
{
	int			count;
	t_builtin	*builtin;

	count = -1;
	builtin = NULL;
	while (++count < BUILTIN_NB)
	{
		if (!ft_strcmp(shell->builtin_list[count]->name, cmd->argv[0]))
		{
			builtin = shell->builtin_list[count];
			break;
		}
	}
	if (!builtin)
		return (0);
	builtin->f(shell, cmd->argc, cmd->argv);
	return (1);
}
