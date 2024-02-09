
#include "cub3d.h"

int	main_loop(t_elems *elems)
{
	calc(elems);
	mlx_put_image_to_window(elems->mlx.server, elems->mlx.window, elems->mlx.img, 0, 0);
	return (0);

}

void	verLine(t_elems *elems, int x, int y1, int y2, int color)
{
	int	y;

	y = y1;
	while (y <= y2)
	{
		mlx_pixel_put(elems->mlx.server, elems->mlx.window, x, y, color);
		y++;
	}
}

void	calc(t_elems *elems)
{
	int	x;

	x = 0;
	while (x++ < WIDTH)
	{
		printf("\nx: %d\n", x);
		elems->cameraX = 2 * x / (double)WIDTH - 1;
		//printf("cameraX: %f\n", elems->cameraX);
		elems->rayDirX = elems->dirX + elems->planeX * elems->cameraX;
		printf("rayDirX: %f\n", elems->rayDirX);
		elems->rayDirY = elems->dirY + elems->planeY * elems->cameraX;
		printf("rayDirY: %f\n", elems->rayDirY);

		elems->mapX = (int)elems->posX;
		printf("mapX: %d\n", elems->mapX);
		elems->mapY = (int)elems->posY;
		printf("mapY: %d\n", elems->mapY);

		//length of ray from current position to next x or y-side
		//elems->sideDistX;
		//elems->sideDistY;

		 //length of ray from one x or y-side to next x or y-side
		elems->deltaDistX = fabs(1 / elems->rayDirX);
		printf("deltaDistX: %f\n", elems->deltaDistX);
		elems->deltaDistY = fabs(1 / elems->rayDirY);
		printf("deltaDistY: %f\n", elems->deltaDistY);
		//elems->perpWallDist;

		//what direction to step in x or y-direction (either +1 or -1)
		//elems->stepX;
		//elems->stepY;

		elems->hit = 0; // initializing hit flag, this is to know if a wall is hit.
		//elems->side; //was a NS or a EW wall hit?
		if (elems->rayDirX < 0)
		{
			elems->stepX = -1;
			printf("Because rayDirX is %f, current stepX is %d\n", elems->rayDirX, elems->stepX);
			elems->sideDistX = (elems->posX - elems->mapX) * elems->deltaDistX;
			printf("sideDistX: %f\n", elems->sideDistX);
		}
		else
		{
			elems->stepX = 1;
			printf("Because rayDirX is %f, current stepX is %d\n", elems->rayDirX, elems->stepX);
			elems->sideDistX = (elems->mapX + 1.0 - elems->posX) * elems->deltaDistX;
			printf("sideDistX: %f\n", elems->sideDistX);
		}
		if (elems->rayDirY < 0)
		{
			elems->stepY = -1;
			printf("Because rayDirY is %f, current stepY is %d\n", elems->rayDirY, elems->stepY);
			elems->sideDistY = (elems->posY - elems->mapY) * elems->deltaDistY;
			printf("sideDistY: %f\n", elems->sideDistY);
		}
		else
		{
			elems->stepY = 1;
			printf("Because rayDirY is %f, current stepY is %d\n", elems->rayDirY, elems->stepY);
			elems->sideDistY = (elems->mapY + 1.0 - elems->posY) * elems->deltaDistY;
			printf("sideDistY: %f\n", elems->sideDistY);

		}
		printf("hit: %d\n", elems->hit);
		while (elems->hit == 0)
		{
			/*****Jump to next map square, OR in x-direction, OR in y-direction*****/
			if (elems->sideDistX < elems->sideDistY)
			{
				printf("sideDistX: %f\n", elems->sideDistX);
				elems->sideDistX += elems->deltaDistX;
				printf("sideDistX + deltaDistX: %f\n", elems->sideDistX);
				printf("mapX: %d\n", elems->mapX);
				elems->mapX += elems->stepX;
				printf("mapX + stepX: %d\n", elems->mapX);
				elems->side = 0;
			}
			else
			{
				printf("sideDistY: %f\n", elems->sideDistY);
				printf("deltaDistY: %f\n", elems->deltaDistY);
				elems->sideDistY += elems->deltaDistY;
				printf("sideDistY + deltaDistY: %f\n", elems->sideDistY);
				printf("mapY: %d\n", elems->mapY);
				printf("stepY: %d\n", elems->stepY);
				elems->mapY += elems->stepY;
				printf("mapY + stepY = %d\n", elems->mapY);
				elems->side = 1;
				printf("side: %d\n", elems->side);
			}

			//**********Check if ray has hit a wall**********//
			//print_elems_map(elems); //debug
			printf("map[%d][%d]:%c\n", elems->mapX, elems->mapY, elems->map[elems->mapX][elems->mapY]);
			//segfault when mapX, mapY is outside of the map. So we need to check before.
			if ((elems->mapX < WIDTH) && (elems->mapY < HEIGHT) && (elems->map[elems->mapX][elems->mapY]== '1'))
				elems->hit = 1;
		}
		if (elems->side == 0) //HORIZONTAL
			elems->perpWallDist = (elems->mapX - elems->posX + (1 - elems->stepX) / 2) / elems->rayDirX;
		else
			elems->perpWallDist = (elems->mapY - elems->posY + (1 - elems->stepY) / 2) / elems->rayDirY;

		/*****Calculate height of line to draw on screen*****/
		elems->line_height = (int)(HEIGHT / elems->perpWallDist);

		/*****Calculate lowest and highest pixel to fill in current stripe*****/
		elems->draw_start = -(elems->line_height) / 2 + HEIGHT / 2;
		printf("draw_start: %d\n", elems->draw_start);
		if(elems->draw_start < 0)
			elems->draw_start = 0;
		elems->draw_end = elems->line_height / 2 + HEIGHT / 2;
		printf("draw_end: %d\n", elems->draw_end);
		if(elems->draw_end >= HEIGHT)
			elems->draw_end = HEIGHT - 1;

		/*****Coloring time****/
		printf("map[%d][%d]:%c\n", elems->mapX, elems->mapY, elems->map[elems->mapX][elems->mapY]);
		if (elems->map[elems->mapY][elems->mapX] == 1)
			elems->color = 0xFF0000; //RED
		else if (elems->map[elems->mapY][elems->mapX] == 2)
			elems->color = 0x00FF00; //GREEN
		else if (elems->map[elems->mapY][elems->mapX] == 3)
			elems->color = 0x0000FF; //BLUE
		else if (elems->map[elems->mapY][elems->mapX] == 4)
			elems->color = 0xFFFFFF; //WHITE
		else
			elems->color = 0xFFFFFF; //YELLOW

		if (elems->side == 1)
			elems->color = elems->color / 2;
		verLine(elems, x, elems->draw_start, elems->draw_end, elems->color);
		//x++;
		printf("\n");
	}
}
