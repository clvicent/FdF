/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clvicent <clvicent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 13:57:29 by clvicent          #+#    #+#             */
/*   Updated: 2023/01/09 21:15:59 by clvicent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	exit_cross(t_fdf *f)
{
	shut_fdf(f, "shut by exit cross");
	exit(0);
}

int	key_press(int keycode, t_fdf *f)
{
	printf("key_press()         : %i\n", keycode);
	if (keycode == 65307)
		shut_fdf(f, "shut by escape key");
	exit (0);
}
// 
// void	print_param(t_math *m)
// {
// 	printf("index_x = %d\n", m->index_x);
// 	printf("index_y = %d\n", m->index_y);
// 	printf("size_x = %d\n", m->size_x);
// 	printf("size_p_x = %d\n", m->size_p_x);
// 	printf("size_y = %d\n", m->size_y);
// 	printf("size_p_y = %d\n", m->size_p_y);
// 	printf("max_alt = %d\n", m->max_alt);
// 	printf("min_alt = %d\n", m->min_alt);
// 	printf("start_x = %d\n", m->start_x);
// 	printf("start_y = %d\n", m->start_y);
// 	printf("alt_0 = %d\n", m->alt_0);
// 	printf("next_alt = %d\n", m->next_alt);
// 	printf("c_alt = %d\n", m->c_alt);
// 	printf("flag = %d\n", m->flag);
// }
#if 0
int	main(int ac, char **av)
{
	t_fdf	f;

	if (ac != 2)
	{
		printf("Usage : ./fdf <filename.fdf>\n");
		return (1);
	}
	ft_init(&f, av[1]);
	if (-1 == width_and_length(&f))
	{
		printf("file is empty\n");
		return (1);
	}
	l_c_size(&f);
	struct_filler(&f);
	input_maker(&f);
	set_alt(&f);
	ft_grid(&f);
	mlx_put_image_to_window(f.mlx, f.win, f.img.img_ptr, 0, 0);
	mlx_key_hook(f.win, key_press, &f);
	mlx_hook(f.win, 17, 1L << 0, exit_cross, &f);
	mlx_loop(f.mlx);
}
#else
int	main(int ac, char **av)
{
	t_fdf	f;

	(void)ac;
	ft_init(&f, av[1]);
	LOG
	draw_line(&f, 0, 0, 1900, 1000);
	LOG
	// draw_line(&f, 1860, 1000, 0, 0);
	// draw_line(&f, 0, 0, 1920, 1080);
	// draw_line(&f, 0, 0, 1920, 1080);
	// draw_line(&f, 0, 0, 1920, 1080);
	// draw_line(&f, 0, 0, 1920, 1080);
	// draw_line(&f, 0, 0, 1920, 1080);
	// draw_line(&f, 0, 0, 1920, 1080);
	
	mlx_put_image_to_window(f.mlx, f.win, f.img.img_ptr, 0, 0);
	mlx_key_hook(f.win, key_press, &f);
	mlx_hook(f.win, 17, 1L << 0, exit_cross, &f);
	mlx_loop(f.mlx);
}
#endif