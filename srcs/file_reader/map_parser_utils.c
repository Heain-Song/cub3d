/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-siga <ede-siga@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 21:48:30 by ede-siga          #+#    #+#             */
/*   Updated: 2024/01/16 21:48:53 by ede-siga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

t_elems	check_around(char d, t_elems elems)
{
	if (d != ' ' && d != '1' && d != '\n' && d)
		elems.error = 1;
	return (elems);
}
