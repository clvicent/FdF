/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing_tools.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clvicent <clvicent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 14:22:53 by clvicent          #+#    #+#             */
/*   Updated: 2023/02/13 20:15:45 by clvicent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_grid(int x, int y, t_fdf *f)
{
	get_pos(x, y, f);
	if (f->m.index_x + 1 < f->m.size_x)
	{
		get_coord(f->m.index_x + 1, f->m.index_y, f);
		bresenham(f);
	}	
	if (f->m.index_y + 1 < f->m.size_y)
	{
		get_coord(f->m.index_x, f->m.index_y + 1, f);
		bresenham(f);
	}
}

void	get_coord(int x, int y, t_fdf *f)
{
	f->m.next_alt = f->tab[y][x];
	f->l.x0 = f->l.true_x + ((f->m.index_x - f->m.index_y) * f->l.half_width);
	f->l.y0 = f->l.true_y + ((f->m.index_x + f->m.index_y) * f->l.half_height);
	f->l.y0 -= f->l.zoom * f->m.c_alt;
	f->l.x1 = f->l.true_x + ((x - y) * f->l.half_width);
	f->l.y1 = f->l.true_y + ((x + y) * f->l.half_height);
	f->l.y1 -= f->l.zoom * f->m.next_alt;
}

void	bresenham(t_fdf *f)
{
	if (f->l.x0 < f->l.x1)
		f->l.sx = 1;
	else
		f->l.sx = -1;
	if (f->l.y0 < f->l.y1)
		f->l.sy = 1;
	else
		f->l.sy = -1;
	f->l.dx = ft_abs(f->l.x1 - f->l.x0);
	f->l.dy = -ft_abs(f->l.y1 - f->l.y0);
	if (f->l.x0 < f->l.x1)
		f->l.sx = 1;
	else
		f->l.sx = -1;
	if (f->l.y0 < f->l.y1)
		f->l.sy = 1;
	else
		f->l.sy = -1;
	f->l.seg_len = get_len(f);
	draw_line(f, &f->l);
}

void	draw_line(t_fdf *f, t_line *l)
{
	int	er;
	
	er = l->dx + l->dy;
	while (1)
	{
		if (l->x0 < f->scx && l->y0 < f->scy)
			set_pix(f, l->x0, l->y0);
		if (l->x0 == l->x1 && l->y0 == l->y1)
			break ;
		if (2 * er >= l->dy)
		{
			if (l->x0 == l->x1)
				break ;
			er += l->dy;
			l->x0 += l->sx;
		}
		if (2 * er <= l->dx)
		{
			if (l->y0 == l->y1)
				break ;
			er += l->dx;
			l->y0 += l->sy;
		}
	}
}

int		get_len(t_fdf *f)
{
	float	a;
	float	b;
	float	c;

	if(f->l.x1 > f->l.x0)
		a = f->l.x1 - f->l.x0;
	else
		a = f->l.x0 - f->l.x1;
	if(f->l.y1 * f->l.zoom > f->l.y0 * f->l.zoom)
		b = f->l.y1 * f->l.zoom - f->l.y0 * f->l.zoom;
	else
		b = f->l.y0 * f->l.zoom - f->l.y1 * f->l.zoom;
	c = a * a + b * b;
	c = sqrt((double)c);
	return ((int)c);
}