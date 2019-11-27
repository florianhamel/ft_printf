#include "ft_printf.h"

void	init_flags(t_flags *flags)
{
	flags->percent = 0;
	flags->rev = 0;
	flags->zero = 0;
	flags->nb1 = 0;
	flags->dot = 0;
	flags->nb2 = 0;
}

int		get_nb_convert(char *str, va_list args)
{
	int i;

	i = 0;
	if ('0' <= str[i] && str[i] <= '9')
		return (ft_atoi(&str[i]));
	else if (str[i] == '*')
		return (va_arg(args, int));
	return (0);
}

void	fill_flags(char *str, t_flags *flags, va_list args)
{
	int i;

	i = 0;
	if (str[i] == '%')
	{
		flags->percent = 1;
		return ;
	}
	if (str[i] == '-' || str[i] == '0')
	{
		flags->rev = (str[i] == '-' ? 1 : 0);
		flags->zero = (str[i] == '0' ? 1 : 0);
		i++;
	}
	flags->nb1 = get_nb_convert(&str[i], args);
	while (!is_convert(str[i]) && str[i] != '.')
		i++;
	if (str[i] == '.')
	{
		flags->dot = 1;
		i++;
		flags->nb2 = get_nb_convert(&str[i], args);
	}
}