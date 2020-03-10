/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_print2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhamel <fhamel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 11:28:38 by fhamel            #+#    #+#             */
/*   Updated: 2020/03/10 12:31:33 by fhamel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_nb_no_rev(t_flags *flags, long nb, int len_nb)
{
	int	ret;

	ret = 0;
	if (flags->dot)
		ret += print_spaces(flags->nb1 - max(len_nb,
		(nb < 0 ? flags->nb2 + 1 : flags->nb2)));
	if (!flags->dot && !flags->zero)
		ret += print_spaces(flags->nb1 - len_nb);
	if ((nb < 0 && flags->nb2 >= len_nb) ||
	(nb < 0 && flags->zero && !flags->dot && flags->nb1 >= len_nb))
		ret += putchar_len('-');
	if (flags->zero && !flags->dot)
		ret += print_zeros(flags->nb1 - len_nb);
	ret += (nb < 0 ? print_zeros(flags->nb2 - len_nb + 1) :
	print_zeros(flags->nb2 - len_nb));
	if ((nb < 0 && flags->nb2 >= len_nb) ||
	(nb < 0 && flags->zero && !flags->dot && flags->nb1 >= len_nb))
		nb = -nb;
	if (!(flags->dot && nb == 0 && flags->nb2 == 0))
		ret += putnbr_len(nb);
	return (ret);
}

int	print_hexa_no_rev(t_flags *flags, long nb, int len_nb, char c)
{
	int ret;

	ret = 0;
	if (flags->dot)
		ret += print_spaces(flags->nb1 - max(len_nb, flags->nb2));
	else if (!flags->dot && !flags->zero)
		ret += print_spaces(flags->nb1 - len_nb);
	ret += print_zeros(flags->nb2 - len_nb);
	if (flags->zero && !flags->dot)
		ret += print_zeros(flags->nb1 - len_nb);
	if (!(flags->dot && nb == 0 && flags->nb2 == 0))
		ret += puthexa_len(nb, c);
	return (ret);
}

int	print_percent(t_flags *flags)
{
	int	ret;

	ret = 0;
	if (!flags->nb1)
		return (putchar_len('%'));
	if (!flags->rev)
	{
		if (flags->zero)
			ret += print_zeros(flags->nb1 - 1);
		else
			ret += print_spaces(flags->nb1 - 1);
		ret += putchar_len('%');
	}
	else
	{
		ret += putchar_len('%');
		ret += print_spaces(flags->nb1 - 1);
	}
	return (ret);
}
