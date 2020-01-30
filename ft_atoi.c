/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhamel <fhamel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 11:16:08 by fhamel            #+#    #+#             */
/*   Updated: 2020/01/22 11:16:09 by fhamel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

long long	ft_atoi(char *str)
{
	long long	nb;
	int			sign;
	int			i;

	nb = 0;
	sign = 1;
	i = 0;
	while ((9 <= str[i] && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		sign = (str[i] == '-' ? -1 : 1);
		i++;
	}
	while ('0' <= str[i] && str[i] <= '9')
	{
		nb = (10 * nb) + (str[i] - '0');
		i++;
	}
	return (sign * nb);
}
