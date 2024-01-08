/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-siga <ede-siga@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 14:49:50 by ede-siga          #+#    #+#             */
/*   Updated: 2024/01/08 15:19:57 by ede-siga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <cub3d.h>

int	ft_strcmp(const char *s1, const char *s2)
{
	unsigned int	i;
	unsigned char	*cs1;
	unsigned char	*cs2;

	i = 0;
	cs1 = (unsigned char *)s1;
	cs2 = (unsigned char *)s2;
	while (cs1[i] == cs2[i] && cs1[i] != '\0' && cs2[i] != '\0')
		i++;
	return (cs1[i] - cs2[i]);
}

void	ft_putstrfd(char *str, int fd)
{
	while (*str)
		write(fd, str++, 1);
}
