/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-siga <ede-siga@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 10:19:42 by ede-siga          #+#    #+#             */
/*   Updated: 2024/01/22 15:48:05 by ede-siga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

t_elems	init_mlx(t_elems elems)
{
	t_num_mlx	mlx_l;

	mlx_l.server = NULL;
	mlx_l.window = NULL;
	mlx_l.server = mlx_init();
	if (!mlx_l.server)
		return (error_reading(NULL, "mlx server failed to create\n", elems));
	//mlx_l.window = mlx_new_window(mlx_l.server, 800, 800, "Cub3D");
	//if (!mlx_l.window)
	//	return (error_reading(NULL, "mlx window failed to create\n", elems));
	elems.mlx_l = mlx_l;
	return (elems);
}
