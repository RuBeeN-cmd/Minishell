/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tshell.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johrober <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 15:31:29 by johrober          #+#    #+#             */
/*   Updated: 2022/06/09 15:46:00 by johrober         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	init_tshell(t_shell *shell)
{
	shell->prompt = "> ";
	tcgetattr(0, &shell->termios_shell);
	shell->termios_shell.c_lflag &= ~ECHOCTL;
	tcsetattr(0, 0, &shell->termios_shell);
}

/* void	destroy_tshell(t_shell *shell) */
