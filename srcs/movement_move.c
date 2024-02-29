/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_move.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-siga <ede-siga@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 13:08:30 by ede-siga          #+#    #+#             */
/*   Updated: 2024/02/29 15:25:41 by ede-siga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	move_plus(t_elems *elems) //rename
{
	int	x;
	int	y;

	printf("(back) before y = %f, x = %f\n", elems->player_y, elems->player_x);
	y = elems->player_y - elems->ray.dir_y * 0.1;
	x = elems->ray.pos_x + elems->ray.dir_x * 0.1;
	printf("(back) after y = %d, x = %d", y, x);
	if (elems->map[y][x] == '1' || elems->map[y][x] == 0)
		return;
	elems->ray.pos_y -= elems->ray.dir_y * 0.1;
	elems->ray.pos_x += elems->ray.dir_x * 0.1;
	elems->player_x -= elems->ray.dir_x * 0.1;
	elems->player_y = elems->ray.pos_y;
}

void	move_right(t_elems *elems)
{
	elems->ray.pos_y += elems->ray.dir_x * 0.1;
	elems->ray.pos_x += elems->ray.dir_y * 0.1;
	elems->player_x -= elems->ray.dir_y * 0.1;
	elems->player_y = elems->ray.pos_y;
}


	//elems->ray.pos_y += 0.1;
	//elems->player_y += 0.1;

void	move_left(t_elems *elems)
{
	elems->ray.pos_y -= elems->ray.dir_x * 0.1;
	elems->ray.pos_x -= elems->ray.dir_y * 0.1;
	elems->player_x += elems->ray.dir_y * 0.1;
	elems->player_y = elems->ray.pos_y;

}

void	move_minus(t_elems *elems) //rename
{
	int	x;
	int	y;

	printf("(forward) before y = %f, x = %f\n", elems->player_y, elems->player_x);
	//printf("dir_x = %f pos_x = %f", elems->player_x, elems->ray.pos_x);
	y = elems->player_y + elems->ray.dir_y * 0.1;
	x = elems->ray.pos_x - elems->ray.dir_x * 0.1;
	printf("(forward) after y = %d, x = %d\n", y, x);
	if (elems->map[y][x] == '1' || elems->map[y][x] == 0)
		return;
	elems->ray.pos_y += elems->ray.dir_y * 0.1;
	elems->ray.pos_x -= elems->ray.dir_x * 0.1;
	elems->player_y = elems->ray.pos_y;
	elems->player_x += elems->ray.dir_x * 0.1;
	//printf("dir_x = %f pos_x = %f", elems->player_x, elems->ray.pos_x);
}
void rot_plus(t_elems *elems) //rename
{
	double	back_dir_x;
	double	back_plane_x;

	back_plane_x = elems->ray.plane_x;
	back_dir_x = elems->ray.dir_x;
	elems->ray.dir_x = elems->ray.dir_x * cos(0.1) - elems->ray.dir_y * sin(0.1);
	elems->ray.dir_y = back_dir_x * sin(0.1) + elems->ray.dir_y * cos(0.1);
	elems->ray.plane_x = elems->ray.plane_x * cos(0.1) - elems->ray.plane_y * sin(0.1);
	elems->ray.plane_y = back_plane_x * sin(0.1) + elems->ray.plane_y * cos(0.1);  	
}

void rot_minus(t_elems *elems) //rename
{
	double	back_plane_x;
	double	back_dir_x;

	back_plane_x = elems->ray.plane_x;
	back_dir_x = elems->ray.dir_x;
	elems->ray.dir_x = elems->ray.dir_x * cos(-0.1) - elems->ray.dir_y * sin(-0.1);
	elems->ray.dir_y = back_dir_x * sin(-0.1) + elems->ray.dir_y * cos(-0.1);
	elems->ray.plane_x = elems->ray.plane_x * cos(-0.1) - elems->ray.plane_y * sin(-0.1);
	elems->ray.plane_y = back_plane_x * sin(-0.1) + elems->ray.plane_y * cos(-0.1);
}
