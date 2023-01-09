#ifndef PRINTF_H
# define PRINTF_H

# include <unistd.h>
# include <stdarg.h>

int     ft_convert(char c, va_list params);
int     ft_basec(int i, char *b);
int     ft_putnbr_base(unsigned int n, char *b);
int     ft_putstr(char *s);
int     ft_putnbr(int i);
int     ft_putnbru(unsigned int i);
int     ft_ptr(unsigned long long n, char *b);
int     ft_check_ptr(void *p);
int     ft_putchar(char c);
int     ft_printf(const char *s, ...);
int     ft_convert(char c, va_list list);
int     ft_strlen(char *s);

#endif
