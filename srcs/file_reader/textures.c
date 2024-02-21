/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-siga <ede-siga@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 09:42:09 by ede-siga          #+#    #+#             */
/*   Updated: 2024/02/21 13:56:33 by ede-siga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

t_elems	check_textures(t_elems elems, t_textures *node)
{
	char	*str;
	int		x;
	int		y;
	int		is_xpm;
	void	*img;

	str = node->path;
	is_xpm = 0;
	x = 0;
	node->img = NULL;
	while (str[x] && str[x] != '.')
		x++;
	if (!ft_strcmp(str + x, ".xpm"))
		is_xpm = 1;
	x = 0;
	if (is_xpm)
		img = mlx_xpm_file_to_image(elems.mlx.server, str, &x, &y);
	if (!img)
		return (basic_error(elems, node->id, ": invalid texture\n", NULL));
	node->img = img;
	//mlx_destroy_image(elems.mlx.server, check_image);
	return (elems);
}
