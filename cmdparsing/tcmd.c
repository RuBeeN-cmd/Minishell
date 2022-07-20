/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tcmd.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrollin <rrollin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 12:36:31 by johrober          #+#    #+#             */
/*   Updated: 2022/07/13 16:28:19 by johrober         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_cmd	*init_cmd(void)
{
	t_cmd	*cmd;

	cmd = malloc(sizeof(t_cmd));
	cmd->argc = 0;
	cmd->argv = NULL;
	cmd->env = NULL;
	cmd->redir_tab = NULL;
	return (cmd);
}

void	destroy_cmd(t_cmd *cmd)
{
	if (cmd->argv)
		ft_destroy_tab((void ***)&cmd->argv, &free);
	if (cmd->redir_tab)
		ft_destroy_tab((void ***)&cmd->redir_tab, (void (*)(void *))destroy_redir);
	if (cmd->env)
		ft_destroy_tab((void ***)&cmd->env, &free);
	free(cmd);
}

void	print_cmd(t_cmd *cmd)
{
	int	count;

	printf("\tArgc\n\t\t%d\n", cmd->argc);
	printf("\tArgv\n");
	count = -1;
	while (cmd->argv && cmd->argv[++count])
		printf("\t\t%s\n", cmd->argv[count]);
	printf("\tRedirections\n");
	count = -1;
	while(cmd->redir_tab && cmd->redir_tab[++count])
	{
		printf("\t\tType\t");
		if (cmd->redir_tab[count]->type == REPLACE)
			printf("Replace");
		if (cmd->redir_tab[count]->type == APPEND)
			printf("Append");
		if (cmd->redir_tab[count]->type == IN)
			printf("Infile");
		if (cmd->redir_tab[count]->type == UNTIL)
			printf("Until");
		printf("\t\t\tValue\t%s\n", cmd->redir_tab[count]->str);
	}
}

t_redir	*init_redir(char *str, char *redir_type)
{
	t_redir	*redir;

	redir = malloc(sizeof(t_redir));
	redir->str = ft_strdup(str);
	if (!ft_strcmp(redir_type, ">"))
		redir->type = REPLACE;
	else if (!ft_strcmp(redir_type, ">>"))
		redir->type = APPEND;
	else if (!ft_strcmp(redir_type, "<"))
		redir->type = IN;
	else if (!ft_strcmp(redir_type, "<<"))
		redir->type = UNTIL;
	return (redir);
}

void	destroy_redir(t_redir *redir)
{
	free(redir->str);
	free(redir);
}
