/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-siga <ede-siga@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 20:52:22 by ede-siga          #+#    #+#             */
/*   Updated: 2024/02/29 20:52:42 by ede-siga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	rot_plus(t_elems *elems)
{
	double	back_dir_x;
	double	back_plane_x;

	back_plane_x = elems->ray.plane_x;
	back_dir_x = elems->ray.dir_x;
	elems->ray.dir_x = elems->ray.dir_x * cos(0.12)
		- elems->ray.dir_y * sin(0.12);
	elems->ray.dir_y = back_dir_x * sin(0.12) + elems->ray.dir_y * cos(0.1);
	elems->ray.plane_x = elems->ray.plane_x * cos(0.12)
		- elems->ray.plane_y * sin(0.12);
	elems->ray.plane_y = back_plane_x * sin(0.12)
		+ elems->ray.plane_y * cos(0.12);
}

void	rot_minus(t_elems *elems)
{
	double	back_plane_x;
	double	back_dir_x;

	back_plane_x = elems->ray.plane_x;
	back_dir_x = elems->ray.dir_x;
	elems->ray.dir_x = elems->ray.dir_x * cos(-0.12)
		- elems->ray.dir_y * sin(-0.12);
	elems->ray.dir_y = back_dir_x * sin(-0.12)
		+ elems->ray.dir_y * cos(-0.12);
	elems->ray.plane_x = elems->ray.plane_x
		* cos(-0.12) - elems->ray.plane_y * sin(-0.12);
	elems->ray.plane_y = back_plane_x * sin(-0.12)
		+ elems->ray.plane_y * cos(-0.12);
}
