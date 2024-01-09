/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_gnl.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-siga <ede-siga@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 14:02:02 by ede-siga          #+#    #+#             */
/*   Updated: 2024/01/09 18:45:43 by ede-siga         ###   ########.fr       */
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

char	*basic_gnl(int fd)
{
	char	c;
	char	*str;

	c = 0;
	str = NULL;
	if (fd <= 0)
		return (NULL);
	while (read(fd, &c, 1) && c != '\n')
		str = add_char_to_str(str, c);
	if (!str)
		return (NULL);
	return (str);
}
