/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_checks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-siga <ede-siga@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 16:02:06 by ede-siga          #+#    #+#             */
/*   Updated: 2024/01/08 16:17:52 by ede-siga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <cub3d.h>

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

int	check_open(char *file)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd <= 0)
		ft_putstrfd("Can't open file\n", 2);
	return (fd);
}

int	file_checker(char *file)
{
	if (check_file_name(file))
	{
		ft_putstrfd("Wrong file extension\n", 2);
		return (-1);
	}
	return (check_open(file));
}
