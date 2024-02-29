/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hesong <hesong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 10:19:42 by ede-siga          #+#    #+#             */
/*   Updated: 2024/02/29 12:12:26 by hesong           ###   ########.fr       */
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
	/*elems.img.img = mlx_new_image(elems.mlx.server, WIDTH, HEIGHT);
	if (!elems.img.img)
		return (error_reading(NULL, "mlx img failed to create.\n", elems));
	elems.img.addr = mlx_get_data_addr(elems.img.img,
			&elems.img.bits_per_pixel,
			&elems.img.line_length,
			&elems.img.endian);
	if (!elems.img.addr)
		return (error_reading(NULL, "mlx img addr failed to create.\n", elems));
		mlx_put_image_to_window(elems.mlx.server, elems.mlx.window, elems.img.img, 0, 0);*/
	return (elems);
}
