/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putlptr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pengamki <pengamki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 18:53:31 by pengamki          #+#    #+#             */
/*   Updated: 2024/10/28 19:09:45 by pengamki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_putlptr(unsigned long ptr)
{
	int	len;

	len = 0;
	if (!ptr)
	{
		return (ft_putlstr("(nil)"));
	}
	len += ft_putlstr("0x");
	len += ft_putllnbrbase(ptr, "0123456789abcdef", 16);
	if (len < 0)
		return (-1);
	return (len);
}

int	ft_putllnbrbase(unsigned long nbr, const char *sheet, unsigned int base)
{
	int	len;

	len = 0;
	if (nbr >= base)
	{
		len += ft_putllnbrbase(nbr / base, sheet, base);
		len += ft_putllnbrbase(nbr % base, sheet, base);
	}
	else
	{
		len += ft_putlchar(sheet[nbr]);
	}
	if (len < 0)
		return (-1);
	return (len);
}
