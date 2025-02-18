/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcruz-me <hcruz-me@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 11:40:53 by marvin            #+#    #+#             */
/*   Updated: 2024/11/19 15:09:53 by hcruz-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_hexa(unsigned int n, const char *base)
{
	int	i;

	i = 0;
	if (n >= 16)
		i += ft_hexa(n / 16, base);
	i += write(1, &base[n % 16], 1);
	return (i);
}

int	variables(char specifier, va_list args)
{
	if (specifier == 'c')
		return (ft_putchar(va_arg(args, int)));
	else if (specifier == 's')
		return (ft_putstr(va_arg(args, char *)));
	else if (specifier == 'd' || specifier == 'i')
		return (ft_putnbr(va_arg(args, int)));
	else if (specifier == 'p')
		return (ft_ptr(va_arg(args, void *)));
	else if (specifier == 'u')
		return (ft_unsigned_int(va_arg(args, unsigned int)));
	else if (specifier == 'x')
		return (ft_hexa(va_arg(args, unsigned int), "0123456789abcdef"));
	else if (specifier == 'X')
		return (ft_hexa(va_arg(args, unsigned int), "0123456789ABCDEF"));
	else if (specifier == '%')
		return (ft_putchar('%'));
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		total;

	total = 0;
	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			total += variables(*format, args);
		}
		else
			total += ft_putchar(*format);
		format++;
	}
	va_end(args);
	return (total);
}
