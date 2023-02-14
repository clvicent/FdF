/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_tools.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clvicent <clvicent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 18:29:21 by clvicent          #+#    #+#             */
/*   Updated: 2023/02/13 19:16:44 by clvicent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"


void	get_pos(int x, int y, t_fdf *f)
{
	f->m.index_y = (y - f->m.start_y) / f->m.size_p_y;
	f->m.index_x = (x - f->m.start_x) / f->m.size_p_x;
	f->m.c_alt = f->tab[f->m.index_y][f->m.index_x];
}
