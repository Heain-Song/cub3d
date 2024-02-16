/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hesong <hesong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 11:04:21 by ede-siga          #+#    #+#             */
/*   Updated: 2024/02/09 16:19:34 by hesong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

int	window_destroyer(t_num_mlx *mlx)
{
	mlx_destroy_window(mlx->server, mlx->window);
	mlx->window = NULL;
	return (-1);
}

int	ft_close_win(int keycode, t_num_mlx *mlx)
{
	if (keycode == 65307)
	{
		window_destroyer(mlx);
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
	mlx_hook(elems.mlx.window, 2, 1L << 0, ft_close_win, &elems.mlx);
	mlx_hook(elems.mlx.window, 33, 1L << 3, window_destroyer, &elems.mlx);
	mlx_loop_hook(elems.mlx.server, hook_event, &elems.mlx);
	mlx_loop(elems.mlx.server);
	return (elems);
}