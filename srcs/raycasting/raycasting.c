/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hesong <hesong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 15:49:29 by hesong            #+#    #+#             */
/*   Updated: 2024/02/26 21:53:00 by hesong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"





void	get_perpwalldist(t_elems *elems)
{
	elems->ray.hit = 0;
	while (elems->ray.hit == 0)
	{
		/*****Jump to next map square, OR in x-direction, OR in y-direction*****/
		if (elems->ray.sidedist_x < elems->ray.sidedist_y)
		{
			elems->ray.sidedist_x += elems->ray.deltadist_x;
			elems->ray.map_x += elems->ray.step_x;
			elems->ray.side = 0; //HORIZONTAL side hit (x)
		}
		else
		{
			elems->ray.sidedist_y += elems->ray.deltadist_y;
			elems->ray.map_y += elems->ray.step_y;
			elems->ray.side = 1; //VERTICAL side hit (y)
		}
		//**********Check if ray has hit a wall**********//
		if ((elems->ray.map_x < WIDTH) && (elems->ray.map_y < HEIGHT) && (elems->map[elems->ray.map_y][elems->ray.map_x]== '1'))
			elems->ray.hit = 1;
	}
	if (elems->ray.side == 0)
		elems->ray.perpwalldist = (elems->ray.sidedist_x - elems->ray.deltadist_x);
	else
		elems->ray.perpwalldist = (elems->ray.sidedist_y - elems->ray.deltadist_y);
}

void	get_sidedist(t_elems *elems)
{
	if (elems->ray.raydir_x < 0)
	{
		elems->ray.step_x = -1;
		elems->ray.sidedist_x = (elems->ray.pos_x - elems->ray.map_x) * elems->ray.deltadist_x;
	}
	else
	{
		elems->ray.step_x = 1;
		elems->ray.sidedist_x = (elems->ray.map_x + 1.0 - elems->ray.pos_x) * elems->ray.deltadist_x;
	}
	if (elems->ray.raydir_y < 0)
	{
		elems->ray.step_y = -1;
		elems->ray.sidedist_y = (elems->ray.pos_y - elems->ray.map_y) * elems->ray.deltadist_y;
	}
	else
	{
		elems->ray.step_y = 1;
		elems->ray.sidedist_y = (elems->ray.map_y + 1.0 - elems->ray.pos_y) * elems->ray.deltadist_y;
	}
}

void	get_deltadist(t_elems *elems)
{
	if (elems->ray.raydir_x == 0)
		elems->ray.deltadist_x = 2147483647;
	else
		elems->ray.deltadist_x = fabs(1 / elems->ray.raydir_x);
	if (elems->ray.raydir_y == 0)
		elems->ray.deltadist_y = 2147483647;
	else
		elems->ray.deltadist_y = fabs(1 / elems->ray.raydir_y);
}

void	get_camerax(t_elems *elems, int x)
{
	elems->ray.camera_x = 2 * x / (double)WIDTH - 1;
	//printf("\tray.camera_x: %f\n", elems->ray.camera_x);
	elems->ray.raydir_x= elems->ray.dir_x + elems->ray.plane_x * elems->ray.camera_x;
	//printf("\tray.raydir_x: %f\n", elems->ray.raydir_x);
	elems->ray.raydir_y = elems->ray.dir_y + elems->ray.plane_y * elems->ray.camera_x;
	//printf("\tray.raydir_y: %f\n", elems->ray.raydir_y);
	elems->ray.map_x = (int)elems->ray.pos_x;
	//printf("\tray.map_x: %d\n", elems->ray.map_x);
	elems->ray.map_y = (int)elems->ray.pos_y;
	//printf("\tray.map_y: %d\n", elems->ray.map_y);
}

void	calc(t_elems *elems)
{
	int	x;

	x = 0;
	while (x++ < WIDTH)
	{
		get_camerax(elems, x);
		get_deltadist(elems);
		get_sidedist(elems);
		get_perpwalldist(elems);
		draw_line(elems, x);
		/*****Calculate height of line to draw on screen*****/
		elems->ray.line_height = (int)(1.5 * HEIGHT / elems->ray.perpwalldist);

		/*****Calculate lowest and highest pixel to fill in current stripe*****/
		elems->ray.draw_start = -elems->ray.line_height / 2 + HEIGHT / 2;
		if(elems->ray.draw_start < 0)
			elems->ray.draw_start = 0;
		elems->ray.draw_end = elems->ray.line_height / 2 + HEIGHT / 2;
		if(elems->ray.draw_end >= HEIGHT || elems->ray.draw_end < 0)
			elems->ray.draw_end = HEIGHT - 1;
	}
}

int	main_loop(t_elems *elems)
{
	if (!elems->mlx.server || !elems->mlx.window)
	{
		elems->error = 0;
		return (-1);
	}
	elems->screen.img = mlx_new_image(elems->mlx.server, WIDTH, HEIGHT);
	elems->screen.addr = mlx_get_data_addr(elems->screen.img,
			&elems->screen.bits_per_pixel,
			&elems->screen.line_length,
			&elems->screen.endian);
	calc(elems);
	mlx_put_image_to_window(elems->mlx.server, elems->mlx.window, elems->screen.img, -1, 0);
	mlx_destroy_image(elems->mlx.server, elems->screen.img);
	return (-1); //???? why -1
}
