/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hesong <hesong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 10:19:42 by ede-siga          #+#    #+#             */
/*   Updated: 2024/02/29 21:31:43 by ede-siga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

t_elems	init_mlx(t_elems elems)
{
	elems.mlx.server = mlx_init();
	elems.mlx.window = NULL;
	if (!elems.mlx.server)
		return (error_reading(NULL, "mlx server failed to create.\n", elems));
	elems.mlx.window = mlx_new_window(elems.mlx.server, WIDTH, HEIGHT, PROG);
	if (!elems.mlx.window)
		return (error_reading(NULL, "mlx window failed to create.\n", elems));
}
