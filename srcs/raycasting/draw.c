/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hesong <hesong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 15:08:10 by hesong            #+#    #+#             */
/*   Updated: 2024/02/29 22:06:06 by ede-siga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

unsigned int	get_pixel_color(t_data *data, int x, int y)
{
	char	*dst;

	if (x < 0 || y < 0 || x > WIDTH || y > HEIGHT)
		return (0);
	dst = data->addr
		+ (y * data->line_length + x * (data->bits_per_pixel / 8));
	return (*(unsigned int *)dst);
}

static int	get_w_dir(t_elems *elems)
{
	int		w_dir;

	if (elems->ray.side == 1 && elems->ray.raydir_y > 0)
		w_dir = NORTH;
	if (elems->ray.side == 1 && elems->ray.raydir_y < 0)
		w_dir = SOUTH;
	if (elems->ray.side == 0 && elems->ray.raydir_x > 0)
		w_dir = WEST;
	if (elems->ray.side == 0 && elems->ray.raydir_x < 0)
		w_dir = EAST;
	return (w_dir);
}

void	put_pixel(t_data *data, int y, int x, int color)
{
	char	*dst;

	if (x < 0 || y < 0 || x > WIDTH || y > HEIGHT)
		return ;
	dst = data->addr
		+ (x * data->line_length + y * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	draw_iteration(t_elems *elems, int x)
{
	int	y;
	int	c_color;
	int	f_color;

	get_f_c_colors(&f_color, &c_color, elems);
	y = 0;
	while (y < HEIGHT)
	{
		elems->ray.tex_y = (int)((double)elems->ray.drawn_len
				/ (double)elems->ray.line_height * (double)(128));
		if (y >= elems->ray.draw_start && y <= elems->ray.draw_end)
		{
			put_pixel(&(elems->screen), x, y,
				get_pixel_color(&(elems->tex[get_w_dir(elems)]),
					elems->ray.tex_x, elems->ray.tex_y));
			elems->ray.drawn_len++;
		}
		else if (y < HEIGHT / 2)
			put_pixel(&(elems->screen), x, y, c_color);
		else
			put_pixel(&(elems->screen), x, y, f_color);
		y++;
	}
}

void	get_lineinfo(t_elems *elems)
{
	if (elems->ray.side == 0)
		elems->ray.wall_x = elems->player_y
			+ elems->ray.perpwalldist * elems->ray.raydir_y;
	else
		elems->ray.wall_x = elems->player_x
			+ elems->ray.perpwalldist * elems->ray.raydir_x;
	elems->ray.wall_x -= floor(elems->ray.wall_x);
	elems->ray.tex_x = (int)(elems->ray.wall_x * (double)(128));
	elems->ray.line_height = (int)(HEIGHT / elems->ray.perpwalldist);
	elems->ray.draw_start = -elems->ray.line_height / 2 + HEIGHT / 2;
	elems->ray.drawn_len = 0;
	if (elems->ray.draw_start < 0)
	{
		elems->ray.drawn_len = abs(elems->ray.draw_start);
		elems->ray.draw_start = 0;
	}
	elems->ray.draw_end = elems->ray.line_height / 2 + HEIGHT / 2;
	if (elems->ray.draw_end >= HEIGHT)
		elems->ray.draw_end = HEIGHT - 1;
}
