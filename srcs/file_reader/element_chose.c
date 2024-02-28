/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   element_chose.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hesong <hesong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 12:12:20 by ede-siga          #+#    #+#             */
/*   Updated: 2024/02/28 18:25:37 by hesong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

t_elems	check_colors(t_elems elems, int type, int color[3])
{
	int	i;

	i = 0;
	while (i < 3)
	{
		if ((color[i] > 255 || color[i] < 0) && !elems.error)
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

/*
str = line
nb = type
*/

t_elems	assign_which_elem(char *str, int nb, t_elems elems)
{
	while (*str && *str == ' ')
		str++;
	if (nb < 4) // NSWE
		elems = get_str_atrib(elems, str);
	else //FC
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


/*
type = 0 -> NO
type = 1 -> SO
type = 2 -> WE
type = 3 -> EA
type = 4 -> C
type = 5 -> F

*/
int	elem_type(char *temp, char **str)
{
	int	i;
	int	length;

	length = 3;
	i = 0;
	//printf("temp in elem_type(): %s\n",temp);
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
