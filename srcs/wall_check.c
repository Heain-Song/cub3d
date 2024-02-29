/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-siga <ede-siga@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 15:56:57 by ede-siga          #+#    #+#             */
/*   Updated: 2024/02/29 18:17:50 by ede-siga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <cub3d.h>

int	wall_check_move_up(t_elems *elems)
{
	int	x;
	int	y;

	printf("(back) before y = %f, x = %f\n", elems->player_y, elems->ray.pos_x);
	y = elems->player_y + elems->ray.dir_y * 0.13;
	x = elems->ray.pos_x - elems->ray.dir_x * 0.13;
	printf("(back) after = y = %d, x = %d\n", y, x);
	if (elems->map[y][x] == '1' || elems->map[y][x] == 0)
	{
		printf("line buggy = %s, col buggy = %d", elems->map[y], x);
		return (1);
	}
/*	x -= 0.1;
	if (elems->map[y][x] == '1' || elems->map[y][x] == 0)
		return (1);
	x += 0.2;
	if (elems->map[y][x] == '1' || elems->map[y][x] == 0)
		return (1);
*/
	return (0);
}

int	wall_check_move_left(t_elems *elems)
{
	int	x;
	int	y;

	y = elems->ray.pos_y - elems->ray.dir_x * 0.13;
	x = elems->ray.pos_x - elems->ray.dir_y * 0.13;
	if (elems->map[y][x] == '1' || elems->map[y][x] == 0)
	{
		printf("line buggy = %s, col buggy = %d", elems->map[y], x);
		return (1);
	}
	return (0);
}

int	wall_check_move_right(t_elems *elems)
{
		int	x;
	int	y;

	y = elems->ray.pos_y + elems->ray.dir_x * 0.13;
	x = elems->ray.pos_x + elems->ray.dir_y * 0.13;
	if (elems->map[y][x] == '1' || elems->map[y][x] == 0)
	{
		printf("line buggy = %s, col buggy = %d", elems->map[y], x);
		return (1);
	}
	return (0);

}
