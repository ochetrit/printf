/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochetrit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 11:56:24 by ochetrit          #+#    #+#             */
/*   Updated: 2023/11/10 09:14:45 by ochetrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H

# define  PRINTF_H
# include <stdlib.h>
# include <stdio.h>
# include <stdarg.h>
# include <unistd.h>
# include <limits.h>

int	ft_putchar(char c);
int	ft_putnbr(int nb);
int	ft_puthex(long nb, char key);
int	ft_strchr(const char *str, int character);
int	ft_write_ptr(char type, void *ptr);
int	ft_write_int(char type, long int nb);
int	ft_putstr(const char *format);
int	ft_check(const char *format);
int	ft_printf(const char *format, ...);
int	ft_putnbr_unsigned(unsigned int nb);

#endif
