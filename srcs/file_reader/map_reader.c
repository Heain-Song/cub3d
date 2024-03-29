/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_reader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hesong <hesong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 15:07:21 by ede-siga          #+#    #+#             */
/*   Updated: 2024/02/27 00:01:49 by hesong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_elems	error_reading(char *temp, char *error, t_elems elems)
{
	if (elems.error == 1)
		return (elems);
	if (temp)
		free(temp);
	ft_putstrfd("Error\n", 2);
	ft_putstrfd(error, 2);
	elems.error = 1;
	return (elems);
}

char	*skip_to_map(int fd)
{
	char	*temp;
	int		read;

	temp = ft_strdup("\n");
	read = 1;
	while (!ft_strcmp(temp, "\n") && read > 0)
	{
		free(temp);
		temp = basic_gnl(fd, &read, 1);
	}
	return (temp);
}

t_elems	start_reading_map(int fd, t_elems elems)
{
	char	*temp;
	int		read;

	temp = skip_to_map(fd);
	if (temp == NULL)
		return (error_reading(temp, "Map not found.\n", elems));
	elems.map = add_to_table(temp, elems.map);
	free(temp);
	read = 1;
	while (read)
	{
		temp = basic_gnl(fd, &read, 1);
		if (temp)
		{
			elems.map = add_to_table(temp, elems.map);
			free(temp);
		}
	}
	return (elems);
}
