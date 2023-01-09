/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clvicent <clvicent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 12:59:26 by clvicent          #+#    #+#             */
/*   Updated: 2023/01/09 17:21:42 by clvicent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	ft_basec(int i, char *b)
{
	int				j;
	unsigned int	n;
	unsigned int	s;

	s = (unsigned int)ft_strlen(b);
	j = 0;
	if (i < 0)
	{
		n = -i;
		j++;
	}
	else
		n = i;
	while (n >= s)
	{
		n /= s;
		j++;
	}
	j++;
	return (j);
}

int	ft_putnbr_base(unsigned int n, char *b) // x X
{
	unsigned int	s;
	int				i;

	s = (unsigned int)ft_strlen(b);
	i = 0;
	if (n >= s)
	{
		ft_putnbr_base((n / s), b);
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

int	ft_putstr(char *s) // s
{
	int i;

	i = 0;
	while (s[i])
	{
		ft_putchar(s[i]);
		i++;
	}
	return (i - 1);
}

int	ft_putnbr(int i) // i d
{
	unsigned int	n;
	int				c;

	c = 0;
	if (i < 0)
	{
		n = -i;
		ft_putchar('-');
		c++;
	}
	else
		n = i;
	if (n >= 10)
	{
		ft_putnbr(n / 10);
		ft_putchar(n % 10);
		c++;
	}
	else
		ft_putchar(n);
	c++;
	return (c);
}

int	ft_putnbru(unsigned int i) // u
{
	int				c;

	c = 0;
	if (i >= 10)
	{
		ft_putnbr(i / 10);
		ft_putchar(i % 10);
		c++;
	}
	else
		ft_putchar(i);
	c++;
	return (c);
}
