/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   element_reader.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-siga <ede-siga@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 17:31:13 by ede-siga          #+#    #+#             */
/*   Updated: 2024/01/11 10:06:16 by ede-siga         ###   ########.fr       */
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

	node = which_elem(elems.textures, str);
	if (node && node->path)
		return (error_node(node, elems, str));
	if (node)
		node->path = make_path(str);
	return (elems);
}

t_elems	get_nbr_atribs(t_elems elems, char *str)
{
	int	r;
	int	g;
	int	b;
	int	i;

	i = 0;
	if (str[0] == 'C')
		i = 1;
	if (str[0] == 'F')
		i = 2;
	//can be made into a skip to next number func
	while (*str < '0' || *str > '9')
		str++;
	r = ft_atoi(str);
	while (*str >= '0' && *str <= '9')
		str++;
	while (*str < '0' || *str > '9')
		str++;
	g = ft_atoi(str);
	 while (*str >= '0' && *str <= '9')
		 str++;
	 while (*str < '0' || *str > '9')
		 str++;
	 b = ft_atoi(str);
	 if (i == 2)
	 {
		 elems.f_colors[0] = r;
		 elems.f_colors[1] = g;
		 elems.f_colors[2] = b;
		 elems.did_f = 1;
	 }
	 else
	 {
		 elems.c_colors[0] = r;
		 elems.c_colors[1] = g;
		 elems.c_colors[2] = b;
		 elems.did_c = 1;
	 }
	 return (elems);
}

t_elems	element_reader(int fd, t_elems elems)
{
	int			i;
	char		*temp;
	//t_textures	*node;

	int	test;

	if (fd <= 0)
	{
		elems.error = 1;
		return (elems);
	}
	i = 0;
	//while (!elems.is_full)// to change
	while (!elems.is_full)
	{
		temp = basic_gnl(fd);
		if (temp)
		{
			test =  elem_type(temp, elems.elem_names);
			if (test >= 0)
				printf("elem name = %s\n", elems.elem_names[test]);
			elems = assign_which_elem(temp, test, elems);
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
	return (elems);
}
