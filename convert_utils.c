/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhamel <fhamel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 11:21:23 by fhamel            #+#    #+#             */
/*   Updated: 2020/01/22 11:22:03 by fhamel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		max(int a, int b)
{
	if (a >= b)
		return (a);
	return (b);
}

int		min(int a, int b)
{
	if (a <= b)
		return (a);
	return (b);
}

void	nb1_negative(t_flags *flags)
{
	if (flags->nb1 < 0)
	{
		flags->rev = 1;
		flags->nb1 = -flags->nb1;
	}
}

int		print_zeros(int n)
{
	int	ret;
	int	i;

	ret = 0;
	i = 0;
	while (i < n)
	{
		ret += putchar_len('0');
		i++;
	}
	return (ret);
}

int		print_spaces(int n)
{
	int	ret;
	int	i;

	ret = 0;
	i = 0;
	while (i < n)
	{
		ret += putchar_len(' ');
		i++;
	}
	return (ret);
}
