/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2d_add.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hesong <hesong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 14:40:18 by ede-siga          #+#    #+#             */
/*   Updated: 2024/02/17 22:37:29 by hesong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

char	**init_table(char *str, char **table)
{
	table = malloc(sizeof(char *) * 2);
	if (!table)
		return (NULL);
	table[0] = ft_strdup(str);
	if (!table[0])
		return (NULL);
	table[1] = NULL;
	return (table);
}

char	**add_to_table(char *str, char **table)
{
	char	**temp;
	size_t	i;

	if (!table)
		return (init_table(str, table));
	i = 0;
	while (table[i])
		i++;
	temp = malloc(sizeof(char *) * (i + 2));
	i = 0;
	while (table[i])
	{
		temp[i] = ft_strdup(table[i]);
		if (!temp[i])
			return (NULL);
		free(table[i]);
		i++;
	}
	free(table);
	temp[i] = ft_strdup(str);
	temp[i + 1] = NULL;
	return (temp);
}
