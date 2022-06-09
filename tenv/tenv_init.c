/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tenv_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrollin <rrollin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 16:45:22 by rrollin           #+#    #+#             */
/*   Updated: 2022/06/09 17:34:15 by johrober         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_env_var	*init_env_var(char *name, char *value)
{
	t_env_var *var;

	var = malloc(sizeof(t_env_var));
	var->name = name;
	var->value = value;
	return (var);
}

t_env_var	*parse_env_var(char *env_str)
{
	char	*name;
	char	*value;
	char	*eq_ptr;
    
	eq_ptr = ft_strchr(env_str, '=');
	name = ft_substr(env_str, 0, eq_ptr - env_str);
	value = ft_substr(eq_ptr, 1, ft_strlen(eq_ptr) - 1);
	return (init_env_var(name, value));
}

t_env_var	**init_env(char **env_str)
{
	t_env_var 	**env;
	int			i;

	env = malloc(sizeof(void *) * (ft_tablen((const void **) env_str) + 1));
	i = -1;
	while (env_str[++i])
		env[i] = parse_env_var(env_str[i]);
	env[i] = NULL;
	return (env);
}
