/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clvicent <clvicent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 15:46:15 by clvicent          #+#    #+#             */
/*   Updated: 2023/04/04 15:48:17 by clvicent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	init_env(t_fdf *f)
{
	f->m.size_x = 0;
	ft_bzero(&f->m, sizeof(t_math));
	ft_bzero(&f->l, sizeof(t_line));
	f->scx = SCX;
	f->scy = SCY;
}

void	init_mlx(t_fdf *f)
{
	f->mlx = mlx_init();
	f->win = mlx_new_window(f->mlx, f->scx, f->scy, "fdf");
	init_img(f);
}

void	init_img(t_fdf *f)
{
	t_data	*img;

	img = &f->img;
	img->i_p = mlx_new_image(f->mlx, f->scx, f->scy);
	img->ad = mlx_get_data_addr(img->i_p, &img->bpp, &img->l, &img->end);
}