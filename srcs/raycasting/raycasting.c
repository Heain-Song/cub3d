/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hesong <hesong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 15:49:29 by hesong            #+#    #+#             */
/*   Updated: 2024/02/21 16:47:03 by ede-siga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main_loop(t_elems *elems)
{
	if (! elems->mlx.server || !elems->mlx.window)
	{
		elems->error = 1;
		return (0);
	}
	calc(elems);
	return (0);
}

void	get_perpwalldist(t_elems *elems)
{
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

void	init_raycast(t_elems *elems, int x)
{
	elems->ray.camera_x = 2 * x / (double)WIDTH - 1;
	elems->ray.raydir_x= elems->ray.dir_x + elems->ray.plane_x * elems->ray.camera_x;
	elems->ray.raydir_y = elems->ray.dir_y + elems->ray.plane_y * elems->ray.camera_x;
	elems->ray.map_x = (int)elems->ray.pos_x;
	elems->ray.map_y = (int)elems->ray.pos_y;
}

void	calc(t_elems *elems)
{
	int	x;

	x = 0;
	while (x++ < WIDTH)
	{
		init_raycast(elems, x);
		/*elems->ray.camera_x = 2 * x / (double)WIDTH - 1;
		  elems->ray.raydir_x= elems->ray.dir_x + elems->ray.plane_x * elems->ray.camera_x;
		  elems->ray.raydir_y = elems->dirY + elems->ray.plane_y * elems->ray.camera_x;
		  elems->ray.map_x = (int)elems->ray.pos_x;
		  elems->ray.map_y = (int)elems->ray.pos_y;*/
		
		//length of ray from one x or y-side to next x or y-side
		get_deltadist(elems);
		/*if (elems->ray.raydir_x== 0)
			elems->ray.deltadist_x = 2147483647;
			else
			elems->ray.deltadist_x = fabs(1 / elems->rayDirX);
			if (elems->ray.raydir_y == 0)
			elems->ray.deltadist_y = 2147483647;
			else
			elems->ray.deltadist_y = fabs(1 / elems->ray.raydir_y);*/
		
		//sideDist calculation
		get_sidedist(elems);
		/*if (elems->ray.raydir_x< 0)
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
		}*/
		
		//perpWalldist calculation
		get_perpwalldist(elems);
		/*while (elems->hit == 0)
		  {
		  //Jump to next map square, OR in x-direction, OR in y-direction
		  if (elems->ray.sidedist_x < elems->ray.sidedist_y)
		  {
		  elems->ray.sidedist_x += elems->ray.deltadist_x;
				elems->ray.map_x += elems->ray.step_x;
				elems->side = 0; //HORIZONTAL side hit (x)
				}
				else
				{
				elems->ray.sidedist_y += elems->ray.deltadist_y;
				elems->ray.map_y += elems->ray.step_y;
				elems->side = 1; //VERTICAL side hit (y)
				}
				
				//Check if ray has hit a wall
				if ((elems->ray.map_x < WIDTH) && (elems->ray.map_y < HEIGHT) && (elems->map[elems->ray.map_x][elems->ray.map_y]== '1'))
				elems->hit = 1;
				}*/
		
		if (elems->ray.side == 0) //HORIZONTAL
			//elems->ray.perpwalldist = (elems->ray.map_x - elems->ray.pos_x + (1 - elems->ray.step_x) / 2) / elems->rayDirX;
			elems->ray.perpwalldist = elems->ray.sidedist_x - elems->ray.deltadist_x;
		else //VERTICAL
			//elems->ray.perpwalldist = (elems->ray.map_y - elems->ray.pos_y + (1 - elems->ray.step_y) / 2) / elems->ray.raydir_y;
			elems->ray.perpwalldist = elems->ray.sidedist_y - elems->ray.deltadist_y;
		
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
