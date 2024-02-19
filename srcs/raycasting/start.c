/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hesong <hesong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 20:55:16 by hesong            #+#    #+#             */
/*   Updated: 2024/02/19 16:46:18 by hesong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_texture_to_buffer(t_elems *elems)
{
	elems->texture_int_array[0] = xpm_to_img(elems, elems->textures->id->path..? );
	elems->texture_int_array[1] = xpm_to_img(elems, );
	elems->texture_int_array[2] = xpm_to_img(elems,);
	elems->texture_int_array[3] = xpm_to_img(elems,);
}

void	get_plane(t_elems *elems)
{
	if (elems->player_dir == 'N')
		elems->planeX = 0.66;
	else if (elems->player_dir == 'S')
		elems->planeX = -0.66;
	else if (elems->player_dir == 'E')
		elems->planeY = 0.66;
	else
		elems->planeY = -0.66;
}

void	get_dir(t_elems *elems)
{
	printf("dir: %c\n", elems->player_dir);
	if (elems->player_dir == 'N')
		elems->dirY = 1;
	else if (elems->player_dir == 'S')
		elems->dirY = -1;
	else if (elems->player_dir == 'W')
	{
		elems->dirX = 1;
	}
	else if (elems->player_dir == 'E')
		elems->dirX = -1;
	else
		elems->error = 1;
}

void	init_before_raycasting(t_elems *elems)
{
	elems->posX = elems->player_x + 0.5; // x start position
	elems->posY = elems->player_y + 0.5; // y start position
	get_dir(elems);
	//elems->dirX = -1; // initial direction vector x
	//elems->dirY = 0; // initial direction vector y
	get_plane(elems);
	//elems->planeX = 0; //the 2d raycaster version of camera plane x
	//elems->planeY = 0.66; //the 2d raycaster version of camera plane y
	elems->time = 0; //time of current frame
	elems->old_time = 0; //time of previous frame
	elems->move_speed = 0.05;
	elems->rotate_speed = 0.05;
	elems->perpWallDist = 0;
	elems->draw_start = 0;
	elems->draw_end = 0;
	elems->color = 0;
	elems->hit = 0;

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
	elems.mlx.window = mlx_new_window(mlx.server, WIDTH, HEIGHT, PROG_NAME);

	elems.textures = calloc(1, sizeof(t_textures)); //ft_calloc
	if (!elems.textures)
	{
		elems.error = 1;
		return (elems);
	}
	elems.texture_int_array = calloc(5, sizeof(int *)); //ft_calloc
	if (!elems.texture_int_array)
	{
		elems.error = 1;
		return (elems);
	}

	//mlx_hook(elems.mlx.window, 2, 1L << 0, ft_close_win, &elems.mlx);
	mlx_hook(elems.mlx.window, 2, 1L << 0, pressed_key, &elems.mlx);
	//mlx_hook(elems.mlx.window, 3, 1L << 1, key_release, &elems);
	mlx_hook(elems.mlx.window, 33, 1L << 3, window_destroyer, &elems.mlx);
	mlx_loop_hook(mlx.server, &main_loop, &elems);
	mlx_loop(mlx.server);
	return(elems);
}

