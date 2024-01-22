/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-siga <ede-siga@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 21:48:30 by ede-siga          #+#    #+#             */
/*   Updated: 2024/01/22 11:20:22 by ede-siga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

int	is_player(char c)
{
	if (c == 'W' || c == 'S' || c == 'N' || c == 'E')
		return (1);
	return (0);
}

t_elems check_around_player(size_t i, size_t j, char **map, t_elems elems)
{
	int	j_int;

	j_int = j;
	if (elems.found_player == 1)
		return(basic_error(elems, "Multiple players found\n", NULL, NULL));
	if (i == 0)
		return(basic_error(elems, "Invalid starting position\n", NULL, NULL));
	if (!map[i + 1] || j_int > ft_strlen(map[i]))
		return(basic_error(elems, "Invalid starting position\n", NULL, NULL));
	if (map[i][j + 1] != '0' && map[i][j + 1] != '1' && !is_player(map[i][j + 1]))
		return(basic_error(elems, "Invalid starting position\n", NULL, NULL));
	if (map[i][j - 1] != '0' && map[i][j - 1] != '1' && !is_player(map[i][j - 1]))
		return(basic_error(elems, "Invalid starting position\n", NULL, NULL));
	if (map[i + 1][j] != '0' && map[i + 1][j] != '1' && !is_player(map[i + 1][j]))
		return(basic_error(elems, "Invalid starting position\n", NULL, NULL));
	if (map[i - 1][j] != '0' && map[i - 1][j] != '1' && !is_player(map[i - 1][j]))
		return(basic_error(elems, "Invalid starting position\n", NULL, NULL));
	elems.found_player = 1;
	return (elems);	
}
t_elems	find_player(char **map, t_elems elems)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (map[i] && elems.error == 0)
	{
		j = 0;
		while (map[i][j] && elems.error == 0)
		{
			if (is_player(map[i][j]))
				elems = check_around_player(i, j, map, elems);
			j++;
		}
		i++;
	}
	return (elems);
}

t_elems	check_around(char d, t_elems elems)
{
	if (d && d != ' ' && d != '1' && d != '\n')
		elems.error = 1;
	return (elems);
}
