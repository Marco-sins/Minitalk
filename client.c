/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmembril <mmembril@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 13:24:53 by mmembril          #+#    #+#             */
/*   Updated: 2024/11/09 16:24:45 by mmembril         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int ft_cifrar(char *str)
{
	int binario;
	int i;

    i = 0;
    binario = 0;
	if (str[i] >= 0)
	{
		while (str[i] > 0)
		{
			if (str[i] % 2 == 1) 	
				binario += 1;		
			else
				binario += 0;	
            binario *= 10;
			str[i] /= 2;			
		}
		ft_printf("%i", binario);	 
	}
    return (binario);
}

int main(int argc, char **argv)
{
    int pid;
    char *str;
    
    if (argc == 3)
    {
        pid = ft_atoi(argv[1]);
        str = argv[2];
        ft_printf ("%i\n%s\n", pid, str);
        ft_cifrar (str);
    }
    return (0);
}
