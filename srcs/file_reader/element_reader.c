/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   element_reader.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-siga <ede-siga@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 17:31:13 by ede-siga          #+#    #+#             */
/*   Updated: 2024/01/22 08:45:39 by ede-siga         ###   ########.fr       */
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

t_elems	get_str_atrib(t_elems elems, char *str)
{
	t_textures	*node;

	node = which_elem(elems.textures, str);
	if (node && node->path)
		return (error_node(node, elems, str));
	if (node)
		node->path = make_path(str);
	return (elems);
}

t_elems	get_nbr_atribs(t_elems elems, char *str)
{
	if (str_check_num_ammount(str) != 3)
	{
		if (str[0] == 'C' && elems.did_c == 0)
			return (basic_error(elems, "Not enough colors for ",
					"Ceiling\n", NULL));
		if (str[0] == 'F' && elems.did_c == 0)
			return (basic_error(elems, "Not enough colors for ",
					"Floor\n", NULL));
	}
	if (str[0] == 'C' && elems.did_c == 0)
	{
		str = skip_and_getnb(str, &elems.c_colors[0]);
		str = skip_and_getnb(str, &elems.c_colors[1]);
		str = skip_and_getnb(str, &elems.c_colors[2]);
		elems.did_c = 1;
	}
	if (str[0] == 'F' && elems.did_f == 0)
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
	int			read_ammount;
	int			type;
	int			i;

	if (fd <= 0)
		return (save_error(elems));
	while (!elems.is_full)
	{
		temp = basic_gnl(fd, &read_ammount, 0);
		if (temp)
		{
			i = 0;
				while (temp[i] == ' ')
					i++;
			type = elem_type(temp + i, elems.elem_names);
			if (type == -1)
				return (basic_error(elems, "invalid info in between elements\n",
						NULL, temp));
			elems = assign_which_elem(temp + i, type, elems);
			free(temp);
		}
		elems = check_elems(elems);
		if (read_ammount <= 0 && !elems.is_full)
			return (basic_error(elems, "Error\n not enough element in file",
					NULL, NULL));
	}
	return (elems);
}
