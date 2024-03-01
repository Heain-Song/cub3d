/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser_utils_2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-siga <ede-siga@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 15:02:58 by ede-siga          #+#    #+#             */
/*   Updated: 2024/03/01 15:07:13 by ede-siga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <cub3d.h>

t_elems	check_all_chars(t_elems elems, char **map)
{
	int	y;
	int	x;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] != '0' && map[y][x] != '1' && map[y][x] != ' '
				&& map[y][x] != '\n')
			{
				if (!is_player(map[y][x]))
					return (basic_error(elems,
							"Map invalid format\n", NULL, NULL));
			}
			x++;
		}
		y++;
	}
	return (elems);
}
