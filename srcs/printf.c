/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clvicent <clvicent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 13:55:12 by clvicent          #+#    #+#             */
/*   Updated: 2023/01/09 17:21:02 by clvicent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int ft_strchar(const char *s, char c)
{
	int i;

	i = 0;
	while (s[i] != c && s[i])
		i++;
	return (i);
}

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_printf(const char *s, ...)
{
	int		i;
	int		count;
	va_list	params;

	va_start (params, s);
	i = 0;
	count = 0;
	while (s[i])
	{
		write (1, &s[i], ft_strchar(&s[i], '%'));
		count += ft_strchar(&s[i], '%');
		i += ft_strchar(&s[i], '%');
		if (s[i] == '%' && s[i + 1])
		{
			i++;
			count += ft_convert(s[i], params);
			i++;
		}
	}
	return (count);
}

int	ft_convert(char c, va_list list)
{
	if (c == 'c')
		return (ft_putchar(va_arg(list, int)));
	if (c == '%')
		return (ft_putchar('%'));
	if (c == 'd' || c == 'i')
		return (ft_putnbr(va_arg(list, int)));
	if (c == 'u')
		return (ft_putnbru(va_arg(list, int)));
	if (c == 'X')
		return (ft_putnbr_base(va_arg(list, unsigned int), "0123456789ABCDEF"));
	if (c == 'x')
		return (ft_putnbr_base(va_arg(list, unsigned int), "0123456789abdef"));
	if (c == 'p')
		return (ft_check_ptr(va_arg(list, void *)));
	return (0);
}
