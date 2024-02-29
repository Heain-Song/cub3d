/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   elems.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hesong <hesong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 09:51:56 by ede-siga          #+#    #+#             */
/*   Updated: 2024/02/29 19:22:58 by ede-siga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_elems	make_names(t_elems struct_elem)
{
	struct_elem.elem_names = malloc(sizeof(char *) * 7);
	if (!struct_elem.elem_names)
	{
		struct_elem.error = 1;
		return (struct_elem);
	}
	struct_elem.textures = NULL;
	struct_elem.elem_names[0] = ft_strdup("NO ");
	struct_elem.elem_names[1] = ft_strdup("SO ");
	struct_elem.elem_names[2] = ft_strdup("WE ");
	struct_elem.elem_names[3] = ft_strdup("EA ");
	struct_elem.elem_names[4] = ft_strdup("C ");
	struct_elem.elem_names[5] = ft_strdup("F ");
	struct_elem.elem_names[6] = NULL;
	struct_elem.did_c = 0;
	struct_elem.did_f = 0;
	struct_elem.map = NULL;
	struct_elem.found_player = 0;
	return (struct_elem);
}

void	free_elems(t_elems elems)
{
	int		i;
	t_elems	*server;

	server = elems.mlx.server;
	i = 0;
	while (i < elems.loaded_textures + 1)
	{
		if (elems.tex[i].img)
			mlx_destroy_image(server, elems.tex[i].img);
		i++;
	}
	i = 0;
	while (elems.elem_names[i])
		free(elems.elem_names[i++]);
	free(elems.elem_names);
	i = 0;
	if (elems.map)
	{
		while (elems.map[i])
			free(elems.map[i++]);
		free(elems.map);
	}
	free_t_textures(elems.textures, elems);
}

t_elems	init_elems(void)
{
	t_elems	struct_elem;
	int		i;

	i = 0;
	while (i < 3)
	{
		struct_elem.f_colors[i] = -1;
		struct_elem.c_colors[i] = -1;
		i++;
	}
	struct_elem.map = NULL;
	struct_elem.is_full = 0;
	struct_elem.error = 0;
	struct_elem = make_names(struct_elem);
	return (struct_elem);
}
