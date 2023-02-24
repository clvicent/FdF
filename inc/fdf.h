/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clvicent <clvicent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 13:54:02 by clvicent          #+#    #+#             */
/*   Updated: 2023/02/24 12:23:21 by clvicent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

// # define LOG    printf("%s:%d %s()\n", __FILE__,__LINE__, __FUNCTION__);
// # define DEBUG 1
// # define PAUSE    if (DEBUG) {getchar();};

# define SCX 2560
# define SCY 1440
# define OK 1
# define END 2

# define LEFT 65361
# define UP 65362
# define RIGHT 65363
# define DOWN 65364

# include "libft.h"
# include "../mlx_linux/mlx.h"
# include <stdlib.h>
# include <math.h>
# include <fcntl.h>
# include <stdio.h>

typedef struct s_data {
	void	*i_p;
	char	*ad;
	int		bpp;
	int		l;
	int		end;
}	t_data;

typedef struct s_line {
	int	x0;
	int	y0;
	int	x1;
	int	y1;
	int	dx;
	int	dy;
	int	sx;
	int	sy;
	int	flag;
	int	true_x;
	int	true_y;
	int	seg_len;
	int	half_height;
	int	half_width;
	int	zoom;
}	t_line;

typedef struct s_math {
	int		index_x;
	int		index_y;
	int		size_x;
	int		size_y;
	int		size_p_x;
	int		size_p_y;
	int		start_x;
	int		start_y;
	int		max_alt;
	int		min_alt;
	int		alt_0;
	int		c_alt;
	int		next_alt;
	int		flag;
}	t_math;

typedef struct s_fdf {
	int		fd;
	int		**tab;
	char	*str;
	int		scx;
	int		scy;
	void	*mlx;
	void	*win;
	t_line	l;
	t_data	img;
	t_math	m;
}	t_fdf;

//grid_tools.c
void	ft_grid(t_fdf *f);
int		is_in_grid(int x, int y, t_fdf *f);
void	l_c_size(t_fdf *f);
int		width_and_length(t_fdf *f, char *file);
int		get_n_col(char **str);

//utils.c
void	set_alt(t_fdf *f);
void	struct_filler(t_fdf *f);
int		wl_util(t_fdf *f, char **tmp, char *line, int y);
void	shut_fdf(t_fdf *f, char *message, int flag);

//display_tools.c
int		get_zoom(t_fdf *f);
void	mlx_pp(t_data *img, int x, int y, int color);
void	set_pix(t_fdf *f, int x, int y);
int		get_rgb(int r, int g, int b);

//tab_tools.c
void	get_pos(int x, int y, t_fdf *f);
int		check_tab(t_fdf *f);
void	check_file(t_fdf *f);
int		atoi_fdf(const char *str);
void	fdf_tab_filler(t_fdf *f, char **data, char *line, int index);

//drawing_tools.c
void	draw_grid(int x, int y, t_fdf *f);
void	get_coord(int x, int y, t_fdf *f);
void	bresenham(t_fdf *f);
void	draw_line(t_fdf *f, t_line *l);
int		get_len(t_fdf *f);

//color_tools.c
int		ex_shader(int x_y, int next, t_fdf *f);
int		reg_shader(int prev, int next, float ratio);
int		spl(int color, int flag);
int		shade_zero(t_fdf *f, int color);
int		prev_color(t_fdf *f);

//colors.c
int		color_maker(t_fdf *f);
int		final_color(float ratio, t_fdf *f);
int		next_color(t_fdf *f);

#endif
