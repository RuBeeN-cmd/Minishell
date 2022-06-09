/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johrober <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 18:03:27 by johrober          #+#    #+#             */
/*   Updated: 2022/04/05 19:03:11 by johrober         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_str_contains(const char *str, const char character);

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	int		offset;
	int		length;
	int		count;

	if (s1 == NULL || set == NULL)
		return (NULL);
	offset = 0;
	while (ft_str_contains(set, s1[ft_strlen(s1) - offset - 1]))
		offset++;
	length = ft_strlen(s1) - offset;
	offset = 0;
	while (ft_str_contains(set, s1[offset]))
		offset++;
	length -= offset;
	if (length < 0)
		length = 0;
	str = malloc(sizeof(char) * (length + 1));
	if (str == NULL)
		return (NULL);
	count = -1;
	while (++count < length)
		str[count] = s1[offset + count];
	str[count] = 0;
	return (str);
}

static int	ft_str_contains(const char *str, const char character)
{
	int	count;

	count = 0;
	while (str[count] && str[count] != character)
		count++;
	if (!str[count] && character != 0)
		return (0);
	else
		return (1);
}
