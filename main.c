/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johrober <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 15:40:26 by johrober          #+#    #+#             */
/*   Updated: 2022/06/09 15:07:25 by johrober         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/* t_shell *get_shell() */
/* { */
/* 	static t_shell shell; */

/* 	return (&shell); */
/* } */

void	receive(int signum)
{
	if (signum == SIGINT)
	{
		printf("\n");
		rl_replace_line("", 0);
		rl_on_new_line();
		rl_redisplay();
	}
}

int main()
{
	char			*str = NULL;
	struct termios	termios_save;

	signal(SIGINT, &receive);
	signal(SIGQUIT, &receive);
	tcgetattr(0, &termios_save);
	termios_save.c_lflag &= ~ECHOCTL;
	tcsetattr(0, 0, &termios_save);
	str = readline(">");
	while(str)
	{
		if (str && *str)
		{
			printf("%s\n", str);
			add_history(str);
			free(str);
			str = NULL;
		}
		tcgetattr(0, &termios_save);
		str = readline(">");
	}
}
