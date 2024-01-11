/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   element_chose.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-siga <ede-siga@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 12:12:20 by ede-siga          #+#    #+#             */
/*   Updated: 2024/01/11 12:35:06 by ede-siga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

t_elems	assign_which_elem(char *str, int nb, t_elems elems)
{
	if (nb < 4)
		elems = gt_str_atrib(elems, str);
	else
		elems = get_nbr_atribs(elems, str);
	return (elems);
}

int	elem_type(char *temp, char **str)
{
	int	i;
	int	length;

	length = 2;
	i = 0;
	while (str[i])
	{
		if (!ft_strncmp(str[i], temp, length))
			return (i);
		i++;
		if (i == 4)
			length = 1;
	}
	return (-1);
}
