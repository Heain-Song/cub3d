/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_in_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-siga <ede-siga@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 22:31:18 by ede-siga          #+#    #+#             */
/*   Updated: 2024/01/22 22:46:39 by ede-siga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <cub3d.h>

t_elems	check_type_in_map(char **str, t_elems elems)
{
	int	type;
	int	i;

	if (elems.error == 1)
		return (elems);
	i = 0;
	while (str[i])
	{
		type = elem_type(str[i], elems.elem_names);
		if (type != -1)
			return (basic_error(elems, elems.elem_names[type],
					": appears twice\n", NULL));
		i++;
	}
	return (elems);
}
