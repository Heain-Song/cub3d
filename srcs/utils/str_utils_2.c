/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_utils_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hesong <hesong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 14:49:50 by ede-siga          #+#    #+#             */
/*   Updated: 2024/03/01 13:03:59 by ede-siga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	str_check_num_amount(char *str)
{
	int	nb;
	int	auth;

	nb = 0;
	auth = 0;
	while (*str)
	{
		if (*str >= '0' && *str <= '9' && auth == 0)
		{
			auth = 1;
			nb++;
		}
		if (*str == ',')
			auth = 0;
		str++;
	}
	return (nb);
}

char	*skip_and_getnb(char *str, int *nb)
{
	if (!str)
		return (NULL);
	while (*str && (*str < '0' || *str > '9'))
		str++;
	if (*(str - 1) == '-')
		str--;
	*nb = ft_atoi(str);
	if (*str == '-')
		str++;
	if (*str == ' ')
		return (NULL);
	while (*str && (*str >= '0' && *str <= '9'))
		str++;
	return (str);
}

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
	if (dest)
		return (NULL);
	while (str[i])
	{
		dest[i] = str[i];
		i++;
	}
	dest[i] = 0;
	return (dest);
}
