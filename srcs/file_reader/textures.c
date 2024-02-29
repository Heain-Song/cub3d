/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hesong <hesong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 09:42:09 by ede-siga          #+#    #+#             */
/*   Updated: 2024/02/29 21:40:36 by ede-siga         ###   ########.fr       */
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
	while (str[x])
		x++;
	while (x > 0 && str[x] != '.')
		x--;
	if (!ft_strcmp(str + x, ".xpm"))
		is_xpm = 1;
	if (!is_xpm)
		return (basic_error(elems, node->id, ": not .xpm file.\n", NULL));
	return (elems);
}
