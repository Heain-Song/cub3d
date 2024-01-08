/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_checks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-siga <ede-siga@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 16:02:06 by ede-siga          #+#    #+#             */
/*   Updated: 2024/01/08 16:28:05 by ede-siga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <cub3d.h>
int	file_error(char *str)
{
	ft_putstrfd("Error\n", 2);
	ft_putstrfd(str, 2);
	return (-1);
}

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
		return (file_error("Can't open file\n"));
	return (fd);
}

int	file_checker(char *file)
{
	if (check_file_name(file))
		return (file_error("Wrong file extension\n"));
	return (check_open(file));
}
