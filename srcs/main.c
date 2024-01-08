/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hesong <hesong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 17:35:13 by hesong            #+#    #+#             */
/*   Updated: 2023/12/16 07:53:07 by hesong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_file_name(char *file_name)
{
	int i;

	i = 0;
	while (file_name[i])
	{

	i++;
	}
}


int	validate_map(char **argv)
{
	if (check_file_name(argv[1]) != 0)

}

int main(int argc, char **argv)
{
	if (argc == 2)
	{
		if (validate_map(argv))
			printf("SUCCESS\n");
	}
	else
		printf("Argc Error. \n");
	return (0);
}
