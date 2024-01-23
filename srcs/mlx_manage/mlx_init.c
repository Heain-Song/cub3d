/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-siga <ede-siga@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 10:19:42 by ede-siga          #+#    #+#             */
/*   Updated: 2024/01/23 11:09:07 by ede-siga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

t_elems	init_mlx(t_elems elems)
{
	t_num_mlx	mlx;

	mlx.server = NULL;
	mlx.window = NULL;
	mlx.server = mlx_init();
	if (!mlx.server)
		return (error_reading(NULL, "mlx server failed to create\n", elems));
	elems.mlx = mlx;
	return (elems);
}
