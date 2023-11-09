/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochetrit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 16:10:17 by ochetrit          #+#    #+#             */
/*   Updated: 2023/11/09 09:39:20 by ochetrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "printf.h"

int	ft_printf(const char *format, ...)
{
	int			len;
	va_list	args;

	if (ft_check(format) == -1)
		return (-1);
	va_start(args, format);
	len = 0;
	while (*format)
	{
		if (*format == '%' && *(format + 1))
		{
			if (ft_strchr("sp", *(++format)))
				len += ft_write_ptr(*format, va_arg(args, void *));
			else if (*format == '%')
				write(1, "%", 1);
			else
				len += ft_write_int(*format, va_arg(args, long));
		}
		else
			len += write(1, format, 1);
		format++;
	}
	va_end(args);
	return (len);
}

int	ft_write_ptr(char type, void *ptr)
{
	unsigned long int	valptr;

	if (type == 's')
	{
		return (ft_putstr((char *)ptr));
	}
	valptr = (long) ptr;
	return (ft_puthex(valptr));
}

int	ft_write_int(char type, long nb)
{
	if (type == 'c')
		return (write(1, &nb, 1));
	else if (ft_strchr("diu", type))
		return (ft_putnbr(nb));
	else if (type == 'x')
		return (ft_puthex(nb));
	else
		return (ft_puthexbig(nb));
}

/*int main()
{
    int count = ft_printf("%c\n%x\n%s\n", 87, 1500, "florian");
    int check = printf("%c\n%x\n%s\n", 87, 1500, "florian");
    printf("%d : %d", count, check);
}*/
