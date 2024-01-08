/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hesong <hesong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 17:35:13 by hesong            #+#    #+#             */
/*   Updated: 2024/01/08 15:15:58 by ede-siga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_file_name(char *file_name)
{
	while (*file_name && *file_name != '.')
		file_name++;
	if (!file_name)
		return (-1);
	if (ft_strcmp(file_name, ".ber"))
		return (-1);
	return (0);
}

/*int	validate_map(char **argv)
{
	if (check_file_name(argv[1]) != 0)

	}*/

int	main(int argc, char **argv)
{
	if (argc == 2)
	{
		if (!check_file_name(argv[1]))
			ft_putstrfd("SUCCESS\n", 2);
		else
			ft_putstrfd("Wrong file xname\n", 2);
	}
	else
		ft_putstrfd("Argc Error. \n", 2);
	return (0);
}
