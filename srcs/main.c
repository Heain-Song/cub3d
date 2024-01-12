/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hesong <hesong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 17:35:13 by hesong            #+#    #+#             */
/*   Updated: 2024/01/12 15:35:36 by ede-siga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*int	validate_map(char **argv)
{
	if (check_file_name(argv[1]) != 0)

	}*/

int	main(int argc, char **argv)
{
	int		fd;
	t_elems	elem_list;
//	t_textures	*textures;

	if (argc == 2)
	{
		elem_list = init_elems();
		fd = file_checker(argv[1]);
		elem_list.textures = make_text_id();
		elem_list = element_reader(fd, elem_list);
		elem_list = start_reading_map(fd, elem_list);
		if (!elem_list.textures)
			return (-1);
		display_textures_list(elem_list.textures); //debug function
		printf("c_color = r%d,g%d,b%d\n", elem_list.c_colors[0], elem_list.c_colors[1], elem_list.c_colors[2]);
		printf("f_color = r%d,g%d,b%d\n", elem_list.f_colors[0], elem_list.f_colors[1], elem_list.f_colors[2]);
		print_map(elem_list.map);
		close(fd);
		free_elems(elem_list); 
	}
	else
		ft_putstrfd("Error need a map file\n", 2);
	return (0);
}
