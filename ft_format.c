/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochetrit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 16:37:05 by ochetrit          #+#    #+#             */
/*   Updated: 2023/11/09 09:10:16 by ochetrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "printf.h"

int	ft_strchr(const char *str, int character)
{
	while (*str && *str != (unsigned char)character)
		str++;
	if (*str == (unsigned char)character)
		return (1);
	return (0);
}

int	ft_check(const char *format)
{
	int			count;
	const char	*str;

	str = format;
	count = 0;
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (ft_strchr("cspdiuxX%", *format) && *format)
				count++;
			else
				return (-1);
		}
		format++;
	}
	return (count);
}
