/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clvicent <clvicent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 15:30:07 by clvicent          #+#    #+#             */
/*   Updated: 2023/04/04 17:42:21 by clvicent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	exit_cross(t_fdf *f)
{
	shut_fdf(f, "shut by exit cross\n", 1);
	exit(0);
}

int	main(int ac, char **av)
{
	t_fdf	f;

	f = malloc(sizeof(t_fdf));
	if (ac != 2 || check_ext(av[1], ".fdf") != 1)
		shut_fdf(&f, "Usage : ./fdf <filename.fdf>\n", 2);
	init_env(&f);
	if (-1 == width_and_length(&f, av[1]))
		shut_fdf(&f, "tab error\n", 1);
	init_mlx(&f);
	l_c_size(&f);
	if (f.l.half_height < 1 || f.l.half_width < 2)
		shut_fdf(&f, "win too small, you should try 2560 * 1440\n", 1);
	struct_filler(&f);
	ft_grid(&f);
	mlx_put_image_to_window(f.mlx, f.win, f.img.i_p, 0, 0);
	mlx_key_hook(f.win, key_press, &f);
	mlx_mouse_hook(f.win, mouse_hook, &f);
	mlx_hook(f.win, 17, 1L << 0, exit_cross, &f);
	mlx_loop(f.mlx);
}
