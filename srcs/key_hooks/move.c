/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hesong <hesong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 17:26:56 by hesong            #+#    #+#             */
/*   Updated: 2024/02/19 10:49:14 by hesong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	is_wall(char c)
{
	if (c == '1')
		return (1);
	return (0);
}

bool	key_w(t_elems *elems, bool reload)
{
	if (!is_wall(elems->map[(int)(elems->posX
				+ (elems->dirX * elems->move_speed * 2))][(int)elems->posY]))
		elems->posX += elems->dirX * elems->move_speed;
	if (!is_wall(elems->map[(int)(elems->posX)][(int)(elems->posY
		+ (elems->dirY * elems->move_speed * 2))]))
		elems->posY += elems->dirY * elems->move_speed;
	reload = true;
	return (reload);
}


bool	key_s(t_elems *elems, bool reload)
{
	if (!is_wall(elems->map[(int)(elems->posX
				- (elems->dirX * elems->move_speed * 2))][(int)(elems->posY)]))
		elems->posX -= elems->dirX * elems->move_speed;
	if (!is_wall(elems->map[(int)(elems->posX)][(int)(elems->posY
		- (elems->dirY * elems->move_speed * 2))]))
		elems->posY -= elems->dirY * elems->move_speed;
	reload = true;
	return (reload);
}

bool	key_d(t_elems *elems, bool reload)
{
	if (!is_wall(elems->map[(int)(elems->posX - elems->dirY
				* (elems->move_speed * 2))][(int)elems->posY]))
		elems->posX -= elems->dirY * elems->move_speed;
	if (!is_wall(elems->map[(int)elems->posX][(int)(elems->posY + elems->dirX
			* (elems->move_speed * 2))]))
		elems->posY += elems->dirX * elems->move_speed;
	reload = true;
	return (reload);
}

bool	key_a(t_elems *elems, bool reload)
{
	if (!is_wall(elems->map[(int)(elems->posX + elems->dirY
				* (elems->move_speed * 2))][(int)elems->posY]))
		elems->posX += elems->dirY * elems->move_speed;
	if (!is_wall(elems->map[(int)elems->posX][(int)(elems->posY - elems->dirX
			* (elems->move_speed * 2))]))
		elems->posY -= elems->dirX * elems->move_speed;
	reload = true;
	return (reload);
}

int move(t_elems *elems)
{
	bool	reload;

	reload = false;
	if (elems->w)
		reload = key_w(elems, reload);
	if (elems->s)
		reload = key_s(elems, reload);
	if (elems->d)
		reload = key_d(elems, reload);
	if (elems->a)
		reload = key_a(elems, reload);
	return (0);

}
