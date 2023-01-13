/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clvicent <clvicent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 17:48:19 by clvicent          #+#    #+#             */
/*   Updated: 2023/01/13 18:45:39 by clvicent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	bresenham(t_fdf *f, int x, int y)
{
	get_start_end(f, &f->l, x, y);
	// printf("l->x0 = %d\n", f->l.x0);
	// LOG
	// printf("l->y0 = %d\n", f->l.y0);
	// printf("l->x1 = %d\n", f->l.x1);
	// printf("l->y1 = %d\n", f->l.y1);
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
	draw_line(f, &f->l);
}

void	draw_line(t_fdf *f, t_line *l)
{
	int	er;
	
	er = l->dx + l->dy;
	// printf("l->x0 = %d\n", l->x0);
	// printf("l->y0 = %d\n", l->y0);
	// printf("l->x1 = %d\n", l->x1);
	// printf("l->y1 = %d\n", l->y1);
	while (1)
	{
		if (l->x0 < f->scx && l->y0 < f->scy)
			my_mlx_pixel_put(&f->img, l->x0, l->y0, 0xFFFFFF);
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

void	get_start_end(t_fdf *f, t_line *l, int x, int y)
{
	l->x0 = f->m.start_x / 2;
	l->y0 = f->scy / 2;
	l->x1 = f->scx / 2;
	l->y1 = f->m.start_y * 2;
	if (is_in_grid(x, y, f) == 1)
	{
		if (l->flag == 0)
			l->flag = 1;
		else
			l->y1 = f->scy - l->y1;
	}
	l->x0 += get_xdest(x, y, f);
	l->x1 += get_xdest(x, y, f);
	if (is_in_grid(x, y, f) == 2)
	{
		l->y0 -= get_ydest(x, y, f);
		l->y1 += get_ydest(x, y, f);
	}
	if (is_in_git add grid(x, y, f) == 3)
	{
		// printf("l->y0 = %d\n", l->y0);
		// printf("l->y1 = %d\n", l->y1);
		l->y0 += get_ydest(x, y, f);
		l->y1 -= get_ydest(x, y, f);
		// printf("l->y0 = %d\n", l->y0);
		// printf("l->y1 = %d\n", l->y1);
	}
	// printf("l->x0 = %d\n", l->x0);
	// printf("l->y0 = %d\n", l->y0);
	// printf("l->x1 = %d\n", l->x1);
	// printf("l->y1 = %d\n", l->y1);
}

int		get_xdest(int x, int y, t_fdf *f)
{
	float	res;
	float	n_col;
	
	(void)y;
	n_col = ((x - f->m.start_x) / f->m.size_p_x) + 1;
	res = (float)(f->scx / 2 - f->m.start_x / 2);
	// printf("n_col = %f\n", n_col);
	// printf("res = %f\n", res);
	// printf("true_res = %f\n", (res * (n_col / (f->m.size_x))));
	return ((int)(res * (n_col / (f->m.size_x))));
}

int		get_ydest(int x, int y, t_fdf *f)
{
	float	res;
	float	n_col;
	
	if (is_in_grid(x, y, f) == 2)
	{
		n_col = ((y - f->m.start_y) / f->m.size_p_y);
		res = (float)(f->scy / 2 - f->m.start_y * 2);
		res *= (n_col / (f->m.size_y));
	}
	if (is_in_grid(x, y, f) == 3)
	{
		n_col = ((x - f->m.start_x) / f->m.size_p_x);
		res = (float)(f->scy / 2 - f->m.start_x * 2);
		res *= (n_col / (f->m.size_x));
	}
	// printf("n_col = %f\n", n_col);
	// printf("res = %f\n", res);
	// printf("true_res = %f\n", (res * (n_col / (f->m.size_y))));
	return ((int)res);
}