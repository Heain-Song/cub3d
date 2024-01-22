/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-siga <ede-siga@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 09:42:09 by ede-siga          #+#    #+#             */
/*   Updated: 2024/01/22 16:05:34 by ede-siga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

t_elems	check_textures(t_elems elems, char *str)
{
	void	*check_image;
	int		x;
	int		y;

	check_image = mlx_xpm_file_to_image(elems.mlx_l.server, str, &x, &y);
	if (!check_image)
		return(basic_error(elems, str," : invalid xpm\n", NULL));
	return (elems);
}
