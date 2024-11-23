/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmembril <mmembril@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 13:25:09 by mmembril          #+#    #+#             */
/*   Updated: 2024/11/23 17:30:57 by mmembril         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "minitalk.h"
# include <signal.h>

void    handler(int signal, struct __siginfo *info, void *context)
{
    static int  i;
    static char byte;

    (void) context;
    if (signal == SIGUSR1)
        byte |= 0b1 << i;
    i++;
    if (i == 8)
    {
        ft_printf("%c", byte);
        if (byte == '\0')
        {
            ft_printf("\n");
            kill (info->si_pid, SIGUSR1);
        }
        i = 0;
        byte = 0;
    }
}

int main()
{
    int pid;
    struct sigaction sig;

    pid = getpid();
    ft_printf("The process ID is %d\n", pid);

    sigemptyset(&sig.sa_mask);
	sig.sa_flags = SA_SIGINFO;
	sig.sa_sigaction = handler;

    while (1)
    {
        sigaction(SIGUSR1, &sig, NULL);
        sigaction(SIGUSR2, &sig, NULL);
        pause();
        usleep(50);
    }
    return (0);
}