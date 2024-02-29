/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_dist.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hesong <hesong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 12:22:21 by hesong            #+#    #+#             */
/*   Updated: 2024/02/29 12:22:50 by hesong           ###   ########.fr       */
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

void	get_dist(t_elems *elems)
{
	elems->ray.map_x = (int)elems->ray.pos_x;
	elems->ray.map_y = (int)elems->ray.pos_y;
	get_deltadist(elems);
	get_sidedist(elems);
	get_perpwalldist(elems);
}
