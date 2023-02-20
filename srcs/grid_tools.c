/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid_tools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clvicent <clvicent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 17:23:10 by clvicent          #+#    #+#             */
/*   Updated: 2023/02/20 14:22:01 by clvicent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_grid(t_fdf *f)
{
	int	y;
	int	x;

	x = 0;
	while (x < f->scx)
	{
		y = 0;
		while (y < f->scy)
		{
			if (is_in_grid(x, y, f))
				draw_grid(x, y, f);
			y++;
		}	
		x++;
	}
}

int	is_in_grid(int x, int y, t_fdf *f)
{
	if (x < f->m.start_x || x > (f->scx + 1 - f->m.start_x)
		|| y < f->m.start_y || y > (f->scy + 1 - f->m.start_y))
		return (0);
	if (((y - f->m.start_y) % f->m.size_p_y == 0)
		&& ((x - f->m.start_x) % f->m.size_p_x == 0))
		return (OK);
	if (x == (f->scx - f->m.start_x) && y == (f->scy - f->m.start_y))
		return (END);
	return (0);
}

void	l_c_size(t_fdf *f)
{
	int	delta;

	delta = f->m.size_x + f->m.size_y - 2;
	printf("f->m.size_x = %d\nf->m.size_y = %d\n", f->m.size_x, f->m.size_y);
	f->m.size_p_x = (f->scx - 1) / f->m.size_x;
	f->m.size_p_y = (f->scy - 1) / f->m.size_y;
	if (f->m.size_p_x > f->m.size_p_y)
		f->m.size_p_x = f->m.size_p_y;
	else
		f->m.size_p_y = f->m.size_p_x;
	f->l.half_width = (f->scx - f->scx / 25) / delta;
	f->l.half_height = (f->scy - f->scy / 25) / delta;
	if (f->l.half_height * 2 > f->l.half_width)
		f->l.half_height = f->l.half_width / 2;
	else
		f->l.half_width = f->l.half_height * 2;
}

int	width_and_length(t_fdf *f, char *file)
{
	char	*line;
	char	**tmp;
	int		y;

	f->m.size_y = get_file_len(file);
	f->fd = open(file, O_RDONLY);
	line = NULL;
	y = 0;
	while (y < f->m.size_y)
	{
		line = get_next_line(f->fd);
		if (line == NULL)
			return (close(f->fd));
		tmp = ft_split(line, ' ');
		if (wl_util(f, tmp, line, y) == -1)
			return (-1);
		tab_filler(f->tab, tmp, y);
		free(line);
		ft_exit(tmp);
		y++;
	}
	close_gnl(f->fd);
	return (0);
}

int	get_n_col(char **str)
{
	int		i;

	i = 0;
	if (!str)
		return (-1);
	while (str[i])
		i++;
	return (i);
}
