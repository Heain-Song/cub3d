/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-siga <ede-siga@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 15:58:23 by ede-siga          #+#    #+#             */
/*   Updated: 2024/01/15 10:50:57 by ede-siga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

//check if two coords for player

t_elems	check_spaces(char **str, t_elems elems)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	while (str[i])
	{
		while (str[i][j] && str[i][j] == ' ')
			j++;
		if (str[i][0] != '\n')
		{
			if (str[i][j] != '1')
			{
				printf("fucked up line = %s\ni value = %d", str[i], i);
				elems.error = 1;
			}
		}
		i++;
		j = 0;
	}
	if (elems.error == 1)
		ft_putstrfd("Error\nMap not enclosed by walls\n", 2);
	return (elems);
}

t_elems	coord_check(char c, t_elems elems)
{
	if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
	{
		if (elems.found_player == 1)
		{
			ft_putstrfd("Error\n multiple staring positions\n", 2);
			elems.error = 1;
		}
		elems.found_player = 1;
		return (elems);
	}
	ft_putstrfd("Error\nInvalid char in map", 2);
	elems.error = 1;
	return (elems);
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

	if (elems.error == 1)
		return (elems);
	i = 0;
	elems = check_spaces(map, elems);
	while (map[i] && elems.error == 0)
	{
		elems = line_checker(map[i], elems);
		i++;
	}
	return (elems);
}


//need to check for path I guess and check if two players
