/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johrober <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 12:03:02 by johrober          #+#    #+#             */
/*   Updated: 2022/04/05 18:45:17 by johrober         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*str;
	unsigned int	length;
	unsigned int	count;

	if (s == NULL)
		return (NULL);
	length = ft_strlen(s);
	str = malloc(sizeof(char) * (length + 1));
	if (str == NULL)
		return (NULL);
	str[length] = 0;
	count = 0;
	while (s[count] != 0)
	{
		str[count] = f(count, s[count]);
		count++;
	}
	return (str);
}
