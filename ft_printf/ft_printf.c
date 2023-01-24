/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apereira <apereira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 16:03:31 by apereira          #+#    #+#             */
/*   Updated: 2022/11/28 17:38:48 by apereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *string, ...)
{
	int		i;
	int		count;
	va_list	arg;

	va_start(arg, string);
	i = 0;
	count = 0;
	while (string[i])
	{
		if (string[i] == '%')
		{
			count += ft_check(arg, string[i + 1]);
			i++;
		}
		else
			count += ft_putchar(string[i]);
		i++;
	}
	va_end(arg);
	return (count);
}

int	ft_check(va_list arg, char format)
{
	int	count;

	count = 0;
	if (format == 'c')
		return (ft_putchar(va_arg(arg, int)));
	else if (format == 's')
		return (ft_putstr(va_arg(arg, char *)));
	else if (format == 'p')
		return (ft_print_address(va_arg(arg, unsigned long long), count));
	else if (format == 'd' || format == 'i')
		return (ft_putnbr(va_arg(arg, int), count));
	else if (format == 'u')
		return (ft_putunbr(va_arg(arg, unsigned int), format));
	else if (format == 'x' || format == 'X')
		return (ft_to_hex(va_arg(arg, unsigned int), format));
	return (ft_putchar('%'));
}

int	ft_print_address(unsigned long long address, int count)
{
	count = 0;
	if (address < 1)
		count += write(1, "(nil)", 5);
	else
	{
		count += write(1, "0x", 2);
		ft_putnbr_ptr(address);
		count += ft_nbr_len(address, 16);
	}
	return (count);
}

void	ft_putnbr_ptr(unsigned long long address)
{
	if (address > 15)
	{
		ft_putnbr_ptr(address / 16);
		ft_putnbr_ptr(address % 16);
	}
	else
	{
		if (address < 10)
			ft_putchar(address + '0');
		else
			ft_putchar(address - 10 + 'a');
	}
}

int	ft_nbr_len(unsigned long long address, int div_by)
{
	int	i;

	i = 0;
	if (address == 0)
		return (1);
	while (address != 0)
	{
		i++;
		address = address / div_by;
	}
	return (i);
}
