/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pengamki <pengamki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 15:24:04 by pengamki          #+#    #+#             */
/*   Updated: 2024/10/28 19:52:52 by pengamki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list	arg;
	int		len;

	len = 0;
	va_start(arg, format);
	len += ft_printf_format(format, &arg);
	va_end(arg);
	return (len);
}

int	ft_printf_format(const char *format, va_list *arg)
{
	int	len;
	int	tmp;

	len = 0;
	if (!format)
		return (-1);
	while (*format)
	{
		if (*format == '%')
		{
			tmp = ft_printf_option(*(format + 1), arg);
			if (tmp == -1)
				return (-1);
			len += tmp;
			format++;
		}
		else
		{
			if (ft_putlchar(*format) == -1)
				return (-1);
			len++;
		}
		format++;
	}
	return (len);
}

int	ft_printf_option(int c, va_list *arg)
{
	if (c == 'c')
		return (ft_putlchar(va_arg(*arg, int)));
	else if (c == 's')
		return (ft_putlstr(va_arg(*arg, char *)));
	else if (c == 'p')
		return (ft_putlptr(va_arg(*arg, unsigned long)));
	else if (c == 'd' || c == 'i')
		return (ft_putlnbr(va_arg(*arg, int)));
	else if (c == 'u')
		return (ft_putlnbrbase(va_arg(*arg, unsigned int), "0123456789", 10));
	else if (c == 'x')
		return (ft_putlnbrbase(va_arg(*arg, unsigned int), "0123456789abcdef",
				16));
	else if (c == 'X')
		return (ft_putlnbrbase(va_arg(*arg, unsigned int), "0123456789ABCDEF",
				16));
	else if (c == '%')
		return (ft_putlchar('%'));
	else
		return (-1);
}
