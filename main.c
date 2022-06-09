/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrollin <rrollin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 15:40:26 by johrober          #+#    #+#             */
/*   Updated: 2022/06/09 15:46:30 by johrober         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/* t_shell *get_shell() */
/* { */
/* 	static t_shell shell; */

/* 	return (&shell); */
/* } */

int main()
{
	char			*str = NULL;
	t_shell			shell;

	init_tshell(&shell);
	set_signal_handlers();
	str = readline(shell.prompt);
	while(str)
	{
		printf("%s\n", str);
		add_history(str);
		free(str);
		str = readline(shell.prompt);
	}
	printf("exit\n");
}
