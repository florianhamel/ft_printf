#include  "ft_printf.h"

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
	return (putchar_len('%'));
}