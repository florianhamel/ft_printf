#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <string.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <stdarg.h>

typedef	struct	s_flags
{
	int	percent;
	int	rev;
	int	zero;
	int	nb1;
	int	dot;
	int	nb2;
}				t_flags;

// ft_printf.c
int			run_str(char *str, va_list args);
int			ft_printf(char *str, ...);

// ft_printf_utils.c
int			is_convert(char c);
int			strlen_convert(char *str);
char		get_convert(char *str);
int			get_len_nb(long long nb, int base);

// utils.c
int			ft_strlen(char *str);
int			putchar_len(char c);
int			putstr_len(char *str, int n);
int			putnbr_len(long long nb);
int			puthexa_len(long nb, char c);

// ft_atoi.c
long long	ft_atoi(char *str);

// flags.c
void		init_flags(t_flags *flags);
int			get_nb_convert(char *str, va_list args);
void		fill_flags(char *convert_str, t_flags *flags, va_list args);

// convert.c
int			print_unsigned(t_flags *flags, unsigned int nb);
int			print_convert(t_flags *flags, va_list args, char c);

// convert_print.c
int			print_nb(t_flags *flags, long nb);
int			print_char(t_flags *flags, int c);
int			print_str(t_flags *flags, char *str);
int			print_hexa(t_flags *flags, long long nb, char c);
int			print_ptr(t_flags *flags, void *ptr);

// convert_utils.c
int			max(int a, int b);
int			min(int a, int b);
void		nb1_negative(t_flags *flags);
int			print_zeros(int	n);
int			print_spaces(int n);

#endif