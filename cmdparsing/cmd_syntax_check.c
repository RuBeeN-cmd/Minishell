/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_syntax_check.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johrober <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 12:02:52 by johrober          #+#    #+#             */
/*   Updated: 2022/07/06 12:05:35 by johrober         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	is_syntax_valid(t_cmd_element *list)
{
	t_cmd_element	*cur;
	int				words;

	cur = list;
	words = 0;
	while (cur)
	{
		if (cur->type == WORD)
			words++;
		if (cur->type == REDIRECT && (!cur->next || cur->next->type != WORD))
			return (0);
		if ((cur->type == OPERATOR || cur->type == PIPE) && !words)
			return (0);
		if (cur->type == OPERATOR || cur->type == PIPE)
			words = 0;
		cur = cur->next;
	}
	if (words == 0 || !is_parenthesis_syntax_valid(list))
		return (0);
	return (1);
}

int	is_parenthesis_syntax_valid(t_cmd_element *list)
{
	t_cmd_element	*cur;
	int				words[PARENTHESIS_NB];
	int				parenthesis;

	parenthesis = -1;
	while (++parenthesis < PARENTHESIS_NB)
		words[parenthesis] = -1;
	parenthesis = -1;
	cur = list;
	while (cur)
	{
		if (cur->type == PARENTHESIS && !ft_strcmp(cur->str, "(") && parenthesis >= -1)
			words[++parenthesis] = 0;
		if (cur->type == WORD && cur->next && cur->next->type == PARENTHESIS
				&& !ft_strcmp(cur->next->str, "("))
			return (0);
		if (cur->type == WORD && parenthesis > -1)
			words[parenthesis] += 1;
		if (cur->type == PARENTHESIS && !ft_strcmp(cur->str, ")")
			&& (parenthesis < 0 || words[parenthesis] == 0))
			return (0);
		if (cur->type == PARENTHESIS && !ft_strcmp(cur->str, ")"))
			words[parenthesis--] = -1;
		cur = cur->next;
	}
	return (parenthesis == -1);
}
