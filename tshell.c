/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tshell.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrollin <rrollin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 15:31:29 by johrober          #+#    #+#             */
/*   Updated: 2022/06/09 17:29:34 by johrober         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	init_tshell(t_shell *shell, char **env)
{
	shell->prompt = "> ";
	tcgetattr(0, &shell->termios_shell);
	shell->termios_shell.c_lflag &= ~ECHOCTL;
	tcsetattr(0, 0, &shell->termios_shell);
	shell->env = init_env(env);
}

void	destroy_tshell(t_shell *shell)
{
	destroy_env(shell->env);
	shell->env = NULL;
}
