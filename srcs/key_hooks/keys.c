/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hesong <hesong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 17:32:00 by hesong            #+#    #+#             */
/*   Updated: 2024/03/01 11:38:20 by ede-siga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	window_destroyer(t_num_mlx *mlx)
{
	mlx_destroy_window(mlx->server, mlx->window);
	mlx->window = NULL;
	return (-1);
}

int	pressed_key(int keycode, t_elems *elems)
{
	if (keycode == 115)
		move_plus(elems);
	if (keycode == 119)
		move_minus(elems);
	if (keycode == 97)
		move_right(elems);
	if (keycode == 100)
		move_left(elems);
	if (keycode == 65361)
		rot_plus(elems);
	if (keycode == 65363)
		rot_minus(elems);
	if (keycode == 65307)
	{
		window_destroyer(&elems->mlx);
		return (-1);
	}
	return (0);
}
