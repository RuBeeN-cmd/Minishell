/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tcmd.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrollin <rrollin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 12:36:31 by johrober          #+#    #+#             */
/*   Updated: 2022/06/25 15:42:29 by rrollin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

t_cmd	*init_cmd(void)
{
	t_cmd	*cmd;

	cmd = malloc(sizeof(t_cmd));
	cmd->argc = 0;
	cmd->argv = NULL;
	return (cmd);
}

void	destroy_cmd(t_cmd *cmd)
{
	free(cmd->function);
	ft_free_tab((void **)cmd->arguments);
	free(cmd);
}
