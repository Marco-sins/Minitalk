/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmembril <mmembril@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 13:25:09 by mmembril          #+#    #+#             */
/*   Updated: 2024/11/09 16:34:44 by mmembril         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "minitalk.h"

int main()
{
    int pid;

    pid = getpid();
    ft_printf("The process ID is %d\n", pid);
    while (1)
        pause();
    return 0;
}