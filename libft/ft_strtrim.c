/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johrober <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 18:03:27 by johrober          #+#    #+#             */
/*   Updated: 2022/06/21 12:48:18 by johrober         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
