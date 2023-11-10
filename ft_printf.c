/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochetrit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 16:10:17 by ochetrit          #+#    #+#             */
/*   Updated: 2023/11/10 09:14:01 by ochetrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "printf.h"

int	ft_format(va_list args, const char *format)
{
	int	n_oct;

	if (*format == 'c')
		n_oct = ft_putchar(va_arg(args, int));
	else if (*format == 's')
		n_oct = ft_putstr(va_arg(args, char *));
	else if (ft_strchr("di", *format))
		n_oct = ft_putnbr(va_arg(args, int));
	else if (*format == 'u')
		n_oct = ft_putnbr_unsigned(va_arg(args, unsigned int));
	else if (*format == 'p')
		n_oct = write(1, "0x", 2) + ft_puthex((long)va_arg(args, void *), 'x');
	else if (ft_strchr("xX", *format))
		n_oct = ft_puthex(va_arg(args, unsigned int), *format);
	else
		n_oct = write(1, "%", 1);
	return (n_oct);
}

int	ft_printf(const char *format, ...)
{
	int		n_oct;
	va_list	args;

	if (ft_check(format) == -1)
		return (-1);
	va_start(args, format);
	n_oct = 0;
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format)
				n_oct += ft_format(args, format);
		}
		else
			n_oct += write(1, format, 1);
		format++;
	}
	va_end(args);
	return (n_oct);
}

/* int main(int ac, char **av)
{
	(void) ac;
	(void) av;
    int count = ft_printf("%x", atoi(av[1]));
	int check =  printf("\n%x", atoi(av[1]));
    printf("\n%d : %d", count, check - 1);
}
 */