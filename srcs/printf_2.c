/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clvicent <clvicent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 18:25:04 by clvicent          #+#    #+#             */
/*   Updated: 2023/01/09 17:23:37 by clvicent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	ft_ptr(unsigned long long n, char *b) // p
{
	unsigned long long	s;
	int                 i;

	s = (unsigned long long)ft_strlen(b);
	i = 0;
	if (n >= s)
	{
		ft_ptr((n / s), b);
		ft_putchar(b[n % s]);
		i++;
	}
	else
	{
		ft_putchar(b[n % s]);
		i++;
	}
	return (i);
}

int	ft_check_ptr(void *p)
{
	if (!p)
	{
		write(1, "0x0", 3);
		return (3);
	}
	write(1, "0x", 2);
	return(2 + ft_ptr((unsigned long long)p, "0123456789abcdef"));
}

// int	ft_strlen(char *s)
// {
// 	int i;

// 	i = 0;
// 	while (s[i])
// 		i++;
// 	return (i);
// }
// #include <stdio.h>

// int    main(int ac, char **av)
// {
//     (void)ac;
//     (void)av;
//     char            *s = "ekip";
//     void            *p = &s;
//     int                d = -2147483648;
//     char            c = 'O';
//     int                x = 21;
//     int                X = 42;
//     int                o = 789;
//     unsigned int    u = 2147483699;
//     int    i = ft_printf("%p %% %c %s %d %i %u %x %X\n", p, c, s, d, o, u, x, X);
//     int    j = printf("%p %% %c %s %d %i %u %x %X\n", p, c, s, d, o, u, x, X);
//     printf("%d\n", i);
//     printf("%d\n", j);

// }