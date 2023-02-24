/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_tools.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clvicent <clvicent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 18:29:21 by clvicent          #+#    #+#             */
/*   Updated: 2023/02/23 17:22:52 by clvicent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	get_pos(int x, int y, t_fdf *f)
{
	f->m.index_y = (y - f->m.start_y) / f->m.size_p_y;
	f->m.index_x = (x - f->m.start_x) / f->m.size_p_x;
	f->m.c_alt = f->tab[f->m.index_y][f->m.index_x];
}

int	check_tab(t_fdf *f)
{
	int	y;
	int	x;

	y = 0;
	while (y < f->m.size_y)
	{
		x = 0;
		while (x < f->m.size_x)
		{
			if (f->tab[y][x] > 1000000 || f->tab[y][x] < -1000000)
				return (-1);
			x++;
		}
		y++;
	}
	return (0);
}

void	check_file(t_fdf *f)
{
	if (f->m.size_y == 0)
		shut_fdf(f, "empty file\n", 0);
	if (f->fd < 0 || f->fd > 1024)
		shut_fdf(f, "", 0);
}

int	atoi_fdf(const char *str)
{
	int			i;
	int			neg;
	long int	n;

	i = 0;
	neg = 1;
	n = 0;
	while ((str[i] <= 13 && str[i] >= 9) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			neg = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
		n = n * 10 + (str[i++] - '0');
	n *= neg;
	return ((int)n);
}

void	fdf_tab_filler(t_fdf *f, char **data, char *line, int index)
{
	int	i;

	i = 0;
	while (data[i])
	{
		if (ft_strlen_chr(data[i], ',') > 8)
		{
			if (line)
				free(line);
			ft_exit(data);
			close_gnl(f->fd);
			shut_fdf(f, "alt too high/deep\n", 1);
		}
		f->tab[index][i] = atoi_fdf(data[i]);
		i++;
	}
}
