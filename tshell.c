/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tshell.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrollin <rrollin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 15:31:29 by johrober          #+#    #+#             */
/*   Updated: 2022/06/25 15:37:59 by rrollin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_shell	*init_tshell(char **env)
{
	t_shell	*shell;

	shell = malloc(sizeof(t_shell));
	shell->prompt = "\e[1;34m>\033[0;37m ";
	tcgetattr(0, &shell->termios_shell);
	shell->termios_shell.c_lflag &= ~ECHOCTL;
	tcsetattr(0, 0, &shell->termios_shell);
	shell->env = init_env(env);
	shell->pwd = NULL;
	shell->pwd = getcwd(shell->pwd, 0);
	init_builtin_list(shell);
	return (shell);
}

void	destroy_tshell(t_shell *shell)
{
	destroy_env(shell->env);
	destroy_builtin_list(shell);
	shell->env = NULL;
	if (shell->pwd)
		free(shell->pwd);
	free(shell);
}
