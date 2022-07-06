/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_wildcards.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johrober <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 15:05:07 by johrober          #+#    #+#             */
/*   Updated: 2022/07/04 14:57:09 by johrober         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	handle_wildcards(t_cmd_element **list)
{
	t_cmd_element	*current;
	char			**matching_files;

	current = *list;
	while (current)
	{
		if (current->type == WORD && ft_str_contains(current->str, '*'))
		{
			matching_files = get_matching_files(current->str);
			if (matching_files)
				current = replace_cmd_elements_by(current, matching_files);
		}
		current = current->next;
	}
}

t_cmd_element	*replace_cmd_elements_by(t_cmd_element *current, char **matching_files)
{
	t_cmd_element	*previous;
	t_cmd_element	*end;
	int				count;

	free(current->str);
	current->str = matching_files[0];
	count = 0;
	end = current->next;
	previous = current;
	while (matching_files[++count])
	{
		current = init_element(matching_files[count], WORD);
		previous->next = current;
		previous = current;
	}
	current->next = end;
	free(matching_files);
	return (current);
}

char	**get_matching_files(char *expr)
{
	DIR				*dir;
	struct dirent	*dirent;
	char			**matching_files;

	matching_files = NULL;
	dir = opendir(".");
	dirent = readdir(dir);
	while (dirent)
	{
		if (is_matching_wildcard(dirent->d_name, expr))
			ft_tab_insert((void ***)&matching_files,
					ft_tablen((const void **)matching_files),
					ft_strdup(dirent->d_name));
		dirent = readdir(dir);
	}
	closedir(dir);
	//if (!matching_files)
		//Output error (no match found)
	return (matching_files);
}

int	is_matching_wildcard(char *name, char *expr)
{
	char	*wildcard;
	char	*match;
	int		length;

	wildcard = ft_strchr(expr, '*');
	length = wildcard - expr;
	if (length > 0 && ft_strncmp(name, expr, length))
		return (0);
	if (advance_in_word(&name, &expr, length, name))
		return (1);
	wildcard = ft_strchr(expr, '*');
	while (wildcard)
	{
		length = wildcard - expr;
		match = ft_strsubstr(name, expr, length);
		if (!match)
			return (0);
		if (advance_in_word(&name, &expr, length, match))
			return (1);
		wildcard = ft_strchr(expr, '*');
	}
	match = ft_strsubstr(name, expr, ft_strlen(expr));
	if (match && ft_strlen(match) == ft_strlen(expr))
		return (1);
	return (0);
}

int	advance_in_word(char **name, char **expr, int length, char *match)
{
	*expr += length + 1;
	while (**expr && **expr == '*')
		(*expr)++;
	if (!**expr)
		return (1);
	*name = match + length;
	return (0);
}
