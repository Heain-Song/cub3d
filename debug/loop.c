/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-siga <ede-siga@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 11:24:59 by ede-siga          #+#    #+#             */
/*   Updated: 2024/01/17 11:29:27 by ede-siga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	loop_debug(t_elems elems)
{
	display_textures_list(elems.textures);
	printf("c_color = r%d,g%d,b%d\n", elems.c_colors[0], elems.c_colors[1], elems.c_colors[2]);
	printf("f_color = r%d,g%d,b%d\n", elems.f_colors[0], elems.f_colors[1], elems.f_colors[2]);
	print_map(elems.map);
}
