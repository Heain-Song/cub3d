/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hesong <hesong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 17:32:00 by hesong            #+#    #+#             */
/*   Updated: 2024/02/18 17:42:01 by hesong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int key_press(int keycode, t_elems *elems)
{
	if (keycode == FORWARD)
		elems->w = true;
	if (keycode == BACK)
		elems->s = true;
	if (keycode == LEFT)
		elems->a = true;
	if (keycode == RIGHT)
		elems->d = true;
	if (keycode == ROTATE_LEFT)
		elems->rotate_left = true;
	if (keycode == ROTATE_RIGHT)
		elems->rotate_right = true;
	return (0);
}

int key_release(int keycode, t_elems *elems)
{
	if (keycode == FORWARD)
		elems->w = false;
	if (keycode == BACK)
		elems->s = false;
	if (keycode == LEFT)
		elems->a = false;
	if (keycode == RIGHT)
		elems->d = false;
	if (keycode == ROTATE_LEFT)
		elems->rotate_left = false;
	if (keycode == ROTATE_RIGHT)
		elems->rotate_right = false;
	return (0);
}
