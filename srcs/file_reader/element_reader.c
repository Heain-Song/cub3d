/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   element_reader.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hesong <hesong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 17:31:13 by ede-siga          #+#    #+#             */
/*   Updated: 2024/02/27 14:07:17 by hesong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

t_textures	*which_elem(t_textures *textures, char *temp)
{
	while (textures)
	{
		if (!ft_strncmp(textures->id, temp, 2))
			return (textures);
		textures = textures->next;
	}
	return (textures);
}

char	*make_path(char *str)
{
	char	*temp;

	if (!str)
		return (NULL);
	while (*str && *str != ' ')
		str++;
	if (!str)
		return (NULL);
	while (*str && *str == ' ')
		str++;
	if (str)
		temp = ft_strdup(str);
	else
		return (NULL);
	return (temp);
}

/*in case of NSWE, get_str_atrib().... except making path, there's no need of this function*/

t_elems	get_str_atrib(t_elems elems, char *str)
{
	t_textures	*node;
	//int			x;
	//int			y;

	node = which_elem(elems.textures, str);
	if (node && node->path)
		return (error_node(node, elems));
	if (node)
	{
		node->path = make_path(str);
		//node->img = mlx_xpm_file_to_image(elems.mlx.server, node->path, &x, &y); // later in load_image();
		//elems = check_textures(elems, node); // later in load_image();
	}
	return (elems);
}

t_elems	get_nbr_atribs(t_elems elems, char *str)
{
	elems = color_checker(elems, str);
	if (elems.error == 1)
		return (elems);
	if (str[0] == 'C' && str[1] == ' ' && elems.did_c == 0)
	{
		str = skip_and_getnb(str, &elems.c_colors[0]);
		str = skip_and_getnb(str, &elems.c_colors[1]);
		str = skip_and_getnb(str, &elems.c_colors[2]);
		elems.did_c = 1;
	}
	if (str[0] == 'F' && str[1] == ' ' && elems.did_f == 0)
	{
		str = skip_and_getnb(str, &elems.f_colors[0]);
		str = skip_and_getnb(str, &elems.f_colors[1]);
		str = skip_and_getnb(str, &elems.f_colors[2]);
		elems.did_f = 1;
	}
	return (elems);
}

t_elems	element_reader(int fd, t_elems elems)
{
	char		*temp;
	int			read_amount;
	int			type;

	if (fd <= 0)
		return (save_error(elems));
	while (!elems.is_full)
	{
		temp = basic_gnl(fd, &read_amount, 0);
		if (temp)
		{
			type = elem_type(temp, elems.elem_names);
			if (type == -1)
				return (basic_error(elems, "invalid info in between elements\n",
						NULL, temp));
			elems = assign_which_elem(temp, type, elems);
			free(temp);
		}
		elems = check_elems(elems);
		if (read_amount <= 0 && !elems.is_full)
			return (error_reading(NULL, "not enough element in file\n",
					elems));
	}
	return (elems);
}
