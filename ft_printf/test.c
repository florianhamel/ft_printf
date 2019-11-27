#include "ft_printf.h"

int	test(char *str, ...)
{
	va_list args;
	t_flags	*flags;

	flags = malloc(sizeof(t_flags));
	va_start(args, str);
	init_flags(flags);
	fill_flags(str, flags, args);
	// printf("perc %d\n", flags->percent);
	// printf("rev %d\n", flags->rev);
	// printf("zero %d\n", flags->zero);
	// printf("nb1 %d\n", flags->nb1);
	// printf("dot %d\n", flags->dot);
	// printf("nb2 %d\n", flags->nb2);
	int ret = print_hexa(flags, va_arg(args, long long), 'x');
	write(1, "\n", 1);
	free(flags);
	va_end(args);
	return (ret);
}

int	main()
{
	int	ret1 = test("0*x", 20, 42);
	int	ret2 = printf("%0*x\n", 20, 42);
	// printf("ret1: %d, ret2: %d\n", ret1, ret2);
	return (0);
}