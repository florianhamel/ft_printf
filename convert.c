/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhamel <fhamel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 11:17:13 by fhamel            #+#    #+#             */
/*   Updated: 2020/03/10 12:31:14 by fhamel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_convert(t_flags *flags, va_list args, char c)
{
	if (c == 'd' || c == 'i')
		return (print_nb(flags, va_arg(args, int)));
	if (c == 'u')
		return (print_nb(flags, va_arg(args, unsigned int)));
	if (c == 'c')
		return (print_char(flags, va_arg(args, int)));
	if (c == 's')
		return (print_str(flags, va_arg(args, char*)));
	if (c == 'x' || c == 'X')
		return (print_hexa(flags, va_arg(args, long long), c));
	if (c == 'p')
		return (print_ptr(flags, va_arg(args, void*)));
	return (print_percent(flags));
}
