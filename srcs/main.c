/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hesong <hesong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 17:35:13 by hesong            #+#    #+#             */
/*   Updated: 2024/01/17 11:34:59 by ede-siga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_elems	file_parsing(char *file)
{
	t_elems	elems;
	int		fd;

	elems = init_elems();
	fd = file_checker(file);
	if (fd < 0)
		return (save_error(elems));
	elems.textures = make_text_id();
	elems = element_reader(fd, elems);
	elems = start_reading_map(fd, elems);
	if (!elems.textures)
		return (save_error(elems));
	elems = check_map(elems, elems.map);
	close(fd);
	return (elems);
}

int	main(int argc, char **argv)
{
	t_elems	elems;

	if (argc == 2)
	{
		elems = file_parsing(argv[1]);
		//debug checking 
		loop_debug(elems);
		//end debug
		free_elems(elems);
	}
	else
		ft_putstrfd("Error need a map file\n", 2);
	return (0);
}
