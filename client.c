/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marco <marco@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 13:24:53 by mmembril          #+#    #+#             */
/*   Updated: 2024/12/09 22:11:34 by marco            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handler(int signal)
{
	(void)signal;
	exit(0);
}

void	ft_send_byte(char c, int pid)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		if (c & (0b1 << i))
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(50);
		i++;
	}
}

void	ft_send_char(int pid, char *msg)
{
	int	i;

	i = 0;
	while (msg[i])
	{
		ft_send_byte(msg[i], pid);
		usleep(50);
		i++;
	}
	ft_send_byte('\0', pid);
}

int	main(int argc, char **argv)
{
	if (argc == 3)
	{
		signal(SIGUSR1, handler);
		ft_send_char(ft_atoi(argv[1]), argv[2]);
	}
	return (0);
}
