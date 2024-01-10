/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_textures_list.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-siga <ede-siga@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 10:00:16 by ede-siga          #+#    #+#             */
/*   Updated: 2024/01/10 10:04:39 by ede-siga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	display_textures_list (t_textures *textures)
{
	while (textures)
	{
		ft_putstrfd(textures->id, 1);
		ft_putstrfd(" ", 1);
		ft_putstrfd(textures->path, 1);
		ft_putstrfd("\n", 1);
		textures = textures->next;
	}
}
