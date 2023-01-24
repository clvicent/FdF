/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clvicent <clvicent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 20:40:48 by clvicent          #+#    #+#             */
/*   Updated: 2023/01/24 19:59:20 by clvicent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_init(t_fdf *f, char *filename)
{
	t_data	*img;

	img = &f->img;
	ft_bzero(&f->m, sizeof(t_math));
	ft_bzero(&f->l, sizeof(t_line));
	f->fd = open(filename, O_RDONLY);
	f->scx = SCX;
	f->scy = SCY;
	f->mlx = mlx_init();
	f->win = mlx_new_window(f->mlx, f->scx, f->scy, "fdf");
	img->img_ptr = mlx_new_image(f->mlx, f->scx, f->scy);
	img->addr = mlx_get_data_addr(img->img_ptr, &img->bpp, &img->length, &img->endian);
}

void	shut_fdf(t_fdf *f, char *message)
{
	printf("%s", message);
	mlx_destroy_image(f->mlx, f->img.img_ptr);
	mlx_destroy_window(f->mlx, f->win);
	mlx_destroy_display(f->mlx);
	free(f->mlx);
}

void    ft_bzero(void *s, size_t n)
{
        size_t  i;

        i = 0;
        while (i != n)
        {
                ((unsigned char *)s)[i] = 0;
                i++;
        }
}

void	free_tab(int **tab, const int ylen)
{
	int	y;

	if (!tab)
		return ;
	y = 0;
	while (y < ylen)
	{
		free(tab[y]);
		y++;
	}
	free(tab);
	tab = NULL;
}

int		ft_abs(int i)
{
	if (i < 0)
		i = -i;
	return (i); 
}
