/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-siga <ede-siga@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 10:19:42 by ede-siga          #+#    #+#             */
/*   Updated: 2024/01/18 10:20:50 by ede-siga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

t_elems	init_mlx(t_elems elems)
{
	t_num_mlx	mlx_info;

	mlx_info.mlx_server = NULL;
	mlx_info.mlx_window = NULL;
	mlx_info.mlx_server = mlx_init();
	if (!mlx_info.mlx_server)
		return (basic_error(elems, "mlx server failed to create", NULL, NULL));
	elems.mlx_info = mlx_info;
	return (elems);
}
