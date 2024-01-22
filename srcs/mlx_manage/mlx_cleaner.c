/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_clear.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-siga <ede-siga@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 10:21:08 by ede-siga          #+#    #+#             */
/*   Updated: 2024/01/22 15:44:11 by ede-siga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	clean_mlx(t_num_mlx mlx_l)
{
	if (mlx_l.window)
		mlx_destroy_window(mlx_l.server, mlx_l.window);
	if (mlx_l.server)
	{
		mlx_destroy_display(mlx_l.server);
		free(mlx_l.server);
	}
}
