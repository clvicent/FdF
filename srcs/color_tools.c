/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clvicent <clvicent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 20:17:19 by clvicent          #+#    #+#             */
/*   Updated: 2023/02/14 13:13:01 by clvicent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	shade_zero(t_fdf *f, int color)
{
	if (f->m.next_alt > f->m.alt_0)
		return (get_rgb(255, splitter(color, 1), splitter(color, 2)));
	if (f->m.next_alt < f->m.alt_0)
		return (get_rgb(splitter(color, 2), splitter(color, 1), 255));
	return (get_rgb(255, 255, 255));
}

int	splitter(int color, int flag)
{
	if (color >= 510)
		return (255);
	if (flag == 1)
	{
		if (color <= 255)
			return (color);
		else
			return (255);
	}
	if (flag == 2)
	{
		if (color <= 255)
			return (0);
		else
			return (color - 255);
	}
	return (255);
}

int	reg_shader(int prev, int next, float ratio)
{
	int	res;

	res = prev;
	if (prev > next)
		res -= (float)abs(prev - next) * ratio;
	if (prev < next)
		res += (float)abs(next - prev) * ratio;
	return (res);
}

int	ex_shader(int len, int next, t_fdf *f)
{
	float	range;
	float	loc;

	if (f->m.c_alt > f->m.next_alt)
	{
		range = -f->m.next_alt;
		range += f->m.c_alt;
		loc = ((1 - (-f->m.next_alt / range)) * (float)f->l.seg_len);
	}
	else
	{
		range = -f->m.c_alt;
		range += f->m.next_alt;
		loc = ((-f->m.c_alt / range) * (float)f->l.seg_len);
	}
	if (len < (int)loc)
		return (reg_shader(prev_color(f), 255, ((float)len / loc)));
	else if (len == (int)loc)
		return (255);
	if (len > (int)loc)
	{
		f->m.flag = 1;
		return (reg_shader(255, next, ((len - loc) / (f->l.seg_len - loc))));
	}
	return (-1);
}

int	prev_color(t_fdf *f)
{
	float	x;

	x = 255;
	if (f->m.c_alt > f->m.alt_0)
		x -= x / (float)(f->m.max_alt / f->m.c_alt);
	if (f->m.c_alt < f->m.alt_0)
		x -= x / (float)(f->m.min_alt / f->m.c_alt);
	if (f->m.c_alt == f->m.alt_0)
		return ((int)x);
	return ((int)x);
}
