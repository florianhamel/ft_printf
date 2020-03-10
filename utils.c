/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhamel <fhamel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 11:14:48 by fhamel            #+#    #+#             */
/*   Updated: 2020/03/10 12:32:31 by fhamel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	putchar_len(char c)
{
	write(1, &c, 1);
	return (1);
}

int	putstr_len(char *str, int n)
{
	int	i;

	i = 0;
	if (!str)
	{
		putstr_len("(null)", 6);
		return (6);
	}
	while (str[i] && i < n)
		putchar_len(str[i++]);
	return (i);
}

int	putnbr_len(long long nb)
{
	long long	pow_ten;
	int			ret;

	ret = 0;
	if (nb < 0)
	{
		ret += putchar_len('-');
		nb = -nb;
	}
	pow_ten = 1;
	while (nb / pow_ten)
		pow_ten *= 10;
	pow_ten = (nb == 0 ? pow_ten : pow_ten / 10);
	while (pow_ten > 0)
	{
		ret += putchar_len(nb / pow_ten + '0');
		nb -= nb / pow_ten * pow_ten;
		pow_ten /= 10;
	}
	return (ret);
}

int	puthexa_len(unsigned long nb, char c)
{
	char		*base;
	long long	pow_16;
	int			ret;

	base = (c == 'x' ? "0123456789abcdef" : "0123456789ABCDEF");
	pow_16 = 1;
	ret = 0;
	while (nb / pow_16)
		pow_16 *= 16;
	pow_16 = (nb == 0 ? pow_16 : pow_16 / 16);
	while (pow_16)
	{
		ret += putchar_len(base[nb / pow_16]);
		nb -= (nb / pow_16) * pow_16;
		pow_16 /= 16;
	}
	return (ret);
}
