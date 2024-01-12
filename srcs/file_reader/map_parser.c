/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-siga <ede-siga@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 15:58:23 by ede-siga          #+#    #+#             */
/*   Updated: 2024/01/12 16:21:39 by ede-siga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

//check if two coords for player

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
		if (str[i] != '0' && str[i] != '1' && str[i] != ' ')
			elems = coord_check(str[i], elems);
		i++;
	}
	return (elems);
}

t_elems	check_map(t_elems elems, char **map)
{
	unsigned int	i;

	i = 0;
	while (map[i] && elems.error == 0)
	{
		elems = line_checker(map[i], elems);
		i++;
	}
	return (elems);
}


//need to check for path I guess and check if two players
