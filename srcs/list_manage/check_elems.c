/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_elems.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-siga <ede-siga@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 10:10:42 by ede-siga          #+#    #+#             */
/*   Updated: 2024/01/16 21:47:06 by ede-siga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

int	all_textures(t_textures *textures)
{
	while (textures)
	{
		if (!textures->path)
			return (0);
		textures = textures->next;
	}
	return (1);
}

t_elems	check_elems(t_elems elems_list)
{
	if (elems_list.error == 1)
		return (elems_list);
	if (!all_textures(elems_list.textures))
		return (elems_list);
	if (elems_list.did_c == 0 || elems_list.did_f == 0)
		return (elems_list);
	elems_list.is_full = 1;
	return (elems_list);
}
