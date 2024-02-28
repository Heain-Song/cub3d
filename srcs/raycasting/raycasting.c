/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hesong <hesong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 15:49:29 by hesong            #+#    #+#             */
/*   Updated: 2024/02/28 16:54:13 by ede-siga         ###   ########.fr       */
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
			elems->ray.side = 0;
		}
		else
		{
			elems->ray.sidedist_y += elems->ray.deltadist_y;
			elems->ray.map_y += elems->ray.step_y;
			elems->ray.side = 1;
		}
		//**********Check if ray has hit a wall**********//
		//if ((elems->ray.map_x < WIDTH) && (elems->ray.map_y < HEIGHT) && (elems->map[elems->ray.map_y][elems->ray.map_x]== '1'))
		printf("ray.map_x in get_perp() : %d\n", elems->ray.map_x);
		printf("ray.map_y in get_perp() : %d\n", elems->ray.map_y);
		printf("before if, map[%d][%d]: %c\n", elems->ray.map_y, elems->ray.map_x,elems->map[elems->ray.map_y][elems->ray.map_x]);
		if (elems->map[elems->ray.map_y][elems->ray.map_x] == '1' && (elems->ray.map_x < WIDTH && elems->ray.map_y < HEIGHT)) // heapbuffer-overflow...........
		{
			printf("after if, map[%d][%d]: %c\n", elems->ray.map_y, elems->ray.map_x,elems->map[elems->ray.map_y][elems->ray.map_x]);
			elems->ray.hit = 1;
		}
	}
	if (elems->ray.side == 0) //HORIZONTAL
		elems->ray.perpwalldist = (elems->ray.sidedist_x - elems->ray.deltadist_x);
	else //VERTICAL
		elems->ray.perpwalldist = (elems->ray.sidedist_y - elems->ray.deltadist_y);
}

void	get_sidedist(t_elems *elems)
{
	if (elems->ray.raydir_x >= 0)
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
		elems->ray.deltadist_x = 0;
	else
		elems->ray.deltadist_x = fabs(1 / elems->ray.raydir_x);
	if (elems->ray.raydir_y == 0)
		elems->ray.deltadist_y = 0;
	else
		elems->ray.deltadist_y = fabs(1 / elems->ray.raydir_y);
}

void	get_camerax(t_elems *elems, int x)
{
	elems->ray.camera_x = 2 * x / (double)WIDTH - 1;
	elems->ray.raydir_x = elems->ray.dir_x + elems->ray.plane_x * elems->ray.camera_x;
	elems->ray.raydir_y = elems->ray.dir_y + elems->ray.plane_y * elems->ray.camera_x;
}

void	get_dist(t_elems *elems)
{
	elems->ray.map_x = (int)elems->ray.pos_x;
	elems->ray.map_y = (int)elems->ray.pos_y;
	get_deltadist(elems);
	get_sidedist(elems);
	get_perpwalldist(elems);
}

void	raycast(t_elems *elems)
{
	int	x;

	x = 0;
	while (x++ < WIDTH)
	{
		get_camerax(elems, x);
		get_dist(elems);
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
		return (-1);
	elems->screen.img = mlx_new_image(elems->mlx.server, WIDTH, HEIGHT);
	elems->screen.addr = mlx_get_data_addr(elems->screen.img,
			&elems->screen.bits_per_pixel,
			&elems->screen.line_length,
			&elems->screen.endian);
	//elems->ray.dir_y = elems->player_y + elems->ray.plane_y * elems->ray.camera_x;
	//elems->ray.dir_x = elems->player_x + elems->ray.plane_x * elems->ray.camera_x;

	raycast(elems);
	mlx_put_image_to_window(elems->mlx.server, elems->mlx.window, elems->screen.img, -1, 0);
	mlx_destroy_image(elems->mlx.server, elems->screen.img);
	return (-1); //???? why -1
}
