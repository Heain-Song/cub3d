/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   element_reader.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-siga <ede-siga@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 17:31:13 by ede-siga          #+#    #+#             */
/*   Updated: 2024/01/10 10:18:57 by ede-siga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

t_textures	*error_node(t_textures *node, t_textures *head, char *temp)
{
	ft_putstrfd("Error\n", 2);
	ft_putstrfd(node->id, 2);
	ft_putstrfd(" has two textures\n", 2);
	free_t_textures(head);
	free(temp);
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

t_textures	*element_reader(int fd, t_elems elems)
{
	int			i;
	char		*temp;
	t_textures	*node;

	if (fd <= 0)
		return (NULL);
	i = 0;
	while (!elems.is_full) // to change
	{
		temp = basic_gnl(fd);
		if (temp)
		{
			node = which_elem(elems.textures, temp);
			if (node->path)
				return (error_node(node, elems.textures, temp));
			if (!node)
				return (elems.textures);
			node->path = make_path(temp);
			free(temp);
			elems = check_elems(elems);
			i++;
		}
	}
	return (elems.textures);
}
