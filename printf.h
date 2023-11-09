/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochetrit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 11:56:24 by ochetrit          #+#    #+#             */
/*   Updated: 2023/11/09 09:41:08 by ochetrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H

# define  PRINTF_H
# include <stdlib.h>
# include <stdio.h>
# include <stdarg.h>
# include <unistd.h>

int	ft_putnbr(long nb);
int	ft_puthex(long nb);
int	ft_puthexbig(long nb);
int	ft_strchr(const char *str, int character);
int	ft_write_ptr(char type, void *ptr);
int	ft_write_int(char type, long nb);
int	ft_putstr(const char *format);
int	ft_check(const char *format);
int	ft_printf(const char *format, ...);

#endif