/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_parse_final.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johrober <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 15:22:28 by johrober          #+#    #+#             */
/*   Updated: 2022/07/21 13:03:11 by johrober         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_cmd	**parse_final(t_cmd_element *list)
{
	t_cmd			**tab;
	t_cmd_element	*current;
	t_cmd_element	*list_start;
	int				nb_pipe;
	int				count;

	tab = NULL;
	nb_pipe = count_pipes(list);
	current = list;
	list_start = current;
	count = 0;
	while (count < nb_pipe)
	{
		if (current->type == PIPE)
		{
			current = detach_element(&list_start, current);
			ft_tab_insert((void ***)&tab, count++, parse_single_cmd(list_start));
			destroy_element_list(list_start);
			list_start = current;
		}
		current = current->next;
	}
	ft_tab_insert((void ***)&tab, count++, parse_single_cmd(list_start));
	destroy_element_list(list_start);
	return (tab);
}

t_cmd	*parse_single_cmd(t_cmd_element *list)
{
	t_cmd			*cmd;
	t_cmd_element	*current;
	t_cmd_element	*previous;

	cmd = init_cmd();
	cmd->redir_tab = parse_redirections(list);
	current = list;
	previous = NULL;
	while (current)
	{
		if (current->type == WORD && (!previous || previous->type != REDIRECT))
			ft_tab_insert((void ***)&(cmd->argv), cmd->argc++, ft_strdup(current->str));
		previous = current;
		current = current->next;
	}
	return (cmd);
}

t_redir	**parse_redirections(t_cmd_element *list)
{
	t_redir			**redir_tab;
	t_cmd_element	*current;
	int				count;

	count = 0;
	current = list;
	redir_tab = NULL;
	while (current)
	{
		if (current->type == REDIRECT)
			ft_tab_insert((void ***)&redir_tab, count++,
				init_redir(current->next->str, current->str));
		current = current->next;
	}
	return (redir_tab);
}
