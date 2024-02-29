/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hesong <hesong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 15:49:29 by hesong            #+#    #+#             */
/*   Updated: 2024/02/29 21:48:51 by ede-siga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	get_camerax(t_elems *elems, int x)
{
	elems->ray.camera_x = 2 * x / (double)WIDTH - 1;
	elems->ray.raydir_x = elems->ray.dir_x
		+ elems->ray.plane_x * elems->ray.camera_x;
	elems->ray.raydir_y = elems->ray.dir_y
		+ elems->ray.plane_y * elems->ray.camera_x;
}

void	raycast(t_elems *elems)
{
	int	x;

	x = 0;
	while (x++ < WIDTH)
	{
		get_camerax(elems, x);
		get_dist(elems);
		draw_line(elems, x);
		elems->ray.line_height = (int)(1.5 * HEIGHT / elems->ray.perpwalldist);
		elems->ray.draw_start = -elems->ray.line_height / 2 + HEIGHT / 2;
		if (elems->ray.draw_start < 0)
			elems->ray.draw_start = 0;
		elems->ray.draw_end = elems->ray.line_height / 2 + HEIGHT / 2;
		if (elems->ray.draw_end >= HEIGHT || elems->ray.draw_end < 0)
			elems->ray.draw_end = HEIGHT - 1;
	}
}

int	main_loop(t_elems *elems)
{
	if (!elems->mlx.server || !elems->mlx.window)
		return (-1);
	elems->screen.img = mlx_new_image(elems->mlx.server, WIDTH, HEIGHT);
	elems->screen.addr = mlx_get_data_addr(elems->screen.img,
			&elems->screen.bits_per_pixel,
			&elems->screen.line_length,
			&elems->screen.endian);
	raycast(elems);
	mlx_put_image_to_window(elems->mlx.server,
		elems->mlx.window, elems->screen.img, -1, 0);
	mlx_destroy_image(elems->mlx.server, elems->screen.img);
	return (-1);
}
