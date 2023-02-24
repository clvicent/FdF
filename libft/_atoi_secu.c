/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _atoi_secu.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clvicent <clvicent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 13:59:20 by clvicent          #+#    #+#             */
/*   Updated: 2023/02/23 15:17:10 by clvicent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	*atoi_secu(const char *str, int *nb)
{
	int			i;
	int			neg;
	long int	n;

	i = 0;
	neg = 1;
	n = 0;
	while ((str[i] <= 13 && str[i] >= 9) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			neg = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
		n = n * 10 + (str[i++] - '0');
	n *= neg;
	if (n > 2147483647 || n < -2147483648)
		return (NULL);
	*nb = (int)n;
	return (nb);
}
