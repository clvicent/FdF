/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clvicent <clvicent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 15:30:07 by clvicent          #+#    #+#             */
/*   Updated: 2023/02/20 14:14:27 by clvicent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	exit_cross(t_fdf *f)
{
	shut_fdf(f, "shut by exit cross\n", 1);
	exit(0);
}

int	key_press(int keycode, t_fdf *f)
{
	ft_printf("key_press()         : %i\n", keycode);
	if (keycode == 65307)
		shut_fdf(f, "shut by escape key\n", 1);
	else
		return (0);
	exit (0);
}

void	ft_init(t_fdf *f)
{
	t_data	*img;

	img = &f->img;
	f->m.size_x = 0;
	ft_bzero(&f->m, sizeof(t_math));
	ft_bzero(&f->l, sizeof(t_line));
	f->scx = SCX;
	f->scy = SCY;
	f->mlx = mlx_init();
	f->win = mlx_new_window(f->mlx, f->scx, f->scy, "fdf");
	img->i_p = mlx_new_image(f->mlx, f->scx, f->scy);
	img->ad = mlx_get_data_addr(img->i_p, &img->bpp, &img->l, &img->end);
}

int	main(int ac, char **av)
{
	t_fdf	f;

	if (ac != 2 || check_ext(av[1], ".fdf") != 1)
	{
		ft_putstr_fd("Usage : ./fdf <filename.fdf>\n", 1);
		return (0);
	}
	ft_init(&f);
	if (-1 == width_and_length(&f, av[1]))
	{
		shut_fdf(&f, "file error\n", 1);
		return (0);
	}
	l_c_size(&f);
	if (f.l.half_height < 1 || f.l.half_width < 2)
	{
		shut_fdf(&f, "win too small, you should try 2560 * 1440\n", 1);
		return (0);
	}
	struct_filler(&f);
	ft_grid(&f);
	mlx_put_image_to_window(f.mlx, f.win, f.img.i_p, 0, 0);
	mlx_key_hook(f.win, key_press, &f);
	mlx_hook(f.win, 17, 1L << 0, exit_cross, &f);
	mlx_loop(f.mlx);
}
