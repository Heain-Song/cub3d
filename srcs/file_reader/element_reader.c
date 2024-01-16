/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   element_reader.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-siga <ede-siga@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 17:31:13 by ede-siga          #+#    #+#             */
/*   Updated: 2024/01/16 17:25:57 by ede-siga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

t_elems	error_node(t_textures *node, t_elems elems, char *temp)
{
	elems.error = 1;
	ft_putstrfd("Error\n", 2);
	ft_putstrfd(node->id, 2);
	ft_putstrfd(" has two textures\n", 2);
	free_t_textures(elems.textures);
	free(temp);
	return (elems);
}

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

	while (str && *str != ' ')
		str++;
	if (!str)
		return (NULL);
	while (str && *str == ' ')
		str++;
	if (str)
		temp = ft_strdup(str);
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
		ft_putstrfd("Error\nNot enough colors for ", 2);
		if (str[0] == 'C')
			ft_putstrfd("Ceiling\n", 2);
		else
			ft_putstrfd("Floor\n", 2);
		elems.error = 1;
		return (elems);
	}
	if (str[0] == 'C')
	{
		str = skip_and_getnb(str, &elems.c_colors[0]);
		str = skip_and_getnb(str, &elems.c_colors[1]);
		str = skip_and_getnb(str, &elems.c_colors[2]);
		elems.did_c = 1;
	}
	if (str[0] == 'F')
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

	if (fd <= 0)
	{
		elems.error = 1;
		return (elems);
	}
	while (!elems.is_full)
	{
		temp = basic_gnl(fd, &read_ammount, 0);
		if (temp)
		{
			type = elem_type(temp, elems.elem_names);
			if (type == -1)
			{
				free(temp);
				ft_putstrfd("Error\n invalid info in between elements\n", 2);
				elems.error = 1;
				return (elems);
			}
			elems = assign_which_elem(temp, type, elems);
			free(temp);
		}
		if (elems.error)
			return (elems);
		elems = check_elems(elems);
		if (read_ammount <= 0 && !elems.is_full)
		{
			ft_putstrfd("Error\n not enough element in file", 2);
			elems.error = 1;
			return (elems);
		}
	}
	return (elems);
}
