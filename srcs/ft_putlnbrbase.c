/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putlnbrbase.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pengamki <pengamki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 16:44:15 by pengamki          #+#    #+#             */
/*   Updated: 2024/10/28 19:10:47 by pengamki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_putlnbrbase(unsigned int nbr, const char *sheet, unsigned int base)
{
	int	len;

	len = 0;
	if (nbr >= base)
	{
		len += ft_putlnbrbase(nbr / base, sheet, base);
		len += ft_putlnbrbase(nbr % base, sheet, base);
	}
	else
	{
		len += ft_putlchar(sheet[nbr]);
	}
	if (len < 0)
		return (-1);
	return (len);
}
