/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tenv_destroy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrollin <rrollin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 16:21:49 by rrollin           #+#    #+#             */
/*   Updated: 2022/06/24 13:59:47 by rrollin          ###   ########.fr       */
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
