/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tenv_destroy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrollin <rrollin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 16:21:49 by rrollin           #+#    #+#             */
/*   Updated: 2022/07/07 15:33:01 by johrober         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	destroy_env_var(t_env_var *var)
{
	free(var->name);
	free(var->value);
	free(var);
}

void	destroy_env(t_env_var **env)
{
	int	i;

	i = -1;
	while (env[++i])
		destroy_env_var(env[i]);
	free(env);
}

void	remove_env_var(t_shell *shell, char *name)
{
	t_env_var	**env;
	t_env_var	*var;
	int			i;
	int			j;

	if (!get_env_var(shell, name))
		return ;
	env = malloc(sizeof(t_env_var *) * ft_tablen((const void **)shell->env));
	i = -1;
	j = 0;
	while (shell->env[++i])
	{
		var = shell->env[i];
		if (ft_strcmp(var->name, name))
		{
			env[j] = var;
			j++;
		}
		else
			destroy_env_var(var);
	}
	env[j] = NULL;
	free(shell->env);
	shell->env = env;
}
