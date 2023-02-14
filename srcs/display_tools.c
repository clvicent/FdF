/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_tools.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clvicent <clvicent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 17:25:59 by clvicent          #+#    #+#             */
/*   Updated: 2023/02/14 19:00:02 by clvicent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		get_zoom(t_fdf *f)
{
	int i;

	i = 200;
	while (i > 1)
	{
		if (f->l.true_y - (i * f->m.max_alt) < 0 ||
			(f->scy - f->l.true_y) - (i * f->m.min_alt) > f->scy)
			i--;
		else
			return (i);
	}
	return (i);
}

void	my_mlx_pixel_put(t_data *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->length + x * (img->bpp / 8));
	*(unsigned int *) dst = color;
}

void	set_pix(t_fdf *f, int x, int y)
{
	int color;

	if (get_len(f) == f->l.seg_len)
		f->m.flag = 0;
	color = color_maker(f);
	if (f->m.c_alt > f->m.alt_0 && f->m.flag != 1)
		my_mlx_pixel_put(&f->img, x, y, get_rgb(255, splitter(color, 1), splitter(color, 2)));
	if (f->m.c_alt < f->m.alt_0 && f->m.flag != 1)
		my_mlx_pixel_put(&f->img, x, y, get_rgb(splitter(color, 2), splitter(color, 1), 255));
	if (f->m.c_alt > f->m.alt_0 && f->m.flag == 1)
		my_mlx_pixel_put(&f->img, x, y, get_rgb(splitter(color, 2), splitter(color, 1), 255));
	if (f->m.c_alt < f->m.alt_0 && f->m.flag == 1)
		my_mlx_pixel_put(&f->img, x, y, get_rgb(255, splitter(color, 1), splitter(color, 2)));
	if (f->m.c_alt == f->m.alt_0)
		my_mlx_pixel_put(&f->img, x, y, shade_zero(f, color));
}

int	get_rgb(int r, int g, int b)
{
	int	rgb;

	rgb = r;
	rgb = (rgb << 8) + g;
	rgb = (rgb << 8) + b;
	return (rgb);
}
