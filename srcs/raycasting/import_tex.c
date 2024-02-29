/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   import_tex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hesong <hesong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 19:35:16 by hesong            #+#    #+#             */
/*   Updated: 2024/02/29 17:56:33 by hesong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	load_image(t_elems *elems, t_textures *current, int index)
{
	int	w;
	int	h;

	elems->tex[index].img = mlx_xpm_file_to_image(elems->mlx.server,
			current->path, &w, &h);
	if (!elems->tex[index].img)
		return (1);
	elems->tex[index].addr = \
		mlx_get_data_addr((elems->tex[index].img), \
		&(elems->tex[index].bits_per_pixel), \
		&(elems->tex[index].line_length), \
		&(elems->tex[index].endian));
	if (w != 128 || h != 128)
	{
		mlx_destroy_image(elems->mlx.server, elems->tex[index].img);
		return (1);
	}
	return (0);
}

static int	get_cardinal_dir(char *id)
{
	if (!ft_strcmp(id, "NO"))
		return (0);
	else if (!ft_strcmp(id, "SO"))
		return (1);
	else if (!ft_strcmp(id, "WE"))
		return (2);
	else if (!ft_strcmp(id, "EA"))
		return (3);
	return (-1);
}

int	save_texture(t_elems *elems)
{
	int			index;
	t_textures	*current;
	int			cardinal_dir;

	index = 0;
	current = elems->textures;
	while (index < 4)
	{
		cardinal_dir = get_cardinal_dir(current->id);
		if (load_image(elems, current, cardinal_dir) == 1 || cardinal_dir == -1)
		{
			elems->error = 1;
			basic_error(*elems, "texture loading error\n", NULL, NULL);
			return (1);
		}
		current = current->next;
		index++;
	}
	return (0);
}
