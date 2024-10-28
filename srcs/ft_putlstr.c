/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putlstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pengamki <pengamki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 16:29:37 by pengamki          #+#    #+#             */
/*   Updated: 2024/10/28 19:11:54 by pengamki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_putlstr(char *s)
{
	int	len;

	len = 0;
	if (!s)
		return (ft_putlstr("(null)"));
	while (*s)
	{
		if (ft_putlchar(*s++) == -1)
			return (-1);
		len++;
	}
	return (len);
}
