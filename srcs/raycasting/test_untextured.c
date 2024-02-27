
// #include "cub3d.h"

// int	main_loop(t_elems *elems)
// {
// 	//rotation
// 	//movement
// 	if (! elems->mlx.server || !elems->mlx.window)
// 	{
// 		elems->error = 1;
// 		return (0);
// 	}
// 	calc(elems);
// 	return (0);

// }

// void	verLine(t_elems *elems, int x, int y1, int y2, int color)
// {
// 	int	y;

// 	y = y1;
// 	while (y <= y2)
// 	{
// 		mlx_pixel_put(elems->mlx.server, elems->mlx.window, x, y, color);
// 		y++;
// 	}
// }

// void	calc(t_elems *elems)
// {
// 	int	x;

// 	x = 0;
// 	while (x++ < WIDTH)
// 	{
// 		elems->cameraX = 2 * x / (double)WIDTH - 1;
// 		elems->rayDirX = elems->dirX + elems->planeX * elems->cameraX;
// 		elems->rayDirY = elems->dirY + elems->planeY * elems->cameraX;
// 		elems->mapX = (int)elems->posX;
// 		elems->mapY = (int)elems->posY;

// 		//length of ray from current position to next x or y-side
// 		//elems->sideDistX;
// 		//elems->sideDistY;

// 		 //length of ray from one x or y-side to next x or y-side
// 		if (elems->rayDirX == 0)
// 			elems->deltaDistX = 2147483647;
// 		else
// 			elems->deltaDistX = fabs(1 / elems->rayDirX);
// 		if (elems->rayDirY == 0)
// 			elems->deltaDistY = 2147483647;
// 		else
// 			elems->deltaDistY = fabs(1 / elems->rayDirY);

// 		//sideDist calculation
// 		if (elems->rayDirX < 0)
// 		{
// 			elems->stepX = -1;
// 			elems->sideDistX = (elems->posX - elems->mapX) * elems->deltaDistX;
// 		}
// 		else
// 		{
// 			elems->stepX = 1;
// 			elems->sideDistX = (elems->mapX + 1.0 - elems->posX) * elems->deltaDistX;
// 		}
// 		if (elems->rayDirY < 0)
// 		{
// 			elems->stepY = -1;
// 			elems->sideDistY = (elems->posY - elems->mapY) * elems->deltaDistY;
// 		}
// 		else
// 		{
// 			elems->stepY = 1;
// 			elems->sideDistY = (elems->mapY + 1.0 - elems->posY) * elems->deltaDistY;
// 		}

// 		//perpWalldist calculation
// 		while (elems->hit == 0)
// 		{
// 			/*****Jump to next map square, OR in x-direction, OR in y-direction*****/
// 			if (elems->sideDistX < elems->sideDistY)
// 			{
// 				elems->sideDistX += elems->deltaDistX;
// 				elems->mapX += elems->stepX;
// 				elems->side = 0; //HORIZONTAL side hit (x)
// 			}
// 			else
// 			{
// 				elems->sideDistY += elems->deltaDistY;
// 				elems->mapY += elems->stepY;
// 				elems->side = 1; //VERTICAL side hit (y)
// 			}

// 			//**********Check if ray has hit a wall**********//
// 			if ((elems->mapX < WIDTH) && (elems->mapY < HEIGHT) && (elems->map[elems->mapX][elems->mapY]== '1'))
// 				elems->hit = 1;
// 		}
// 		if (elems->side == 0) //HORIZONTAL
// 			//elems->perpWallDist = (elems->mapX - elems->posX + (1 - elems->stepX) / 2) / elems->rayDirX;
// 			elems->perpWallDist = elems->sideDistX - elems->deltaDistX;
// 		else //VERTICAL
// 			//elems->perpWallDist = (elems->mapY - elems->posY + (1 - elems->stepY) / 2) / elems->rayDirY;
// 			elems->perpWallDist = elems->sideDistY - elems->deltaDistY;

// 		/*****Calculate height of line to draw on screen*****/
// 		elems->line_height = (int)(1.5 * HEIGHT / elems->perpWallDist);

// 		/*****Calculate lowest and highest pixel to fill in current stripe*****/
// 		elems->draw_start = -elems->line_height / 2 + HEIGHT / 2;
// 		if(elems->draw_start < 0)
// 			elems->draw_start = 0;
// 		elems->draw_end = elems->line_height / 2 + HEIGHT / 2;
// 		if(elems->draw_end >= HEIGHT || elems->draw_end < 0)
// 			elems->draw_end = HEIGHT - 1;

// 		/*****Coloring time****/
// 		if (elems->map[elems->mapY][elems->mapX] == 1)
// 			elems->color = 0xFF0000; //RED
// 		else if (elems->map[elems->mapY][elems->mapX] == 2)
// 			elems->color = 0x00FF00; //GREEN
// 		else if (elems->map[elems->mapY][elems->mapX] == 3)
// 			elems->color = 0x0000FF; //BLUE
// 		else if (elems->map[elems->mapY][elems->mapX] == 4)
// 			elems->color = 0xFFFFFF; //WHITE
// 		else
// 			elems->color = 0xFFFFFF; //YELLOW

// 		if (elems->side == 1)
// 			elems->color = elems->color / 2;

// 		verLine(elems, x, elems->draw_start, elems->draw_end, elems->color);
// 	}
// }
// */
