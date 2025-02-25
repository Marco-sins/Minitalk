/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmembril <mmembril@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 20:48:11 by mmembril          #+#    #+#             */
/*   Updated: 2025/02/25 12:59:01 by mmembril         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

int	ft_printf(char const *str, ...);
int	ft_type(char c, va_list args);
int	ft_putchar_fd_printf(char c, int fd);
int	ft_putnbr_fd_printf(int n, int fd);
int	ft_putstr_fd_printf(char *s, int fd);
int	ft_printhex(unsigned long long num, char *base, int fd);
int	ft_cont_numbers(int i);
int	ft_putchar_fd2(char c, int fd);
int	ft_get_ptr(unsigned long long i, int fd);

#endif
