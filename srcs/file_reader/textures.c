/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-siga <ede-siga@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 09:42:09 by ede-siga          #+#    #+#             */
/*   Updated: 2024/02/21 17:40:34 by ede-siga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

t_elems	check_textures(t_elems elems, t_textures *node)
{
	char	*str;
	int		x;
	int		is_xpm;

	str = node->path;
	is_xpm = 0;
	x = 0;
	while (str[x] && str[x] != '.')
		x++;
	if (!ft_strcmp(str + x, ".xpm"))
		is_xpm = 1;
	if (!node->img || !is_xpm)
		return (basic_error(elems, node->id, ": invalid texture\n", NULL));
	//mlx_destroy_image(elems.mlx.server, check_image);
	return (elems);
}
