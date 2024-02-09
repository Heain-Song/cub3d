/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hesong <hesong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 20:55:16 by hesong            #+#    #+#             */
/*   Updated: 2024/02/09 20:30:58 by hesong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_before_raycasting(t_elems *elems)
{
	elems->posX = 2; // x start position
	elems->posY = 2; // y start position
	elems->dirX = -1; // initial direction vector x
	elems->dirY = 0; // initial direction vector y
	elems->planeX = 0; //the 2d raycaster version of camera plane x
	elems->planeY = 0.66; //the 2d raycaster version of camera plane y
	elems->time = 0; //time of current frame
	elems->old_time = 0; //time of previous frame
	elems->move_speed = 0.05;
	elems->rotate_speed = 0.05;
}

t_elems	start_raycasting(t_elems elems)
{
	/*

	t_num_mlx	mlx;

	mlx.server = elems.mlx.server;
	elems.mlx.window = mlx_new_window(mlx.server, WIDTH, HEIGHT, PROG_NAME);
	mlx_hook(elems.mlx.window, 2, 1L << 0, ft_close_win, &elems.mlx);
	mlx_hook(elems.mlx.window, 33, 1L << 3, window_destroyer, &elems.mlx);
	mlx_loop_hook(elems.mlx.server, hook_event, &elems.mlx);
	mlx_loop(elems.mlx.server);
	//don't forget to free();

	*/

	/*untextured_testing - segfault when closed the game via ESC !!!!!!!!!!!!*/
	t_num_mlx	mlx;

	mlx.server = elems.mlx.server;
	init_before_raycasting(&elems);
	elems.mlx.window = mlx_new_window(mlx.server, WIDTH, HEIGHT, "TEST");
	mlx_hook(elems.mlx.window, 2, 1L << 0, ft_close_win, &elems.mlx);
	mlx_hook(elems.mlx.window, 33, 1L << 3, window_destroyer, &elems.mlx);
	mlx_loop_hook(mlx.server, &main_loop, &elems);
	mlx_loop(mlx.server);
	return(elems);
}

