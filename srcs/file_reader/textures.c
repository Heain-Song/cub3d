/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-siga <ede-siga@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 09:42:09 by ede-siga          #+#    #+#             */
/*   Updated: 2024/01/22 21:34:12 by ede-siga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

t_elems	check_textures(t_elems elems, char *str, char *node)
{
	void	*check_image;
	int		x;
	int		y;
	int		is_xpm;

	check_image = NULL;
	is_xpm = 0;
	x = 0;
	while (str[x] && str[x] != '.')
		x++;
	if (!ft_strcmp(str + x, ".xpm"))
		is_xpm = 1;
	x = 0;
	if (is_xpm)
		check_image = mlx_xpm_file_to_image(elems.mlx_l.server, str, &x, &y);
	if (!check_image)
		return (basic_error(elems, node, ": invalid texture\n", NULL));
	mlx_destroy_image(elems.mlx_l.server, check_image);
	return (elems);
}
