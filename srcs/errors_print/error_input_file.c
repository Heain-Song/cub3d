/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_node.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-siga <ede-siga@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 21:24:27 by ede-siga          #+#    #+#             */
/*   Updated: 2024/01/22 22:10:14 by ede-siga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

t_elems	save_error(t_elems elems)
{
	elems.error = 1;
	return (elems);
}

t_elems	error_node(t_textures *node, t_elems elems)
{
	if (elems.error == 1)
		return (elems);
	ft_putstrfd("Error\n", 2);
	ft_putstrfd(node->id, 2);
	ft_putstrfd(" has two textures\n", 2);
	return (save_error(elems));
}

t_elems	basic_error(t_elems elems, char *error, char *attrib, char *to_free)
{
	if (to_free)
		free(to_free);
	if (elems.error == 1)
		return (elems);
	ft_putstrfd("Error\n", 2);
	ft_putstrfd(error, 2);
	if (attrib)
		ft_putstrfd(attrib, 2);
	return (save_error(elems));
}

t_elems	error_player(t_elems elems)
{
	return (basic_error(elems, "Invalid player position\n", NULL, NULL));
}
