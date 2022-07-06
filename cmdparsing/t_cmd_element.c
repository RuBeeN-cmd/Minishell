/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_cmd_element.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrollin <rrollin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 13:32:11 by johrober          #+#    #+#             */
/*   Updated: 2022/07/02 16:42:23 by johrober         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_cmd_element	*init_element(char *str, t_elem_type type)
{
	t_cmd_element	*new;

	new = malloc(sizeof(t_cmd_element));
	new->next = NULL;
	new->str = str;
	new->type = type;
	return (new);
}

void	destroy_element(t_cmd_element *elem)
{
	free(elem->str);
	free(elem);
}

void	destroy_element_list(t_cmd_element *elem)
{
	t_cmd_element	*current;
	t_cmd_element	*next;

	current = elem;
	while (current)
	{
		next = current->next;
		destroy_element(current);
		current = next;
	}
}

void	print_element(t_cmd_element *elem)
{
	printf("\tType :\t\t");
	if (elem->type == WORD)
		printf("Word\n");
	else if (elem->type == REDIRECT)
		printf("Redirect\n");
	else if (elem->type == OPERATOR)
		printf("Binary operator\n");
	else if (elem->type == PIPE)
		printf("Pipe\n");
	else if (elem->type == PARENTHESIS)
		printf("Parenthesis\n");
	else
		printf("Unknown");
	printf("\tContent\t\t%s\n", elem->str);

}

void	print_element_list(t_cmd_element *elem)
{
	t_cmd_element	*current;
	int				count;

	current = elem;
	count = 1;
	while(current)
	{
		printf("Element %2.d\n", count);
		print_element(current);
		count++;
		current = current->next;
	}
}
