/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   import_tex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hesong <hesong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 19:35:16 by hesong            #+#    #+#             */
/*   Updated: 2024/02/29 12:15:51 by hesong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	load_image(t_elems *elems, char *line, int index)
{
	int	w;
	int	h;

	elems->tex[index].img = mlx_xpm_file_to_image(elems->mlx.server,
			ft_strchr(line, ' ') + 1, &w, &h);
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

int	save_texture(t_elems *elems)
{
	int		index;
	char	*line;
	int		fd;
	int		read;

	index = 0;
	read = 1;
	fd = open(elems->map_file, O_RDONLY);
	line = basic_gnl(fd, &read, 0);
	index = 0;
	while (line && index < 4)
	{
		if (load_image(elems, line, index) || elems->tex[index].img == NULL)
		{
			elems->loaded_textures = index;
			elems->error = 1;
			return (1);
		}
		free(line);
		line = basic_gnl(fd, &read, 0);
		index++;
	}
	elems->loaded_textures = index;
	line = basic_gnl(fd, &read, 0);
	while (line)
	{
		free(line);
		line = basic_gnl(fd, &read, 0);
	}
	return (0);
}
