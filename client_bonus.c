/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmembril <mmembril@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 17:56:18 by mmembril          #+#    #+#             */
/*   Updated: 2025/01/20 12:22:41 by mmembril         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

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
		usleep(300);
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
		usleep(100);
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
