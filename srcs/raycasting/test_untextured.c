
#include "cub3d.h"

int	main_loop(t_elems *elems)
{
	calc(elems);
	//mlx_put_image_to_window(mlx->server, mlx->window, mlx->img, 0, 0);
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
	while (x < WIDTH)
	{
		double cameraX = 2 * x / (double)WIDTH - 1;
		double rayDirX = elems->dir.x + elems->plane.x * cameraX;
		double rayDirY = elems->dir.y + elems->plane.y * cameraX;

		int mapX = (int)elems->pos.x;
		int mapY = (int)elems->pos.y;

		//length of ray from current position to next x or y-side
		double sideDistX;
		double sideDistY;

		 //length of ray from one x or y-side to next x or y-side
		double deltaDistX = fabs(1 / rayDirX);
		double deltaDistY = fabs(1 / rayDirY);
		double perpWallDist;

		//what direction to step in x or y-direction (either +1 or -1)
		int stepX;
		int stepY;

		int hit = 0; //was there a wall hit?
		int side; //was a NS or a EW wall hit?

		if (rayDirX < 0)
		{
			stepX = -1;
			sideDistX = (elems->pos.x - mapX) * deltaDistX;
		}
		else
		{
			stepX = 1;
			sideDistX = (mapX + 1.0 - elems->pos.x) * deltaDistX;
		}
		if (rayDirY < 0)
		{
			stepY = -1;
			sideDistY = (elems->pos.y - mapY) * deltaDistY;
		}
		else
		{
			stepY = 1;
			sideDistY = (mapY + 1.0 - elems->pos.y) * deltaDistY;
		}

		while (hit == 0)
		{
			//jump to next map square, OR in x-direction, OR in y-direction
			if (sideDistX < sideDistY)
			{
				sideDistX += deltaDistX;
				mapX += stepX;
				side = 0;
			}
			else
			{
				sideDistY += deltaDistY;
				mapY += stepY;
				side = 1;
			}
			//Check if ray has hit a wall
			if (elems->map[mapX][mapY] > 0) hit = 1;
		}
		if (side == 0)
			perpWallDist = (mapX - elems->pos.x + (1 - stepX) / 2) / rayDirX;
		else
			perpWallDist = (mapY - elems->pos.y + (1 - stepY) / 2) / rayDirY;

		//Calculate height of line to draw on screen
		int lineHeight = (int)(HEIGHT / perpWallDist);

		//calculate lowest and highest pixel to fill in current stripe
		int drawStart = -lineHeight / 2 + HEIGHT / 2;
		if(drawStart < 0)
			drawStart = 0;
		int drawEnd = lineHeight / 2 + HEIGHT / 2;
		if(drawEnd >= HEIGHT)
			drawEnd = HEIGHT - 1;

		int	color;
		if (elems->map[mapY][mapX] == 1)
			color = 0xFF0000;
		else if (elems->map[mapY][mapX] == 2)
			color = 0x00FF00;
		else if (elems->map[mapY][mapX] == 3)
			color = 0x0000FF;
		else if (elems->map[mapY][mapX] == 4)
			color = 0xFFFFFF;
		else
			color = 0xFFFF00;

		if (side == 1)
			color = color / 2;

		verLine(elems, x, drawStart, drawEnd, color);

		x++;
	}
}
