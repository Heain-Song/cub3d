/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_reader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-siga <ede-siga@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 15:07:21 by ede-siga          #+#    #+#             */
/*   Updated: 2024/01/12 15:37:59 by ede-siga         ###   ########.fr       */
/*                                                                            */
/* **********************************************************************
**** */


#include <cub3d.h>

t_elems	start_reading_map(int fd, t_elems elems)
{
	char	*temp;
	int		read_ammount;

	read_ammount = 0;
	temp = basic_gnl(fd, &read_ammount);
	if (read_ammount == 0)
	{
		ft_putstrfd("Error\n map not found\n", 2);
		elems.error = 1;
		return (elems);
	}
	if (temp && read_ammount != 1)
	{
		free(temp);
		elems.error = 1;
		ft_putstrfd("Error\nMap should be serparated by a \\n\n", 2);
		return (elems);
	}
	free(temp);
	temp = basic_gnl(fd, &read_ammount);
	//printf("read = %d\n", read_ammount);
	if (!temp) //needs to check if there is a map
	{
		if (temp)
			free(temp);
		elems.error = 1;
		ft_putstrfd("Error\nMap separated by multiple \\n\n", 2);
		return(elems);
	}
	read_ammount = 1;
	while (read_ammount)
	{
		temp = basic_gnl(fd, &read_ammount);
		if (temp)
		{
			elems.map = add_to_table(temp, elems.map);
			free(temp);
		}
	}
	return (elems);
	//read one line;
	
}
