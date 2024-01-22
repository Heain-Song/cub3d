/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-siga <ede-siga@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 10:19:42 by ede-siga          #+#    #+#             */
/*   Updated: 2024/01/22 12:49:47 by ede-siga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

t_elems	init_mlx(t_elems elems)
{
	t_num_mlx	mlx_info;
	void		*win;

	mlx_info.mlx_server = NULL;
	mlx_info.mlx_window = NULL;
	mlx_info.mlx_server = mlx_init();
	if (!mlx_info.mlx_server)
		return (error_reading(NULL, "mlx server failed to create\n", elems));
	win = mlx_new_window(mlx_info.mlx_server, 800, 800, "Cub3D");
	if (!win)
		return (error_reading(NULL, "mlx window failed to create\n", elems));
	mlx_info.mlx_window = win;
	elems.mlx_info = mlx_info;
	return (elems);
}
