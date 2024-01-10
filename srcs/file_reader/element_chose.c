/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   element_chose.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-siga <ede-siga@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 12:12:20 by ede-siga          #+#    #+#             */
/*   Updated: 2024/01/10 18:19:32 by ede-siga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

t_elem	assign_which_elem(char *str, int nb, t_elem elems)
{
	if (nb < 5)
		elems = gt_str_atrib(elems, str, nb);
	else
		get_nbr_atrib(elems, str);
}

int	elem_type(char *temp, char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!ft_strncmp(str[i], temp, 2))
			return (i);
		i++;
	}
	return (-1);
}
