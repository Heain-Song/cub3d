/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hesong <hesong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 17:35:13 by hesong            #+#    #+#             */
/*   Updated: 2024/02/08 21:13:26 by hesong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_elems	file_parsing(char *file)
{
	t_elems	elems;
	int		fd;

	elems = init_elems();
	elems = init_mlx(elems);
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
			display_textures_list (elems.textures); //debug
			print_map(elems.map); //debug
			//elems = start_window_loop(elems);
			elems = start_raycasting(elems);
			ft_putstrfd("\033[0;32mGood\n\033[0m", 1);
		}
		clean_mlx(elems.mlx);
		free_elems(elems);
	}
	else
		ft_putstrfd("Error\n: Need a map file.\n", 2);
	return (0);
}
