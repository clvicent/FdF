/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_tools.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clvicent <clvicent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 18:29:21 by clvicent          #+#    #+#             */
/*   Updated: 2023/02/22 18:41:48 by clvicent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	get_pos(int x, int y, t_fdf *f)
{
	f->m.index_y = (y - f->m.start_y) / f->m.size_p_y;
	f->m.index_x = (x - f->m.start_x) / f->m.size_p_x;
	f->m.c_alt = f->tab[f->m.index_y][f->m.index_x];
}

int	check_tab(t_fdf *f)
{
	int	y;
	int	x;

	y = 0;
	while (y < f->m.size_y)
	{
		x = 0;
		while (x < f->m.size_x)
		{
			if (f->tab[y][x] > 1000000 || f->tab[y][x] < -1000000)
				return (-1);
			x++;
		}
		y++;
	}
	return (0);
}

void	check_file(t_fdf *f)
{
	if (f->m.size_y == 0)
		shut_fdf(f, "empty file\n", 0);
	if (f->fd < 0 || f->fd > 1024)
		shut_fdf(f, "", 0);
}
