/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clvicent <clvicent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 17:48:19 by clvicent          #+#    #+#             */
/*   Updated: 2023/01/09 21:24:35 by clvicent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_line(t_fdf *f, int x0, int y0, int x1, int y1)
{
	int	dx;
	int	dy;
	int	er;
	int	sx;
	int	sy;
	
	dx = abs(x1 - x0);
	dy = abs(y1 - y0);
	er = dx + dy;
	if (x0 < x1)
		sx = 1;
	else
		sx = -1;
	if (y0 < y1)
		sy = 1;
	else
		sy = -1;
	while (1)
	{
		if (x0 < f->scx && y0 < f->scy)
			my_mlx_pixel_put(&f->img, x0, y0, 0xFFFFFF);
		if (x0 == x1 && y0 == y1)
			break ;
		if (2 * er >= dy)
		{
			er += dy;
			x0 += sx;
		}
		if (2 * er <= dx)
		{
			er += dx;
			y0 += sy;
		}
	}
	
}