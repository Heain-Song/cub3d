/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hesong <hesong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 17:35:13 by hesong            #+#    #+#             */
/*   Updated: 2024/02/27 14:06:05 by hesong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_elems	file_parsing(char *file)
{
	t_elems	elems;
	int		fd;

	elems = init_elems();
	//elems = init_mlx(elems); // moving to raycasting
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
		if (elems.error == 0)
		{
			printf("----------------------------\n"); //debug
			display_textures_list (elems.textures); //debug
			printf("----------------------------\n");//debug
			print_map(elems.map); //debug
			printf("----------------------------\n");//debug
			elems.map_file = argv[1];
			elems = raycast(elems);
			ft_putstrfd("\033[0;32mGood\n\033[0m", 1);
		}
		free_elems(elems);
		clean_mlx(elems.mlx);
	}
	else
		ft_putstrfd("Error\n: Need a map file.\n", 2);
	return (0);
}
