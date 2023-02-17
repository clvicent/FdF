/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_tools.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clvicent <clvicent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 17:25:59 by clvicent          #+#    #+#             */
/*   Updated: 2023/02/17 12:58:44 by clvicent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	get_zoom(t_fdf *f)
{
	int	zoom;
	int	delta;

	delta = f->m.max_alt - f->m.min_alt;
	zoom = 16;
	while (f->l.true_y - (zoom * f->m.max_alt) < 0
		|| (f->scy - f->l.true_y) - (zoom * f->m.min_alt) > f->scy)
	{
		if (delta > 200)
			zoom = 1;
		if (zoom == 1)
			break ;
		zoom--;
	}
	return (zoom);
}

void	mlx_pp(t_data *img, int x, int y, int color)
{
	char	*dst;

	dst = img->ad + (y * img->l + x * (img->bpp / 8));
	*(unsigned int *) dst = color;
}

void	set_pix(t_fdf *f, int x, int y)
{
	int	color;

	if (get_len(f) == f->l.seg_len)
		f->m.flag = 0;
	color = color_maker(f);
	if (f->m.c_alt > f->m.alt_0 && f->m.flag != 1)
		mlx_pp(&f->img, x, y, get_rgb(255, spl(color, 1), spl(color, 2)));
	if (f->m.c_alt < f->m.alt_0 && f->m.flag != 1)
		mlx_pp(&f->img, x, y, get_rgb(spl(color, 2), spl(color, 1), 255));
	if (f->m.c_alt > f->m.alt_0 && f->m.flag == 1)
		mlx_pp(&f->img, x, y, get_rgb(spl(color, 2), spl(color, 1), 255));
	if (f->m.c_alt < f->m.alt_0 && f->m.flag == 1)
		mlx_pp(&f->img, x, y, get_rgb(255, spl(color, 1), spl(color, 2)));
	if (f->m.c_alt == f->m.alt_0)
		mlx_pp(&f->img, x, y, shade_zero(f, color));
}

int	get_rgb(int r, int g, int b)
{
	int	rgb;

	rgb = r;
	rgb = (rgb << 8) + g;
	rgb = (rgb << 8) + b;
	return (rgb);
}
