/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johrober <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 17:53:29 by johrober          #+#    #+#             */
/*   Updated: 2022/04/05 18:37:17 by johrober         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	length;
	char	*str;
	int		str_count;
	int		count;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	length = ft_strlen(s1) + ft_strlen(s2);
	str = malloc(sizeof(char) * (length + 1));
	if (str == NULL)
		return (NULL);
	count = 0;
	str_count = 0;
	while (s1[count])
		str[str_count++] = s1[count++];
	count = 0;
	while (s2[count])
		str[str_count++] = s2[count++];
	str[str_count] = 0;
	return (str);
}
