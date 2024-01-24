/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-siga <ede-siga@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 17:01:28 by ede-siga          #+#    #+#             */
/*   Updated: 2024/01/24 18:18:14 by ede-siga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	my_mlx_pixel_put(t_data *data, int y, int x, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	loop_image_put(int y, int x, t_data *img, int color)
{
	int	i;
	int	j;

	i = 0;
	while (i < y)
	{
		j = 0;
		while (j < x)
		{
			my_mlx_pixel_put(img, i, j, color);
			j++;
		}
		i++;
	}
}

t_elems	make_background(t_elems	elems)
{
	int		color;
	t_data	ceiling;
	t_data	floor;

	ceiling.img = mlx_new_image(elems.mlx.server, 800, 400);
	floor.img = mlx_new_image(elems.mlx.server, 800, 400);
	ceiling.addr = mlx_get_data_addr(ceiling.img, &ceiling.bits_per_pixel,
			&ceiling.line_length, &ceiling.endian);
	floor.addr = mlx_get_data_addr(floor.img, &floor.bits_per_pixel,
			&floor.line_length, &floor.endian);
	color = get_colors(0, elems.f_colors[0], elems.f_colors[1],
			elems.f_colors[2]);
	loop_image_put(400, 800, &floor, color);
	color = get_colors(0, elems.c_colors[0], elems.c_colors[1],
			elems.c_colors[2]);
	loop_image_put(400, 800, &ceiling, color);
	mlx_put_image_to_window(elems.mlx.server, elems.mlx.window,
		ceiling.img, 0, 0);
	mlx_put_image_to_window(elems.mlx.server, elems.mlx.window,
		floor.img, 0, 400);
	elems.ceiling = ceiling;
	elems.floor = floor;
	return (elems);
}
