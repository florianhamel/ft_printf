/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhamel <fhamel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 11:16:44 by fhamel            #+#    #+#             */
/*   Updated: 2020/01/22 11:16:45 by fhamel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	run_str(char *str, va_list args)
{
	t_flags	*flags;
	int		ret;
	int		i;

	if (!(flags = (t_flags *)malloc(sizeof(t_flags))))
		return (-1);
	ret = 0;
	i = 0;
	while (str[i] != 0)
	{
		if (str[i] == '%')
		{
			i++;
			init_flags(flags);
			fill_flags(&str[i], flags, args);
			ret += print_convert(flags, args, get_convert(&str[i]));
			i += strlen_convert(&str[i]);
		}
		else
			ret += putchar_len(str[i++]);
	}
	free(flags);
	return (ret);
}

int	ft_printf(char *str, ...)
{
	va_list args;
	int		ret;

	if (!str)
		return (-1);
	va_start(args, str);
	ret = run_str(str, args);
	va_end(args);
	return (ret);
}
