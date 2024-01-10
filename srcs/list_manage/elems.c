/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   elems.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-siga <ede-siga@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 09:51:56 by ede-siga          #+#    #+#             */
/*   Updated: 2024/01/10 09:55:41 by ede-siga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <cub3d.h>

t_elems	init_elems(void)
{
	t_elems	struct_elem;
	int		i;

	i = 0;
	while (i < 3)
	{
		struct_elem.f_colors[i] = 0;
		struct_elem.c_colors[i] = 0;
		i++;
	}
	struct_elem.map = NULL;
	struct_elem.is_full = 0;
	struct_elem.error = 0;
	return (struct_elem);
}
