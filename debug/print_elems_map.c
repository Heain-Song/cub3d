/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_elems_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hesong <hesong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 18:16:35 by hesong            #+#    #+#             */
/*   Updated: 2024/02/09 18:18:53 by hesong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	print_elems_map(t_elems	*elems)
{
	int i = 0;
	int j = 0;

	while (elems->map[i++])
	{
		j = 0;
		while (elems->map[i][j++])
			printf("%c", elems->map[i][j]);
		printf("\n");
	}
}
