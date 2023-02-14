/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clvicent <clvicent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 19:26:43 by clvicent          #+#    #+#             */
/*   Updated: 2023/02/14 13:12:19 by clvicent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	color_maker(t_fdf *f)
{
	int		prev;
	int		current;
	float	ratio;

	ratio = get_len(f);
	prev = prev_color(f);
	if (ratio == f->l.seg_len)
		return (prev * 2);
	ratio /= f->l.seg_len;
	ratio = (float)1 - ratio;
	current = final_color(ratio, f);
	return (current * 2);
}

int	final_color(float ratio, t_fdf *f)
{
	int		prev;
	int		next;

	prev = prev_color(f);
	f->m.flag = 0;
	next = next_color(f);
	if ((f->m.c_alt > f->m.alt_0 && f->m.next_alt < f->m.alt_0)
		|| (f->m.c_alt < f->m.alt_0 && f->m.next_alt > f->m.alt_0))
		return (ex_shader((f->l.seg_len - get_len(f)), next, f));
	else
		return (reg_shader(prev, next, ratio));
	return (-1);
}

int	next_color(t_fdf *f)
{
	float	next;

	next = 255;
	if (f->m.next_alt > f->m.alt_0)
		next -= next / (float)(f->m.max_alt / f->m.next_alt);
	if (f->m.next_alt < f->m.alt_0)
		next -= next / (float)(f->m.min_alt / f->m.next_alt);
	if (f->m.next_alt == f->m.alt_0)
		return ((int)next);
	return ((int)next);
}
