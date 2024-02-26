/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hesong <hesong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 15:35:19 by hesong            #+#    #+#             */
/*   Updated: 2024/02/26 15:35:21 by hesong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strchr(const char *s, int c)
{
	size_t	i;
	char	ch;

	ch = c;
	i = 0;
	while (s[i])
	{
		if (s[i] == ch)
			return (&((char *)s)[i]);
		i++;
	}
	if (c == '\0')
		return (&(((char *)s)[i]));
	return (0);
}
