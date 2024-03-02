/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hesong <hesong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 13:08:30 by ede-siga          #+#    #+#             */
/*   Updated: 2024/03/02 10:40:43 by hesong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	move_plus(t_elems *elems)
{
	int	x;
	int	y;

	y = elems->player_y - elems->ray.dir_y * 0.12;
	x = elems->ray.pos_x + elems->ray.dir_x * 0.12;
	if (elems->map[y][x] == '1' || elems->map[y][x] == 0)
		return ;
	elems->ray.pos_y -= elems->ray.dir_y * 0.12;
	elems->player_y = elems->ray.pos_y;
	elems->ray.pos_x += elems->ray.dir_x * 0.12;
	elems->player_x -= elems->ray.dir_x * 0.12;
}

void	move_right(t_elems *elems)
{
	if (wall_check_move_right(elems))
		return ;
	elems->ray.pos_y += elems->ray.dir_x * 0.12;
	elems->ray.pos_x += elems->ray.dir_y * 0.12;
	elems->player_x -= elems->ray.dir_y * 0.12;
	elems->player_y = elems->ray.pos_y;
}

void	move_left(t_elems *elems)
{
	if (wall_check_move_left(elems))
		return ;
	elems->ray.pos_y -= elems->ray.dir_x * 0.12;
	elems->ray.pos_x -= elems->ray.dir_y * 0.12;
	elems->player_x += elems->ray.dir_y * 0.12;
	elems->player_y = elems->ray.pos_y;
}

void	move_minus(t_elems *elems)
{
	if (wall_check_move_up(elems))
		return ;
	elems->ray.pos_y += elems->ray.dir_y * 0.12;
	elems->ray.pos_x -= elems->ray.dir_x * 0.12;
	elems->player_y = elems->ray.pos_y;
	elems->player_x += elems->ray.dir_x * 0.12;
}
