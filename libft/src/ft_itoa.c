/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmembril <mmembril@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 18:36:04 by mmembril          #+#    #+#             */
/*   Updated: 2024/10/02 16:43:12 by mmembril         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>

static int	count_digit(long int n)
{
	int	count;

	count = 0;
	if (n == 0)
		count = 1;
	else
	{
		if (n < 0)
		{
			n *= -1;
			count++;
		}
		while (n > 0)
		{
			n /= 10;
			count++;
		}
	}
	return (count);
}

char	*ft_itoa(int n)
{
	char		*str;
	int			cont;
	long int	nbr;

	nbr = n;
	cont = count_digit(nbr);
	str = ft_calloc(sizeof(char), cont + 1);
	if (!str)
		return (NULL);
	str[cont--] = '\0';
	if (nbr == 0)
		str[0] = '0';
	if (nbr < 0)
	{
		str[0] = '-';
		nbr *= -1;
	}
	while (nbr > 0)
	{
		str[cont--] = nbr % 10 + '0';
		nbr /= 10;
	}
	return (str);
}
