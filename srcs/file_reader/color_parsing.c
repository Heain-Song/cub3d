/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hesong <hesong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 22:57:56 by ede-siga          #+#    #+#             */
/*   Updated: 2024/03/01 14:15:03 by ede-siga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_elems	color_checker(t_elems elems, char *str)
{
	if (str_check_num_amount(str) != 3)
	{
		if (str[0] == 'C' && str[1] == ' ' && elems.did_c == 0)
			return (basic_error(elems, "Not enough colors for ",
					"Ceiling\n", NULL));
		if (str[0] == 'F' && str[1] == ' ' && elems.did_c == 0)
			return (basic_error(elems, "Not enough colors for ",
					"Floor\n", NULL));
	}
	if (str[0] == 'C' && str[1] == ' ' && elems.did_c == 1)
		return (error_reading(NULL, "Ceiling already has a color\n", elems));
	if (str[0] == 'F' && str[1] == ' ' && elems.did_f == 1)
		return (error_reading(NULL, "Floor already has a color\n", elems));
	return (elems);
}

t_elems	make_colors_f(t_elems elems, char *str)
{	
	str = skip_and_getnb(str, &elems.f_colors[0]);
	if (*str == ' ')
		return (basic_error(elems, "Spaces in colors\n", NULL, NULL));
	str = skip_and_getnb(str, &elems.f_colors[1]);
	if (*str == ' ')
		return (basic_error(elems, "Spaces in colors\n", NULL, NULL));
	str = skip_and_getnb(str, &elems.f_colors[2]);
	if (*str == ' ')
		return (basic_error(elems, "Spaces in colors\n", NULL, NULL));
	elems.did_f = 1;
	return (elems);
}

t_elems	make_colors_c(t_elems elems, char *str)
{
	str = skip_and_getnb(str, &elems.c_colors[0]);
	if (*str == ' ')
		return (basic_error(elems, "Spaces in colors\n", NULL, NULL));
	str = skip_and_getnb(str, &elems.c_colors[1]);
	if (*str == ' ')
		return (basic_error(elems, "Spaces in colors\n", NULL, NULL));
	str = skip_and_getnb(str, &elems.c_colors[2]);
	if (*str == ' ')
		return (basic_error(elems, "Spaces in colors\n", NULL, NULL));
	elems.did_c = 1;
	return (elems);
}
