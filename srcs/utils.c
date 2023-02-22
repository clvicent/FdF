/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clvicent <clvicent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 17:42:48 by clvicent          #+#    #+#             */
/*   Updated: 2023/02/22 18:21:54 by clvicent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	struct_filler(t_fdf *f)
{	
	int	delta_x;
	int	delta_y;

	delta_x = (f->m.size_x + f->m.size_y) * f->l.half_width;
	delta_y = (f->m.size_x + f->m.size_y - 2) * f->l.half_height;
	f->m.start_x = (f->scx - f->m.size_p_x * (f->m.size_x - 1)) / 2;
	f->m.start_y = (f->scy - f->m.size_p_y * (f->m.size_y - 1)) / 2;
	f->l.true_x = ((f->scx - delta_x) / 2) + (f->m.size_y * f->l.half_width);
	f->l.true_y = ((f->scy - delta_y) / 2);
	set_alt(f);
	if (check_tab(f) < 0)
		shut_fdf(f, "alt too high/deep\n", 1);
}

void	set_alt(t_fdf *f)
{
	int	x;
	int	y;

	y = 0;
	f->m.min_alt = f->tab[0][0];
	f->m.max_alt = f->tab[0][0];
	while (y < f->m.size_y)
	{
		x = 0;
		while (x < f->m.size_x)
		{
			if (f->m.min_alt > f->tab[y][x])
				f->m.min_alt = f->tab[y][x];
			if (f->m.max_alt < f->tab[y][x])
				f->m.max_alt = f->tab[y][x];
			x++;
		}
		y++;
	}
	if (f->m.min_alt >= 0)
		f->m.alt_0 = f->m.min_alt;
	if (f->m.max_alt <= 0)
		f->m.alt_0 = f->m.max_alt;
	f->l.zoom = get_zoom(f);
}

int	wl_util(t_fdf *f, char **tmp, char *line, int y)
{
	if (f->m.size_x == 0)
	{
		f->m.size_x = get_n_col(tmp);
		f->tab = ft_gen_tab(f->m.size_x, f->m.size_y, 0);
	}
	else if (f->m.size_x != get_n_col(tmp) && y != f->m.size_y)
	{
		if (line)
			free(line);
		if (tmp)
			ft_exit(tmp);
		close_gnl(f->fd);
		return (-1);
	}
	return (1);
}

void	shut_fdf(t_fdf *f, char *message, int flag)
{
	if (f->tab && flag == 1)
		free_tab(f->tab, f->m.size_y);
	ft_putstr_fd(message, 2);
	if (flag != 2)
	{
		mlx_destroy_image(f->mlx, f->img.i_p);
		mlx_destroy_window(f->mlx, f->win);
		mlx_destroy_display(f->mlx);
		if (f->mlx)
			free(f->mlx);
	}
	exit (0);
}
