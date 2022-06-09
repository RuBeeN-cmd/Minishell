/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johrober <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 18:28:37 by johrober          #+#    #+#             */
/*   Updated: 2022/04/05 18:41:37 by johrober         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_get_nb_str(char const *s, char c)
{
	int	count;
	int	length;

	count = 0;
	length = 0;
	while (s[count])
	{
		if (s[count] == c && count > 0 && s[count - 1] != c)
			length++;
		count++;
	}
	if (count != 0 && s[count - 1] != c)
		length++;
	return (length);
}

static char	*ft_save_two_line(char const *s, int i, char c)
{
	int		length;
	char	*str;

	length = 0;
	while (s[i + length] != c && s[i + length])
		length++;
	str = ft_substr(s, i, length);
	if (str == NULL)
		return (NULL);
	return (str);
}

static char	**ft_free(char **str)
{
	int	count;

	if (str == NULL)
		return (NULL);
	count = 0;
	while (str[count] != NULL)
	{
		free(str[count]);
		count++;
	}
	free(str);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**tab_str;
	int		str_count;
	int		i;

	if (s == NULL)
		return (NULL);
	tab_str = malloc(sizeof(char *) * (ft_get_nb_str(s, c) + 1));
	if (tab_str == NULL)
		return (NULL);
	str_count = 0;
	i = -1;
	while (s[++i])
	{
		if (s[i] != c && (i == 0 || s[i - 1] == c))
		{
			tab_str[str_count] = ft_save_two_line(s, i, c);
			if (tab_str[str_count] == NULL)
				return (ft_free(tab_str));
			i += ft_strlen(tab_str[str_count]) - 1;
			str_count++;
		}
	}
	tab_str[str_count] = NULL;
	return (tab_str);
}
