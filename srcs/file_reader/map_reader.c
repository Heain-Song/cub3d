/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_reader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-siga <ede-siga@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 15:07:21 by ede-siga          #+#    #+#             */
/*   Updated: 2024/01/15 10:49:58 by ede-siga         ###   ########.fr       */
/*                                                                            */
/* **********************************************************************
**** */


#include <cub3d.h>

t_elems	error_reading(char *temp, char *error, t_elems elems)
{
	if (temp)
		free(temp);
	ft_putstrfd("Error\n", 2);
	ft_putstrfd(error, 2);
	elems.error = 1;
	return (elems);
	
}

t_elems	start_reading_map(int fd, t_elems elems)
{
	char	*temp;
	int		read;

	temp = NULL;
	read = 0;
	temp = basic_gnl(fd, &read, 1);
	if (read == 0)
		return (error_reading(temp, "Error\n map not found\n", elems));
	while (!ft_strcmp(temp, "\n"))
	{
		free(temp);
		temp = basic_gnl(fd, &read, 1);
	}
	elems.map = add_to_table(temp, elems.map);
	free(temp);
	read = 1;
	while (read)
	{
		temp = basic_gnl(fd, &read, 1);
		if (temp && (!ft_strcmp(temp, "\n")))
		{
			free(temp);
			return (elems);
		}
		if (temp)
		{
			elems.map = add_to_table(temp, elems.map);
			free(temp);
		}
	}
	return (elems);
//read one line;
	
}
