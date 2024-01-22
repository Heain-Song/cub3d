/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   element_chose.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-siga <ede-siga@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 12:12:20 by ede-siga          #+#    #+#             */
/*   Updated: 2024/01/22 12:34:32 by ede-siga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

t_elems	check_colors(t_elems elems, int type, int color[3])
{
	int	i;

	i = 0;
	while (i < 3)
	{
		if (color[i] > 255 || color[i] < 0)
		{
			ft_putstrfd("Error\n", 2);
			if (type == 4)
				ft_putstrfd("Ceiling ", 2);
			else
				ft_putstrfd("Floor ", 2);
			ft_putstrfd("color is not between 0 and 255\n", 2);
			elems.error = 1;
		}
		i++;
	}
	return (elems);
}

t_elems	assign_which_elem(char *str, int nb, t_elems elems)
{
	while (*str && *str == ' ')
		str++;
	if (nb < 4)
		elems = get_str_atrib(elems, str);
	else
	{
		elems = get_nbr_atribs(elems, str);
		if (elems.error == 1)
			return (elems);
		if (nb == 4)
			elems = check_colors(elems, 4, elems.c_colors);
		else
			elems = check_colors(elems, 5, elems.f_colors);
	}
	return (elems);
}

int	elem_type(char *temp, char **str)
{
	int	i;
	int	length;

	length = 3;
	i = 0;
	while (*temp && *temp == ' ')
		temp++;
	while (str[i])
	{
		if (!ft_strncmp(str[i], temp, length))
			return (i);
		i++;
		if (i == 4)
			length = 2;
	}
	return (-1);
}
