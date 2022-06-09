/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johrober <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 13:14:37 by johrober          #+#    #+#             */
/*   Updated: 2022/04/26 11:57:33 by johrober         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_stradd(char *str, char c)
{
	char	*new;
	int		count;

	if (ft_strchr(str, c))
		return (str);
	new = malloc(sizeof(char) * (ft_strlen(str) + 2));
	if (!new)
		return (NULL);
	count = -1;
	while (str[++count])
		new[count] = str[count];
	new[count++] = c;
	new[count] = 0;
	free(str);
	return (new);
}

int	ft_strcontains_any(char *str, char *set)
{
	int	count;
	int	contains;

	count = 0;
	contains = 0;
	while (set[count] && !contains)
		if (ft_strchr(str, set[count++]))
			contains++;
	return (contains);
}

char	*ft_strremove(char *str, char *set)
{
	int	count;

	count = 0;
	while (set[count])
		str = ft_strremove_one(str, set[count++]);
	return (str);
}

char	*ft_strremove_one(char *str, char c)
{
	char	*new;
	int		count;
	int		occurence;
	int		strcount;

	count = -1;
	occurence = 0;
	while (str[++count])
		if (str[count] == c)
			occurence++;
	new = malloc(sizeof(char) * ft_strlen(str) + 1 - occurence);
	if (!new)
		return (NULL);
	count = 0;
	strcount = 0;
	while (str[count])
	{
		if (str[count] != c)
			new[strcount++] = str[count];
		count++;
	}
	new[strcount] = 0;
	free(str);
	return (new);
}

char	*ft_strjoin_free(char *s1, char *s2)
{
	char	*str;

	str = NULL;
	if (s1 && s2)
		str = ft_strjoin(s1, s2);
	if (s1)
		free(s1);
	if (s2)
		free(s2);
	return (str);
}
