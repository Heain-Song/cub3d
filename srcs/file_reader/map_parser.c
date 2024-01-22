/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-siga <ede-siga@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 15:58:23 by ede-siga          #+#    #+#             */
/*   Updated: 2024/01/22 23:07:07 by ede-siga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

//check if two coords for player

t_elems	check_single_space(char **str, size_t i, size_t j, t_elems elems)
{
	char	c;

	if (elems.error == 1)
		return (elems);
	c = str[i][j];
	if (is_player(c))
		return (elems);
	if (i == 0 || j == 0)
		return (elems = check_around(c, elems));
	if (ft_strlen(str[i - 1]) < (int) j)
		return (elems = check_around(c, elems));
	if (c == ' ')
	{
		elems = check_around(str[i][j + 1], elems);
		if (j > 0)
			elems = check_around(str[i][j - 1], elems);
		if (i > 0)
			elems = check_around(str[i - 1][j], elems);
		if (str[i + 1] && ft_strlen(str[i + 1]) > (int) j)
			elems = check_around(str[i + 1][j], elems);
	}
	return (elems);
}

t_elems	check_all_spaces(char **str, t_elems elems)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (str[i])
	{
		j = 0;
		while (str[i][j] && str[i][j] != '\n' && elems.error != 1)
		{
			elems = check_single_space(str, i, j, elems);
			j++;
		}
		if (j > 0 && str[i][j - 1] != ' ' && str[i][j - 1] != '1'
			&& !is_player(str[i][j - 1]))
			return (error_reading(NULL, "Map not enclosed by walls\n", elems));
		i++;
	}
	return (elems);
}

t_elems	coord_check(char c, t_elems elems)
{
	if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
		return (elems);
	return (error_reading(NULL, "Invalid char in map\n", elems));
}

t_elems	line_checker(char *str, t_elems elems)
{
	unsigned int	i;

	i = 0;
	while (str[i] && elems.error == 0)
	{
		if (str[i] != '0' && str[i] != '1' && str[i] != ' ' && str[i] != '\n')
			elems = coord_check(str[i], elems);
		i++;
	}
	return (elems);
}

t_elems	check_map(t_elems elems, char **map)
{
	unsigned int	i;

	if (!map || !map[0][0])
		return (basic_error(elems, "Map not found\n", NULL, NULL));
	elems = check_type_in_map(map, elems);
	if (elems.error == 1)
		return (elems);
	i = 0;
	elems = check_all_spaces(map, elems);
	while (map[i] && elems.error == 0)
	{
		elems = line_checker(map[i], elems);
		elems = check_empty_line(map, i, elems);
		i++;
	}
	elems = find_player(map, elems);
	if (elems.found_player == 0 && !elems.error)
		return (basic_error(elems, "Player not found\n", NULL, NULL));
	return (elems);
}
//need to check for path I guess and check if two players
