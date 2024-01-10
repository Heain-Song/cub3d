/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   element_reader.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-siga <ede-siga@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 17:31:13 by ede-siga          #+#    #+#             */
/*   Updated: 2024/01/10 18:30:27 by ede-siga         ###   ########.fr       */
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

t_elems	gt_str_atrib(t_elems elems, char *str)
{
	t_textures	*node;

	node = which_elem(elems.textures, temp);
	if (node && node->path)
		return (error_node(node, elems.textures, temp));
	if (node)
		node->path = make_path(temp);
	return (elems);
}

t_elems	get_nbr_atribs(t_elems elems, char *str)
{
	int	r;
	int	g;
	int	b;

	while (*str < '0' || *str > '9')
		str++;
	r = ft_atoi(str);
	while (*str >= '0' && *str <= '9')
		str++;
	while (*str < '0' || *str > '9')
		str++;
	g = ft_atoi(str);
	
}

t_textures	*element_reader(int fd, t_elems elems)
{
	int			i;
	char		*temp;
	t_textures	*node;

	int	test;

	if (fd <= 0)
		return (NULL);
	i = 0;
	//while (!elems.is_full)// to change
	while (i < 6)
	{
		temp = basic_gnl(fd);
		if (temp)
		{
			test =  elem_type(temp, elems.elem_names);
			if (test >= 0)
				printf("elem name = %s\n", elems.elem_names[test]);
/*			node = which_elem(elems.textures, temp);
			if (node && node->path)
				return (error_node(node, elems.textures, temp));
			if (node)
				node->path = make_path(temp);
			free(temp);
*/
			elems = check_elems(elems);
			i++;
		}
	}
	return (elems.textures);
}
