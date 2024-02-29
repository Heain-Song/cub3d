/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-siga <ede-siga@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 21:56:37 by ede-siga          #+#    #+#             */
/*   Updated: 2024/02/29 22:07:30 by ede-siga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	get_f_c_colors(int *f_colors, int *c_colors, t_elems *elems)
{
	*f_colors = get_colors(0, elems->f_colors[0],
			elems->f_colors[1], elems->f_colors[2]);
	*c_colors = get_colors(0, elems->c_colors[0],
			elems->c_colors[1], elems->c_colors[2]);
}

void	draw_line(t_elems *elems, int x)
{
	get_lineinfo(elems);
	draw_iteration(elems, x);
}
