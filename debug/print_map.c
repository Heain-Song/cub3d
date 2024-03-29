/* **********************************************************************65;6800;1c**** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-siga <ede-siga@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 15:31:20 by ede-siga          #+#    #+#             */
/*   Updated: 2024/01/15 10:26:49 by ede-siga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	print_map(char **map)
{
	unsigned int	i = 0;

	if (!map)
		return;
	while (map[i])
		printf("%s", map[i++]);
}
