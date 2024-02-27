/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hesong <hesong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 20:55:16 by hesong            #+#    #+#             */
/*   Updated: 2024/02/27 14:14:35 by hesong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	get_plane(t_elems *elems)
{
	if (elems->player_dir == 'N')
		elems->ray.plane_x = 0.66;
	else if (elems->player_dir == 'S')
		elems->ray.plane_x = -0.66;
	else if (elems->player_dir == 'W')
		elems->ray.plane_y = -0.66;
	else if (elems->player_dir == 'E')
		elems->ray.plane_y = 0.66;
	else
		return ;
}

void	get_dir(t_elems *elems)
{
	if (elems->player_dir == 'N')
		elems->ray.dir_y = 1;
	else if (elems->player_dir == 'S')
		elems->ray.dir_y = -1;
	else if (elems->player_dir == 'W')
		elems->ray.dir_x = 1;
	else if (elems->player_dir == 'E')
		elems->ray.dir_x = -1;
	else
		return ;
}

void	get_position(t_elems *elems)
{
	elems->ray.pos_x = elems->player_x + 0.5; // x start position
	elems->ray.pos_y = elems->player_y + 0.5; // y start position
}

t_elems	raycast(t_elems elems)
{
	elems = init_mlx(elems);
	save_texture(&elems);
	get_position(&elems);
	get_dir(&elems);
	get_plane(&elems);
	//mlx_hook(elems.mlx.window, 2, 1L << 0, ft_close_win, &elems.mlx);
	mlx_hook(elems.mlx.window, 2, 1L << 0, pressed_key, &elems);
	//mlx_hook(elems.mlx.window, 3, 1L << 1, key_release, &elems);
	mlx_hook(elems.mlx.window, 33, 1L << 3, window_destroyer, &elems.mlx);
	mlx_loop_hook(elems.mlx.server, &main_loop, &elems);
	mlx_loop(elems.mlx.server);
	return(elems);
}
