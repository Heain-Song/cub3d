/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hesong <hesong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 17:35:13 by hesong            #+#    #+#             */
/*   Updated: 2024/01/08 15:04:39 by ede-siga         ###   ########.fr       */
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
			printf("SUCCESS\n");
		else
			printf("Wrong file xname\n");
	}
	else
		printf("Argc Error. \n");
	return (0);
}
