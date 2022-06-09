/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tenv_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrollin <rrollin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 16:47:58 by rrollin           #+#    #+#             */
/*   Updated: 2022/06/09 17:28:21 by johrober         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_env_var	*get_env_var(t_shell *shell, char *name)
{
	t_env_var	*var;
	int			i;
	
	i = -1;
	while(shell->env[++i])
	{
		var = shell->env[i];
		if (!ft_strcmp(var->name, name))
			return (var);
	}
	return (NULL);
}

void	add_env_var(t_shell	*shell, char *name, char *value)
{
	int			len;

	len = ft_tablen((const void **)shell->env);
	shell->env = (t_env_var **)ft_add_row((void **)shell->env);
	shell->env[len] = init_env_var(name, value);
}

void	set_env_var(t_shell *shell, char *name, char *value)
{
	t_env_var	*var;

	var = get_env_var(shell, name);
	if (var)
		var->value = value;
	else
		printf("Var %s not found", name);
}

void	print_env(t_shell *shell)
{
	t_env_var	*var;
	int			i;

	i = -1;
	while (shell->env[++i])
	{
		var = shell->env[i];
		printf("%-30s%s\n", var->name, var->value);
	}
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
