/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _free_tab.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clvicent <clvicent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 17:30:18 by clvicent          #+#    #+#             */
/*   Updated: 2023/01/30 17:32:56 by clvicent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	free_tab(int **tab, const int ylen)
{
	int	y;

	if (!tab)
		return ;
	y = 0;
	while (y < ylen)
	{
		free(tab[y]);
		y++;
	}
	free(tab);
	tab = NULL;
}
