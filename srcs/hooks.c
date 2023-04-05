/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clvicent <clvicent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 14:37:04 by clvicent          #+#    #+#             */
/*   Updated: 2023/04/04 17:29:53 by clvicent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	mouse_hook(int keycode, t_fdf *f)
{
	if (keycode == 5)
	{
		f->l.half_height -= 10;
		f->l.half_width -= 20;
		// ft_grid(f);
		return (keycode);
	}
	if (keycode == 4)
	{
		f->l.half_height += 10;
		f->l.half_width += 20;
		// ft_grid(f);
		return (keycode);
	}
	return(0);
}

int	key_press(int keycode, t_fdf *f)
{
	ft_printf("key_press()         : %i\n", keycode);
	if (keycode == 65307)
		shut_fdf(f, "shut by escape key\n", 1);
	if (keycode >= LEFT && keycode <= DOWN)
		translation(keycode, f);
	else
		return (0);
	exit (0);
}

void	translation(int keycode, t_fdf *f)
{
	if (keycode == UP)
		f->l.true_y -= f->scy / 20;
	if (keycode == DOWN)
		f->l.true_y += f->scy / 20;
	if (keycode == RIGHT)
		f->l.true_x -= f->scy / 20;
	if (keycode == LEFT)
		f->l.true_x += f->scy / 20;
	ft_grid(f);
	mlx_put_image_to_window(f->mlx, f->win, f->img.i_p, 0, 0);
}