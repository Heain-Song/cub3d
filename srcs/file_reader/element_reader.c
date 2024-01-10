/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   element_reader.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-siga <ede-siga@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 17:31:13 by ede-siga          #+#    #+#             */
/*   Updated: 2024/01/10 09:35:55 by ede-siga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

t_textures	*error_node(t_textures *node)
{
	ft_putstrfd("Error\n", 2);
	ft_putstrfd(node->id, 2);
	ft_putstrfd(" has two textures\n", 2);
	return (NULL);
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
	//element not found?
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

t_textures	*element_reader(int fd, t_textures *textures)
{
	int			i;
	char		*temp;
	t_textures	*node;

	if (fd <= 0)
		return (NULL);
	i = 0;
	while (i < 4) // to change
	{
		temp = basic_gnl(fd);
		if (temp)
		{
			node = which_elem(textures, temp);
			if (node->path)
				return (error_node(node));
			if (!node)
				return (textures);
			node->path = make_path(temp);
			free(temp);
			i++;
		}
	}
	return (textures);
}
