/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apereira <apereira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 17:05:33 by apereira          #+#    #+#             */
/*   Updated: 2022/11/28 17:07:02 by apereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(int c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *s)
{
	size_t	i;

	if (s == NULL)
		return (ft_putstr("(null)"));
	i = 0;
	while (s[i])
		write(1, &s[i++], 1);
	return (i);
}

int	ft_to_hex(unsigned int nbr, char c)
{
	if (nbr > 15)
	{
		ft_to_hex(nbr / 16, c);
		ft_to_hex(nbr % 16, c);
	}
	else
	{
		if (nbr < 10)
			ft_putchar(nbr + '0');
		else
		{
			if (c == 'x')
				ft_putchar(nbr - 10 + 'a');
			else
				ft_putchar(nbr - 10 + 'A');
		}
	}
	return (ft_nbr_len(nbr, 16));
}

int	ft_putnbr(int n, int count)
{
	int			i;

	if (n < 0)
	{
		if (n == -2147483648)
			return (ft_putstr("-2147483648"));
		count += write(1, "-", 1);
		n *= -1;
	}
	i = n;
	if (i > 9)
	{
		ft_putnbr(i / 10, count);
		i %= 10;
	}
	ft_putchar(i + '0');
	return (count += ft_nbr_len(n, 10));
}

int	ft_putunbr(unsigned int n, int count)
{
	size_t			i;

	i = n;
	if (i > 9)
	{
		ft_putunbr(i / 10, count++);
		i %= 10;
	}
	ft_putchar(i + '0');
	count = ft_nbr_len(n, 10);
	return (count);
}
