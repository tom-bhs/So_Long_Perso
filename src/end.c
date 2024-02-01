/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbihoues <tbihoues@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 17:56:16 by tbihoues          #+#    #+#             */
/*   Updated: 2024/02/01 14:40:04 by tbihoues         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void frame_1(void *param)
{
    mlx_t *mlx = param;
    int newX = textureInfoArray[4].img->instances->x;
    int newY = textureInfoArray[4].img->instances->y;

    mlx_image_to_window(mlx, textureInfoArray[14].img, newX, newY); //blast
}

void frame_2(void *param)
{
    mlx_t *mlx = param;
    int x = 0;
    int y = 0;

    mlx_resize_image(textureInfoArray[15].img, WIN_WIDTH, WIN_HEIGHT);
    mlx_image_to_window(mlx, textureInfoArray[15].img, x, y);
}

void	frame_3(void *param)
{
	mlx_t *mlx = param;
	int x = 0;
	int y = 0;

	mlx_resize_image(textureInfoArray[16].img, WIN_WIDTH, WIN_HEIGHT);
	mlx_image_to_window(mlx, textureInfoArray[16].img, x, y);
}

void	frame_4(void *param)
{
	mlx_t *mlx = param;
	int x = 0;
	int y = 0;

	mlx_resize_image(textureInfoArray[17].img, WIN_WIDTH, WIN_HEIGHT);
	mlx_image_to_window(mlx, textureInfoArray[17].img, x, y);
}

void	frame_5(void *param)
{
	mlx_t *mlx = param;
	int x = 0;
	int y = 0;

	mlx_resize_image(textureInfoArray[18].img, WIN_WIDTH, WIN_HEIGHT);
	mlx_image_to_window(mlx, textureInfoArray[18].img, x, y);
}

void	frame_6(void *param)
{
	mlx_t *mlx = param;
	int x = 0;
	int y = 0;

	mlx_resize_image(textureInfoArray[19].img, WIN_WIDTH, WIN_HEIGHT);
	mlx_image_to_window(mlx, textureInfoArray[19].img, x, y);
}

void	frame_7(void *param)
{
	mlx_t *mlx = param;
	int x = 0;
	int y = 0;

	mlx_resize_image(textureInfoArray[20].img, WIN_WIDTH, WIN_HEIGHT);
	mlx_image_to_window(mlx, textureInfoArray[20].img, x, y);
}

void	frame_8(void *param)
{
	mlx_t *mlx = param;
	int x = 0;
	int y = 0;

	mlx_resize_image(textureInfoArray[21].img, WIN_WIDTH, WIN_HEIGHT);
	mlx_image_to_window(mlx, textureInfoArray[21].img, x, y);
}

void	frame_9(void *param)
{
	mlx_t *mlx = param;
	int x = 0;
	int y = 0;

	mlx_resize_image(textureInfoArray[22].img, WIN_WIDTH, WIN_HEIGHT);
	mlx_image_to_window(mlx, textureInfoArray[22].img, x, y);
}

void	frame_10(void *param)
{
	mlx_t *mlx = param;
	int x = 0;
	int y = 0;

	mlx_resize_image(textureInfoArray[23].img, WIN_WIDTH, WIN_HEIGHT);
	mlx_image_to_window(mlx, textureInfoArray[23].img, x, y);
}

void	frame_11(void *param)
{
	mlx_t *mlx = param;
	int x = 0;
	int y = 0;

	mlx_resize_image(textureInfoArray[24].img, WIN_WIDTH, WIN_HEIGHT);
	mlx_image_to_window(mlx, textureInfoArray[24].img, x, y);
}

void	frame_12(void *param)
{
	mlx_t *mlx = param;
	int x = 0;
	int y = 0;

	mlx_resize_image(textureInfoArray[25].img, WIN_WIDTH, WIN_HEIGHT);
	mlx_image_to_window(mlx, textureInfoArray[25].img, x, y);
}

void	frame_13(void *param)
{
	mlx_t *mlx = param;
	int x = 0;
	int y = 0;

	mlx_resize_image(textureInfoArray[26].img, WIN_WIDTH, WIN_HEIGHT);
	mlx_image_to_window(mlx, textureInfoArray[26].img, x, y);
}

void	frame_14(void *param) // game over
{
	mlx_t *mlx = param;
	int x = 0;
	int y = 0;

	mlx_resize_image(textureInfoArray[27].img, WIN_WIDTH, WIN_HEIGHT);
	mlx_image_to_window(mlx, textureInfoArray[27].img, x, y);
}

void (*frame_functions[])(void *) = {frame_1, frame_2, frame_3, frame_4, frame_5, frame_6, frame_7, frame_8, frame_9, frame_10, frame_11, frame_12, frame_13, frame_14};

void	animate_next_frame(void *param)
{
	static int frame = 0;
	static clock_t last_update = 0;
	mlx_t *mlx = param;
	clock_t now = clock();
	int newX;
	int newY;
	newX = textureInfoArray[4].img->instances->x;
	newY = textureInfoArray[4].img->instances->y;

	if ((double)(now - last_update) / CLOCKS_PER_SEC > 0.1)  // 0.1 seconds delay
	{
		if (textureInfoArray[8].img->instances->x == textureInfoArray[4].img->instances->x 
		&& textureInfoArray[8].img->instances->y == textureInfoArray[4].img->instances->y)
		{
			frame_functions[frame](mlx);
			frame = (frame + 1) % (sizeof(frame_functions) / sizeof(frame_functions[0]));
			if (frame == 0) // if all frames have been displayed, close the window
			{
				mlx_close_window(mlx);
			}
		}
		else if (mapy.mapp[newY / 32][newX / 32] == 'E'
		&& (textureInfoArray[2].img->count == mapy.nb_c))
		{
			mlx_image_to_window(mlx, textureInfoArray[14].img, newX, newY);
			mlx_close_window(mlx);
		}
		last_update = now;
	}
}


// bool isCollision = false;

// void animate_next_frame(void *param)
// {
// 	static int frame = 0;
// 	static clock_t last_update = 0;
// 	mlx_t *mlx = param;
// 	clock_t now = clock();
// 	int newX;
// 	int newY;
// 	newX = textureInfoArray[4].img->instances->x;
// 	newY = textureInfoArray[4].img->instances->y;

// 	if ((double)(now - last_update) / CLOCKS_PER_SEC > 0.1)  // 0.1 seconds delay
// 	{
// 		if (textureInfoArray[8].img->instances->x == textureInfoArray[4].img->instances->x 
// 		&& textureInfoArray[8].img->instances->y == textureInfoArray[4].img->instances->y)
// 		{
// 			isCollision = true;
// 			frame_functions[frame](mlx);
// 			frame = (frame + 1) % (sizeof(frame_functions) / sizeof(frame_functions[0]));
// 			if (frame == 0) // if all frames have been displayed, close the window
// 			{
// 				mlx_close_window(mlx);
// 			}
// 		}
// 		else if (mapy.mapp[newY / 32][newX / 32] == 'E'
// 		&& (textureInfoArray[2].img->count == mapy.nb_c))
// 		{
// 			mlx_image_to_window(mlx, textureInfoArray[14].img, newX, newY);
// 			mlx_close_window(mlx);
// 		}
// 		last_update = now;
// 	}
// }

// void move_character(/* parameters */)
// {
// 	if (isCollision)
// 	{
// 		return;
// 	}
// }

// void move_barrel(/* parameters */)
// {
// 	if (isCollision)
// 	{
// 		return;
// 	}
// }