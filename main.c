/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrollin <rrollin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 15:40:26 by johrober          #+#    #+#             */
/*   Updated: 2022/07/13 17:21:31 by johrober         ###   ########.fr       */
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
	str = readline(shell->prompt);
	while (str)
	{
		list = split_into_element_list(shell, str);
		handle_wildcards(&list);
		if (is_syntax_valid(list))
			ft_exec_bloc(shell, list);
		else
			ft_printf("Syntax error in command.\n");
		add_history(str);
		free(str);
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
