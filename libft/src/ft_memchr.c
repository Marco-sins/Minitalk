/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmembril <mmembril@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 12:12:56 by mmembril          #+#    #+#             */
/*   Updated: 2024/11/09 14:14:33 by mmembril         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*str;
	unsigned char	a;
	size_t			i;

	i = 0;
	str = (unsigned char *)s;
	a = (unsigned char)c;
	while (n > i)
	{
		if (*str == a)
			return (str);
		i++;
		str++;
	}
	return (NULL);
}
