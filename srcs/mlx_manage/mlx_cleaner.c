/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_clear.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-siga <ede-siga@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 10:21:08 by ede-siga          #+#    #+#             */
/*   Updated: 2024/01/18 10:26:20 by ede-siga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	clean_mlx(t_num_mlx mlx_info)
{
	mlx_destroy_display(mlx_info.mlx_server);
	free(mlx_info.mlx_server);
}
