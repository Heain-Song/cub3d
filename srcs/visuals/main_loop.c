/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hesong <hesong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 11:04:21 by ede-siga          #+#    #+#             */
/*   Updated: 2024/02/29 14:55:06 by ede-siga         ###   ########.fr       */
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
	if (keycode == 65364 || keycode == 115)
		move_plus(elems);
	//back function
	if (keycode == 65362 || keycode == 119)
		move_minus(elems);
	//forward function
	if (keycode == 97)
	{
		 if (elems->player_dir == 'E' || elems->player_dir == 'W')
			 move_left(elems);
		 else
			 move_right(elems);
	}
	
	if (keycode == 100)
	{
		if (elems->player_dir == 'E' || elems->player_dir == 'W')
			move_right(elems);
		else
			move_left(elems);
	}
	if (keycode == 65361)
	{
		if (elems->player_dir == 'E' || elems->player_dir == 'W')
			rot_minus(elems);
		else
			rot_plus (elems);
	}
	//left function
	//if (key_code == 100)
//		left
	if (keycode == 65363)
	{
		if (elems->player_dir == 'E' || elems->player_dir == 'W')
			rot_plus(elems);
		else
			rot_minus(elems);
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
