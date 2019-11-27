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

int		print_zeros(int	n)
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