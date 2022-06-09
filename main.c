/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johrober <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 15:40:26 by johrober          #+#    #+#             */
/*   Updated: 2022/06/08 17:19:09 by johrober         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/* t_shell *get_shell() */
/* { */
/* 	static t_shell shell; */

/* 	return (&shell); */
/* } */

int	interrupted = 0;

void	receive(int signum)
{
	(void)signum;
	printf("\n");
	rl_replace_line("", 0);
	if (signum == SIGINT)
		rl_on_new_line();
	rl_redisplay();
}

int main()
{
	char	*str = NULL;

	signal(SIGINT, &receive);
	signal(SIGQUIT, &receive);
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
		str = readline(">");
	}
}
