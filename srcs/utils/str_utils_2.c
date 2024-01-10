/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-siga <ede-siga@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 14:49:50 by ede-siga          #+#    #+#             */
/*   Updated: 2024/01/10 09:41:10 by ede-siga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <cub3d.h>

int	ft_strncmp(const char *s1, const char *s2, unsigned int n)
{
	unsigned int	i;
	unsigned char	*cs1;
	unsigned char	*cs2;

	i = 0;
	cs1 = (unsigned char *)s1;
	cs2 = (unsigned char *)s2;
	while (cs1[i] == cs2[i] && cs1[i] != '\0' && cs2[i] != '\0' && i < n - 1)
		i++;
	return (cs1[i] - cs2[i]);
}

char	*ft_strdup(char *str)
{
	size_t	size;
	size_t	i;
	char	*dest;

	i = 0;
	size = ft_strlen(str);
	dest = malloc(sizeof(char) * size + 1);
	while (str[i])
	{
		dest[i] = str[i];
		i++;
	}
	dest[i] = 0;
	return (dest);
}
