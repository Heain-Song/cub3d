/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hesong <hesong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 11:04:21 by ede-siga          #+#    #+#             */
/*   Updated: 2024/02/29 12:16:38 by ede-siga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

int	window_destroyer(t_num_mlx *mlx)
{
	mlx_destroy_window(mlx->server, mlx->window);
	mlx->window = NULL;
	return (-1);
}

int	pressed_key(int keycode, t_elems *elems)
{
	int y;
	int x;
	double back_dir_x;
	double back_plane_x;
	
	if (keycode == 65364 || keycode == 115)
	{
		y = elems->ray.pos_y - elems->ray.dir_y * 0.1;
		x = elems->player_x - elems->ray.dir_x * 0.1;
		if (elems->map[y][x] == '1')
			return (0);
		//elems->ray.pos_x += 0.1;
		elems->ray.pos_y -= elems->ray.dir_y * 0.1;
		elems->ray.pos_x += elems->ray.dir_x * 0.1;
		elems->player_x -= elems->ray.dir_x * 0.1;
		elems->player_y = elems->ray.pos_y;
		//elems->player_x -= 0.1;
		//elems->player_x = elems->ray.pos_x;
	}
	//back function
	if (keycode == 65362 || keycode == 119)
	{
		//printf("dir_x = %f pos_x = %f", elems->player_x, elems->ray.pos_x);
		y = elems->ray.pos_y + elems->ray.dir_y * 0.1;
		x = elems->player_x + elems->ray.dir_x * 0.1;
		if (elems->map[y][x] == '1')
			return (0);
		elems->ray.pos_y += elems->ray.dir_y * 0.1;
		elems->ray.pos_x -= elems->ray.dir_x * 0.1;
		elems->player_y = elems->ray.pos_y;
		elems->player_x += elems->ray.dir_x * 0.1;
		//printf("dir_x = %f pos_x = %f", elems->player_x, elems->ray.pos_x);
	}
	//forward function
	if (keycode == 65361 || keycode == 97)
	{
		elems->ray.current_angle += 0.1;
		back_plane_x = elems->ray.plane_x;
		back_dir_x = elems->ray.dir_x;
		elems->ray.dir_x = elems->ray.dir_x * cos(0.1) - elems->ray.dir_y * sin(0.1);
		elems->ray.dir_y = back_dir_x * sin(0.1) + elems->ray.dir_y * cos(0.1);
		elems->ray.plane_x = elems->ray.plane_x * cos(0.1) - elems->ray.plane_y * sin(0.1);
		elems->ray.plane_y = back_plane_x * sin(0.1) + elems->ray.plane_y * cos(0.1);  
		//elems->ray.plane_y += -0.1;
		//elems->ray.plane_x += 0.1;
		//elems->ray.pos_x += -0.5;
		//elems->player_x += -0.5;
	}
	//left function
	if (keycode == 65363 || keycode == 100)
	{
		elems->ray.current_angle -= 0.1;
		back_plane_x = elems->ray.plane_x;
		back_dir_x = elems->ray.dir_x;
		elems->ray.dir_x = elems->ray.dir_x * cos(-0.1) - elems->ray.dir_y * sin(-0.1);
		elems->ray.dir_y = back_dir_x * sin(-0.1) + elems->ray.dir_y * cos(-0.1);
		elems->ray.plane_x = elems->ray.plane_x * cos(-0.1) - elems->ray.plane_y * sin(-0.1);
		elems->ray.plane_y = back_plane_x * sin(-0.1) + elems->ray.plane_y * cos(-0.1);  
		//elems-
		//elems->ray.plane_y += 0.1;
		//elems->ray.plane_x += 0.1;
		//elems->ray.pos_x += 0.5;
		//	elems->player_x += 0.5;
	}
	//right function
	if (keycode == 65307)
	{
		window_destroyer(&elems->mlx);
		return (-1);
	}
	return (0);
}

int	hook_event(t_num_mlx *mlx)
{
	if (!mlx || !mlx->window)
		return (-1);
	return (0);
}

t_elems	start_window_loop(t_elems elems)
{
	t_num_mlx	mlx;

	mlx.server = elems.mlx.server;
	elems.mlx.window = mlx_new_window(mlx.server, 800, 800, "Cub3D");
	elems = make_background(elems);
	mlx_hook(elems.mlx.window, 2, 1L << 0, pressed_key, &elems);
	mlx_hook(elems.mlx.window, 33, 1L << 3, window_destroyer, &elems.mlx);
	mlx_loop_hook(elems.mlx.server, hook_event, &elems.mlx);
	mlx_loop(elems.mlx.server);
	return (elems);
}
