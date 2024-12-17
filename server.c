/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmembril <mmembril@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 13:25:09 by mmembril          #+#    #+#             */
/*   Updated: 2024/12/17 17:26:19 by mmembril         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	signal_handler(int signal, siginfo_t *info, void *context)
{
	static int	i = 0;
	static char	byte = 0;

	(void)context;
	if (signal == SIGUSR1)
		byte |= 0b1 << i;
	i++;
	if (i == 8)
	{
		if (byte == '\0')
		{
			ft_printf("\n");
			if (info->si_pid > 0)
				kill(info->si_pid, SIGUSR1);
		}
		else
			ft_printf("%c", byte);
		i = 0;
		byte = 0;
	}
}

int	main(void)
{
	struct sigaction	sig;
	int					pid;

	pid = getpid();
	ft_printf("The process ID is %d\n", pid);
	sig.sa_sigaction = signal_handler;
	sig.sa_flags = SA_SIGINFO;
	sigemptyset(&sig.sa_mask);
	sigaction(SIGUSR1, &sig, NULL);
	sigaction(SIGUSR2, &sig, NULL);
	while (1)
	{
		usleep(100);
	}
	return (0);
}
