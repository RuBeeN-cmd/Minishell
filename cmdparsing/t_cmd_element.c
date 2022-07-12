/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_cmd_element.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrollin <rrollin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 13:32:11 by johrober          #+#    #+#             */
/*   Updated: 2022/07/07 12:54:40 by johrober         ###   ########.fr       */
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

/* 	Function that detach and destroy an element elem from the list, splitting it into two lists, */
/* 	and returns the first element of the second list.
 *  Returns NULL if elem has not been found in the list. */
/* 		list		Point to the list (so the adress can be changed) */
/* 		elem		The elem to find and destroy */
t_cmd_element	*detach_element(t_cmd_element **list, t_cmd_element *elem)
{
	t_cmd_element	*current;
	t_cmd_element	*previous;
	t_cmd_element	*to_return;

	current = *list;
	previous = NULL;
	while (current)
	{
		if (current == elem)
		{
			if (!previous)
				*list = current->next;
			else
				previous->next = NULL;
			to_return = current->next;
			destroy_element(elem);
			return (to_return);
		}
		previous = current;
		current = current->next;
	}
	return (NULL);
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
