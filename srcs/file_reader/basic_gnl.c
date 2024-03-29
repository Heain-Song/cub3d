/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_gnl.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hesong <hesong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 14:02:02 by ede-siga          #+#    #+#             */
/*   Updated: 2024/02/26 23:22:32 by hesong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

char	*initiate_dest(char *dest, char c)
{
	dest = malloc(sizeof(char) * 2);
	if (!dest)
		return (NULL);
	dest[0] = c;
	dest[1] = 0;
	return (dest);
}

char	*add_char_to_str(char *dest, char c)
{
	size_t	size;
	char	*temp;

	if (!dest)
		return (dest = initiate_dest(dest, c));
	size = ft_strlen(dest);
	temp = malloc(sizeof(char) * size + 2);
	temp = ft_strcpy(dest, temp);
	temp[size] = c;
	temp[size + 1] = 0;
	free(dest);
	return (temp);
}

char	*basic_gnl(int fd, int *read_amount, int keep_nl)
{
	char	c;
	char	*str;

	c = 0;
	str = NULL;
	if (fd <= 0)
		return (NULL);
	*read_amount = 1;
	while (*read_amount == 1 && c != '\n')
	{
		*read_amount = read(fd, &c, 1);
		if (*read_amount > 0 && c != '\n')
			str = add_char_to_str(str, c);
	}
	if (keep_nl == 1)
		str = add_char_to_str(str, c);
	if (!str)
		return (NULL);
	return (str);
}
