/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hesong <hesong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 09:42:09 by ede-siga          #+#    #+#             */
/*   Updated: 2024/02/28 17:39:08 by hesong           ###   ########.fr       */
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
	printf("str in check_textures(): %s\n", str);
	while (str[x])
		x++;
	while (x > 0 && str[x] != '.')
		x--;
	if (!ft_strcmp(str + x, ".xpm"))
		is_xpm = 1;
	if (!node->img || !is_xpm)
		return (basic_error(elems, node->id, ": invalid texture\n", NULL));
	//mlx_destroy_image(elems.mlx.server, check_image);
	return (elems);
}

// t_elems	check_textures(t_elems elems, t_textures *node)
// {
// 	if (!node->img)
// 		return (basic_error(elems, node->id, ": invalid texture.\n", NULL));
// 	return (elems);
// }
