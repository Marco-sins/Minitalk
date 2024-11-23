/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmembril <mmembril@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 13:25:09 by mmembril          #+#    #+#             */
/*   Updated: 2024/11/23 17:52:57 by mmembril         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <signal.h>

void	handler(int signal, struct siginfo_t *info, void *context)
{
	static int	i = 0;
	static char	byte = 0;

	(void)context;
	if (signal == SIGUSR1)
		byte |= 0b1 << i;
	i++;
	if (i == 8)
	{
		ft_printf("%c", byte);
		if (byte == '\0')
		{
			ft_printf("\n");
			if (info->si_pid > 0)
			kill(info->si_pid, SIGUSR1);
		}
		i = 0;
		byte = 0;
	}
}

int	main(void)
{
	int pid;
	struct sigaction sig;

	pid = getpid();
	ft_printf("The process ID is %d\n", pid);

	sigemptyset(&sig.sa_mask);
    sig.sa_flags = SA_SIGINFO;
    sig.sa_sigaction = handler;
	sigaction(SIGUSR1, &sig, NULL);
	sigaction(SIGUSR2, &sig, NULL);
	while (1)
	{
		pause();
		usleep(50);
	}
	return (0);
}