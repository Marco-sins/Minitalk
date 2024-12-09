/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marco <marco@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 13:25:09 by mmembril          #+#    #+#             */
/*   Updated: 2024/12/09 22:08:38 by marco            ###   ########.fr       */
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
		printf("%c", byte);
		if (byte == '\0')
		{
			printf("\n");
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
	printf("The process ID is %d\n", pid);

    sig.sa_sigaction = signal_handler;
    sig.sa_flags = SA_SIGINFO;
	sigemptyset(&sig.sa_mask);
	sigaction(SIGUSR1, &sig, NULL);
	sigaction(SIGUSR2, &sig, NULL);
	while (1)
	{
		usleep(50);
	}
	return (0);
}