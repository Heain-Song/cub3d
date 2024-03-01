/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hesong <hesong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 20:55:16 by hesong            #+#    #+#             */
/*   Updated: 2024/03/01 16:16:22 by hesong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	get_plane(t_elems *elems)
{
	elems->ray.plane_y = 0;
	elems->ray.plane_x = 0;
	if (elems->player_dir == 'S')
		elems->ray.plane_x = 0.66;
	else if (elems->player_dir == 'N')
		elems->ray.plane_x = -0.66;
	else if (elems->player_dir == 'E')
		elems->ray.plane_y = 0.66;
	else if (elems->player_dir == 'W')
		elems->ray.plane_y = -0.66;
	else
		return ;
}

void	get_dir(t_elems *elems)
{
	elems->ray.dir_y = 0;
	elems->ray.dir_x = 0;
	if (elems->player_dir == 'S')
		elems->ray.dir_y = 1;
	else if (elems->player_dir == 'N')
		elems->ray.dir_y = -1;
	else if (elems->player_dir == 'E')
		elems->ray.dir_x = -1;
	else if (elems->player_dir == 'W')
		elems->ray.dir_x = 1;
	else
		return ;
}

void	get_position(t_elems *elems)
{
	elems->player_x += 0.5;
	elems->ray.pos_x = elems->player_x;
	elems->player_y += 0.5;
	elems->ray.pos_y = elems->player_y;
}

t_elems	launch_game(t_elems elems)
{
	if (elems.error == 1)
		return (elems);
	get_position(&elems);
	get_dir(&elems);
	get_plane(&elems);
	mlx_hook(elems.mlx.window, 2, 1L << 0, pressed_key, &elems);
	mlx_hook(elems.mlx.window, 33, 1L << 3, window_destroyer, &elems.mlx);
	mlx_loop_hook(elems.mlx.server, &main_loop, &elems);
	mlx_loop(elems.mlx.server);
	return (elems);
}
