/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrollin <rrollin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 13:24:46 by rrollin           #+#    #+#             */
/*   Updated: 2022/07/13 17:19:43 by johrober         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../minishell.h"

void	env(t_shell *shell, int argc, char **argv)
{
	(void)argv;
	if (argc == 1)
	{
		print_env(shell);
		exit(EXIT_SUCCESS);
	}
	else
		ft_printf_fd(2, "env: too many arguments\n");
}

void	export(t_shell *shell, int argc, char **argv)
{
	t_env_var	*env_var_ptr;
	char		**var;
	char		*eq_ptr;
	int			i;

	i = 0;
	while (++i < argc)
	{
		eq_ptr = ft_strchr(argv[i], '=');
		if (eq_ptr && eq_ptr != argv[i])
		{
			var = ft_split(argv[i], '=');
			if (!var[1])
				var[1] = ft_strdup("");
			env_var_ptr = get_env_var(shell, var[0]);
			if (env_var_ptr)
				env_var_ptr->value = var[1];
			else
				add_env_var(shell, var[0], var[1]);
			free(var);
			exit(EXIT_SUCCESS);
		}
		else if (eq_ptr == argv[i])
		{
			ft_printf_fd(2, "export: invalids arguments\n");
			break;
		}
	}
}

void	unset(t_shell *shell, int argc, char **argv)
{
	int	i;

	i = 0;
	while (++i < argc)
		remove_env_var(shell, argv[i]);
	if (argc == 1)
		ft_printf_fd(2, "unset: not enough arguments.\n");
	else
		exit(EXIT_SUCCESS);
}
