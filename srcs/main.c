/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hesong <hesong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 17:35:13 by hesong            #+#    #+#             */
/*   Updated: 2024/01/09 19:41:36 by ede-siga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*int	validate_map(char **argv)
{
	if (check_file_name(argv[1]) != 0)

	}*/

int	main(int argc, char **argv)
{
	int	fd;
	t_textures *textures;
	t_textures *head;
	
	if (argc == 2)
	{
		fd = file_checker(argv[1]);
		textures = make_text_id();
		head = textures;
		textures = element_reader(fd, textures);
		if (!textures)
			return (-1);
		while (textures)
		{
			ft_putstrfd(textures->id, 1);
			ft_putstrfd(" ", 1);
			ft_putstrfd(textures->path, 1);
			ft_putstrfd("\n", 1);
			textures = textures->next;
		}
		close(fd);
		free_t_textures(head);
	}
	else
		ft_putstrfd("Argc Error. \n", 2);
	return (0);
}
