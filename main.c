/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrollin <rrollin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 15:40:26 by johrober          #+#    #+#             */
/*   Updated: 2022/06/09 17:37:38 by johrober         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/* t_shell *get_shell() */
/* { */
/* 	static t_shell shell; */

/* 	return (&shell); */
/* } */

int main(int argc, char **argv, char **env)
{
	char			*str = NULL;
	t_shell			shell;

	(void) argc;
	(void) argv;
	(void) str;
	init_tshell(&shell, env);
	set_signal_handlers();
	remove_env_var(&shell, "LESS");
	add_env_var(&shell, "USRNAME", "rrollin");
	print_env(&shell);
	str = readline(shell.prompt);
	while (str)
	{
		printf("%s\n", str);
		add_history(str);
		free(str);
		str = readline(shell.prompt);
	}
	destroy_tshell(&shell);
	printf("exit\n");
}
