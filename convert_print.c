/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_print.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhamel <fhamel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 11:22:34 by fhamel            #+#    #+#             */
/*   Updated: 2020/01/30 11:28:28 by fhamel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_nb(t_flags *flags, long nb)
{
	int	len_nb;
	int	ret;

	flags->dot = (flags->nb2 < 0 ? 0 : flags->dot);
	nb1_negative(flags);
	len_nb = (!(flags->dot && nb == 0 && flags->nb2 == 0) ?
	get_len_nb(nb, 10) : 0);
	ret = 0;
	if (!flags->rev)
		ret += print_nb_no_rev(flags, nb, len_nb);
	else
	{
		ret += print_zeros(flags->nb2 - len_nb);
		if (!(flags->dot && nb == 0 && flags->nb2 == 0))
			ret += putnbr_len(nb);
		ret += print_spaces(flags->nb1 - max(len_nb, flags->nb2));
	}
	return (ret);
}

int	print_char(t_flags *flags, int c)
{
	int	ret;

	ret = 0;
	nb1_negative(flags);
	if (!flags->rev)
		ret += print_spaces(flags->nb1 - 1);
	ret += putchar_len(c);
	if (flags->rev)
		ret += print_spaces(flags->nb1 - 1);
	return (ret);
}

int	print_str(t_flags *flags, char *str)
{
	int		len_str;
	int		ret;

	ret = 0;
	nb1_negative(flags);
	if (!str)
		str = "(null)";
	if (flags->dot && flags->nb2 >= 0)
		len_str = min(ft_strlen(str), flags->nb2);
	else
		len_str = ft_strlen(str);
	if (!flags->rev)
		ret += print_spaces(flags->nb1 - len_str);
	ret += putstr_len(str, len_str);
	if (flags->rev)
		ret += print_spaces(flags->nb1 - len_str);
	return (ret);
}

int	print_hexa(t_flags *flags, long long nb, char c)
{
	int			len_nb;
	long long	ret;

	flags->dot = (flags->nb2 < 0 ? 0 : flags->dot);
	nb1_negative(flags);
	len_nb = (!(flags->dot && nb == 0 && flags->nb2 == 0) ?
	get_len_nb(nb, 16) : 0);
	ret = 0;
	if (!flags->rev)
		ret += print_hexa_no_rev(flags, nb, len_nb, c);
	else
	{
		ret += print_zeros(flags->nb2 - len_nb);
		if (!(flags->dot && nb == 0 && flags->nb2 <= 0))
			ret += puthexa_len(nb, c);
		ret += print_spaces(flags->nb1 - max(len_nb, flags->nb2));
	}
	return (ret);
}

int	print_ptr(t_flags *flags, void *ptr)
{
	int			len;
	int			ret;

	len = get_len_nb((long long)ptr, 16) + 2;
	ret = 0;
	nb1_negative(flags);
	if (!flags->rev)
		ret += print_spaces(flags->nb1 - len);
	ret += putstr_len("0x", 2);
	ret += puthexa_len((long long)ptr, 'x');
	if (flags->rev)
		ret += print_spaces(flags->nb1 - len);
	return (ret);
}
