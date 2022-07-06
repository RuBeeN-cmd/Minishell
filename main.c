/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrollin <rrollin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 15:40:26 by johrober          #+#    #+#             */
/*   Updated: 2022/07/06 12:01:38 by johrober         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int argc, char **argv, char **env)
{
	char			*str;
	t_shell			*shell;
	t_cmd_element	*list;

	(void) argc;
	(void) argv;
	shell = init_tshell(env);
	set_signal_handlers();
	/* str = ft_strdup("echo lol && (echo)"); */
	str = readline(shell->prompt);
	while (str)
	{
		list = split_into_element_list(shell, str);
		handle_wildcards(&list);
		print_element_list(list);
		if (is_syntax_valid(list))
			ft_printf("SYNTAX OK\n");
		else
			ft_printf("SYNTAX KO\n");
		//ft_exec_bloc(list);
		add_history(str);
		free(str);
		/* str = NULL; */
		str = readline(shell->prompt);
	}
	destroy_tshell(shell);
	printf("exit\n");
}

/** Not used currently **/
void	clean_exit(t_shell *shell, int exit_code)
{
	destroy_tshell(shell);
	exit(exit_code);
}
