/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johrober <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 12:54:47 by johrober          #+#    #+#             */
/*   Updated: 2022/04/04 14:45:35 by johrober         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalnum(int character)
{
	if ((character <= '9' && character >= '0')
		|| (character <= 'z' && character >= 'a')
		|| (character <= 'Z' && character >= 'A'))
	{
		return (1);
	}
	else
		return (0);
}
