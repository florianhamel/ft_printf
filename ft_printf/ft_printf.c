/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: florianhamel <florianhamel@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 15:03:34 by florianhame       #+#    #+#             */
/*   Updated: 2019/11/27 14:57:21 by florianhame      ###   ########.fr       */
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
