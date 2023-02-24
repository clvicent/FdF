/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _is_in_range.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clvicent <clvicent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 14:31:59 by clvicent          #+#    #+#             */
/*   Updated: 2023/02/23 15:19:14 by clvicent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	is_in_range(char *s, char start, char end)
{
	int	i;

	i = 0;
	if (!s || !start || !end)
		return (-1);
	while (s[i])
	{
		if ((s[i] < start || s[i] > end))
			return (0);
		i++;
	}
	return (1);
}
