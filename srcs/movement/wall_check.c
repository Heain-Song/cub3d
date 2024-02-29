/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-siga <ede-siga@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 15:56:57 by ede-siga          #+#    #+#             */
/*   Updated: 2024/02/29 20:55:20 by ede-siga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <cub3d.h>

int	wall_check_move_up(t_elems *elems)
{
	int	x;
	int	y;

	y = elems->player_y + elems->ray.dir_y * 0.12;
	x = elems->ray.pos_x - elems->ray.dir_x * 0.12;
	if (elems->map[y][x] == '1' || elems->map[y][x] == 0)
		return (1);
	return (0);
}

int	wall_check_move_left(t_elems *elems)
{
	int	x;
	int	y;

	y = elems->ray.pos_y - elems->ray.dir_x * 0.12;
	x = elems->ray.pos_x - elems->ray.dir_y * 0.12;
	if (elems->map[y][x] == '1' || elems->map[y][x] == 0)
		return (1);
	return (0);
}

int	wall_check_move_right(t_elems *elems)
{
	int	x;
	int	y;

	y = elems->ray.pos_y + elems->ray.dir_x * 0.12;
	x = elems->ray.pos_x + elems->ray.dir_y * 0.12;
	if (elems->map[y][x] == '1' || elems->map[y][x] == 0)
		return (1);
	return (0);
}
