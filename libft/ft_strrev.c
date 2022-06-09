/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johrober <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 13:40:26 by johrober          #+#    #+#             */
/*   Updated: 2022/04/18 13:02:32 by johrober         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrev(char *str)
{
	int		count;
	int		length;
	char	buffer;

	length = ft_strlen(str);
	if (str == NULL)
		return (NULL);
	count = 0;
	while (count < length / 2)
	{
		buffer = str[count];
		str[count] = str[length - count - 1];
		str[length - count - 1] = buffer;
		count++;
	}
	return (str);
}
