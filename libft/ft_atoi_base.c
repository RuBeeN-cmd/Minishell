/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johrober <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 15:33:27 by johrober          #+#    #+#             */
/*   Updated: 2022/04/28 15:36:32 by johrober         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	char_to_int_base(char *str, char *base, int base_length);
static int	get_char_value_from_base(char a, char *base);

int	ft_atoi_base(char *str, char *base)
{
	int	bsize;
	int	count;
	int	sign;

	bsize = -1;
	while (base[++bsize])
	{
		count = -1;
		while (base[++count])
			if (count != bsize && base[count] == base[bsize])
				return (0);
		if (base[bsize] == '-' || base[bsize] == '+' || base[bsize] == ' ')
			return (0);
	}
	if (bsize <= 1)
		return (0);
	while (*str == ' ' || *str == '\f' || *str == '\n' || *str == '\r'
		|| *str == '\t' || *str == '\v')
		str++;
	sign = 1;
	while (*str == '-' || *str == '+')
		if (*str++ == '-')
			sign *= -1;
	return (sign * char_to_int_base(str, base, bsize));
}

static int	char_to_int_base(char *str, char *base, int base_length)
{
	int	result;
	int	count;
	int	str_length;
	int	nbr;

	str_length = 0;
	while (str[str_length])
		str_length++;
	result = 0;
	count = 0;
	while (count < str_length)
	{
		nbr = get_char_value_from_base(str[count], base);
		if (nbr == -1)
			return (result);
		result *= base_length;
		result += nbr;
		count++;
	}
	return (result);
}

static int	get_char_value_from_base(char a, char *base)
{
	int	count;

	count = 0;
	while (base[count])
	{
		if (base[count] == a)
			return (count);
		count++;
	}
	return (-1);
}
