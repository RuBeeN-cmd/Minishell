/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johrober <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 13:03:23 by johrober          #+#    #+#             */
/*   Updated: 2022/07/02 13:12:38 by johrober         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnjoin(char *s1, char *s2, int length)
{
	int		size;
	char	*str;
	int		count;
	int		str_count;

	size = 0;
	while (s1 && s1[size])
		size++;
	if (s2)
		size += ft_lower(length, ft_strlen(s2));
	str = malloc(sizeof(char) * (size + 1));
	if (!str)
		return (NULL);
	count = 0;
	str_count = 0;
	while (s1 && s1[count])
		str[str_count++] = s1[count++];
	count = 0;
	while (count < length && s2[count])
		str[str_count++] = s2[count++];
	str[str_count] = 0;
	if (s1)
		free(s1);
	return (str);
}
