/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hesong <hesong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 20:55:16 by hesong            #+#    #+#             */
/*   Updated: 2024/02/21 15:46:43 by hesong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*void	init_texture_to_buffer(t_elems *elems)
{
	unsigned int	i;
	int				x;
	int				y;
	t_textures		*textures;

	textures = elems->textures;
	i = 0;
	while (textures)
	{
		elems->texture_int_array[i] = (int *)textures->img;
		i++;
		textures = textures->next;
	}
}*/

void	get_plane(t_elems *elems)
{
	if (elems->player_dir == 'N')
		elems->ray.plane_x = 0.66;
	else if (elems->player_dir == 'S')
		elems->ray.plane_x = -0.66;
	else if (elems->player_dir == 'E')
		elems->ray.plane_y = 0.66;
	else
		elems->ray.plane_y = -0.66;
}

void	get_dir(t_elems *elems)
{
	if (elems->player_dir == 'N')
		elems->ray.dir_y = 1;
	else if (elems->player_dir == 'S')
		elems->ray.dir_y = -1;
	else if (elems->player_dir == 'W')
	{
		elems->ray.dir_x = 1;
	}
	else if (elems->player_dir == 'E')
		elems->ray.dir_x = -1;
	else
		elems->error = 1;
}

void	init_before_raycasting(t_elems *elems)
{
	elems->ray.pos_x = elems->player_x + 0.5; // x start position
	elems->ray.pos_y = elems->player_y + 0.5; // y start position
	get_dir(elems);
	//elems->ray.dir_x = -1; // initial direction vector x
	//elems->dirY = 0; // initial direction vector y
	get_plane(elems);
	//elems->ray.plane_x = 0; //the 2d raycaster version of camera plane x
	//elems->ray.plane_y = 0.66; //the 2d raycaster version of camera plane y
	elems->ray.time = 0; //time of current frame
	elems->ray.old_time = 0; //time of previous frame
	elems->ray.move_speed = 0.05;
	elems->ray.rotate_speed = 0.05;
	elems->ray.perpwalldist = 0;
	elems->ray.draw_start = 0;
	elems->ray.draw_end = 0;
	elems->color = 0;
	elems->ray.hit = 0;

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
	//mlx_hook(elems.mlx.window, 2, 1L << 0, ft_close_win, &elems.mlx);
	mlx_hook(elems.mlx.window, 2, 1L << 0, pressed_key, &elems.mlx);
	//mlx_hook(elems.mlx.window, 3, 1L << 1, key_release, &elems);
	mlx_hook(elems.mlx.window, 33, 1L << 3, window_destroyer, &elems.mlx);
	mlx_loop_hook(mlx.server, &main_loop, &elems);
	mlx_loop(mlx.server);
	return(elems);
}
