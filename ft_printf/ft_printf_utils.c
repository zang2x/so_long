/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcruz-me <hcruz-me@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 17:53:20 by marvin            #+#    #+#             */
/*   Updated: 2024/11/19 15:08:59 by hcruz-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h" 

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putnbr(int n)
{
	int		count;
	char	digit;

	count = 0;
	if (n == -2147483648)
	{
		count += write(1, "-2147483648", 11);
		return (count);
	}
	if (n < 0)
	{
		count += write(1, "-", 1);
		n = -n;
	}
	if (n >= 10)
		count += ft_putnbr(n / 10);
	digit = '0' + (n % 10);
	count += write(1, &digit, 1);
	return (count);
}

int	ft_putstr(char *str)
{
	int	len;

	len = 0;
	if (!str)
		return (write(1, "(null)", 6));
	while (str[len])
	{
		write(1, &str[len], 1);
		len++;
	}
	return (len);
}

int	ft_ptr(void *ptr)
{
	unsigned long	addr;
	char			*hex;
	char			buffer[16];
	int				i;
	int				count;

	addr = (unsigned long)ptr;
	hex = "0123456789abcdef";
	i = 0;
	count = 0;
	if (!ptr)
		return (write(1, "(nil)", 5));
	count += write(1, "0x", 2);
	if (addr == 0)
		return (count + write(1, "0", 1));
	while (addr > 0)
	{
		buffer[i++] = hex[addr % 16];
		addr /= 16;
	}
	while (i-- > 0)
		count += write(1, &buffer[i], 1);
	return (count);
}

int	ft_unsigned_int(unsigned int n)
{
	char	c;
	int		count;

	count = 0;
	if (n >= 10)
		count += ft_unsigned_int(n / 10);
	c = (n % 10) + '0';
	count += ft_putchar(c);
	return (count);
}
