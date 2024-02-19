/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hesong <hesong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 21:48:30 by ede-siga          #+#    #+#             */
/*   Updated: 2024/02/19 10:43:26 by hesong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

int	is_player(char c, t_elems elems)
{
	(void)elems;
	if (c == 'W' || c == 'S' || c == 'N' || c == 'E')
	{
		if (c == 'W')
			elems.player_dir = 'W';
		else if (c == 'S')
			elems.player_dir = 'S';
		else if (c == 'N')
			elems.player_dir = 'N';
		else
			elems.player_dir = 'E';
		return (1);
	}
	else
		return (0);
}

t_elems	check_around_player(size_t i, size_t j, char **map, t_elems elems)
{
	int	j_int;

	j_int = j;
	if (elems.found_player == 1)
		return (error_reading(NULL, "Multiple player found\n", elems));
	if (i == 0)
		return (error_player(elems));
	if (!map[i + 1] || j_int > ft_strlen(map[i]))
		return (error_player(elems));
	if (map[i][j + 1] != '0' && map[i][j + 1] != '1' &&
		!is_player(map[i][j + 1], elems))
		return (error_player(elems));
	if (map[i][j - 1] != '0' && map[i][j - 1] != '1' &&
		!is_player(map[i][j - 1], elems))
		return (error_player(elems));
	if (map[i + 1][j] != '0' && map[i + 1][j] != '1' &&
		!is_player(map[i + 1][j], elems))
		return (error_player(elems));
	if (map[i - 1][j] != '0' && map[i - 1][j] != '1' &&
		!is_player(map[i - 1][j], elems))
		return (error_player(elems));
	elems.found_player = 1;
	elems.player_x = j;
	elems.player_y = i;
	return (elems);
}

t_elems	find_player(char **map, t_elems elems)
{
	size_t	i;
	size_t	j;

	if (elems.error == 1)
		return (elems);
	i = 0;
	while (map[i] && elems.error == 0)
	{
		j = 0;
		while (map[i][j] && elems.error == 0)
		{
			if (is_player(map[i][j], elems))
				elems = check_around_player(i, j, map, elems);
			j++;
		}
		i++;
	}
	return (elems);
}

t_elems	check_empty_line(char **map, size_t i, t_elems elems)
{
	if (map[i][0] == '\n')
	{
		while (map[i] && map[i][0] == '\n')
			i++;
		if (map[i] && map[i][0])
			return (error_reading(NULL, "Empty line in map\n", elems));
		return (elems);
	}
	return (elems);
}

t_elems	check_around(char d, t_elems elems)
{
	if (elems.error == 0)
	{
		if (d && d != ' ' && d != '1' && d != '\n')
			return (error_reading(NULL, "Map not enclosed by walls\n", elems));
	}
	return (elems);
}
