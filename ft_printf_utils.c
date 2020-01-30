/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhamel <fhamel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 11:19:41 by fhamel            #+#    #+#             */
/*   Updated: 2020/01/22 11:20:37 by fhamel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		is_convert(char c)
{
	char	convert_dic[10];
	int		i;

	convert_dic[0] = 'c';
	convert_dic[1] = 's';
	convert_dic[2] = 'p';
	convert_dic[3] = 'd';
	convert_dic[4] = 'i';
	convert_dic[5] = 'u';
	convert_dic[6] = 'x';
	convert_dic[7] = 'X';
	convert_dic[8] = '%';
	convert_dic[9] = '\0';
	i = 0;
	while (convert_dic[i])
	{
		if (c == convert_dic[i])
			return (1);
		i++;
	}
	return (0);
}

int		strlen_convert(char *str)
{
	int	i;

	i = 0;
	while (!is_convert(str[i]))
		i++;
	return (i + 1);
}

char	get_convert(char *str)
{
	int i;

	i = 0;
	while (str[i] && !is_convert(str[i]))
		i++;
	return (str[i]);
}

int		get_len_nb(long long nb, int base)
{
	int			len;
	long long	pow;

	len = 0;
	pow = 1;
	if (nb < 0)
		len++;
	nb = (nb < 0 ? -nb : nb);
	if (nb == 0)
		return (1);
	while (nb / pow)
	{
		len++;
		pow *= base;
	}
	return (len);
}
