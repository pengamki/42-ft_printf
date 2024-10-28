/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pengamki <pengamki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 11:24:40 by pengamki          #+#    #+#             */
/*   Updated: 2024/10/28 19:08:00 by pengamki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

// Main functions
int	ft_printf(const char *format, ...);
int	ft_printf_format(const char *format, va_list *arg);
int	ft_printf_option(int c, va_list *arg);

// Helper functions
int	ft_putlchar(int c);
int	ft_putlstr(char *s);
int	ft_putlptr(unsigned long ptr);
int	ft_putlnbr(int nbr);
int	ft_putlnbrbase(unsigned int nbr, const char *sheet, unsigned int base);
int	ft_putllnbrbase(unsigned long nbr, const char *sheet, unsigned int base);

#endif
