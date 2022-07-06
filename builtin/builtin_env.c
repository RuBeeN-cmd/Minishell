/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrollin <rrollin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 13:24:46 by rrollin           #+#    #+#             */
/*   Updated: 2022/06/25 15:40:32 by rrollin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../minishell.h"

void	env(t_shell *shell, int argc, char **argv)
{
	(void)argv;
	if (argc == 1)
		print_env(shell);
	else
		printf("env: too many arguments");
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
		}
		else if (eq_ptr == argv[i])
			printf("export: invalids arguments");
	}
}

void	unset(t_shell *shell, int argc, char **argv)
{
	int			i;

	i = 0;
	while (++i < argc)
		remove_env_var(shell, argv[i]);
}
