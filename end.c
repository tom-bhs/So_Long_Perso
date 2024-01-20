/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbihoues <tbihoues@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 17:56:16 by tbihoues          #+#    #+#             */
/*   Updated: 2024/01/19 18:26:57 by tbihoues         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MLX42/include/MLX42/MLX42.h"
#include "src/get_next_line.h"
#include "src/so_long.h"
#include "mouv_perso.c"

void	finish(void)
{
    mlx_t						*mlx;
    int							newX;
	int							newY;

	newX = textureInfoArray[4].img->instances->x;
	newY = textureInfoArray[4].img->instances->y;


if (textureInfoArray[8].img->instances->x == textureInfoArray[4].img->instances->x 
	&& textureInfoArray[8].img->instances->y == textureInfoArray[4].img->instances->y)
	{
		mlx_image_to_window(mlx, textureInfoArray[14].img, newX, newY);
		//wait();
		mlx_close_window(mlx);
		// mlx_resize_image(textureInfoArray[15].img, WIN_WIDTH, WIN_HEIGHT);
		// mlx_image_to_window(mlx, textureInfoArray[15].img, x, y);
		// wait();
		// mlx_resize_image(textureInfoArray[16].img, WIN_WIDTH, WIN_HEIGHT);
		// mlx_image_to_window(mlx, textureInfoArray[16].img, x, y);
		// wait();
		// mlx_resize_image(textureInfoArray[17].img, WIN_WIDTH, WIN_HEIGHT);
		// mlx_image_to_window(mlx, textureInfoArray[17].img, x, y);
		// wait();
		// mlx_resize_image(textureInfoArray[18].img, WIN_WIDTH, WIN_HEIGHT);
		// mlx_image_to_window(mlx, textureInfoArray[18].img, x, y);
		// wait();
		// mlx_resize_image(textureInfoArray[19].img, WIN_WIDTH, WIN_HEIGHT);
		// mlx_image_to_window(mlx, textureInfoArray[19].img, x, y);
		// wait();
		// mlx_resize_image(textureInfoArray[20].img, WIN_WIDTH, WIN_HEIGHT);
		// mlx_image_to_window(mlx, textureInfoArray[20].img, x, y);
		// wait();
		// mlx_resize_image(textureInfoArray[21].img, WIN_WIDTH, WIN_HEIGHT);
		// mlx_image_to_window(mlx, textureInfoArray[21].img, x, y);
		
		//mlx_resize_image(textureInfoArray[15].img, 1224, 512);
		// mlx_image_to_window(mlx, textureInfoArray[16].img, x , y);
		// mlx_image_to_window(mlx, textureInfoArray[17].img, x , y);
		// mlx_image_to_window(mlx, textureInfoArray[18].img, x , y);
		// mlx_image_to_window(mlx, textureInfoArray[19].img, x , y);
		// mlx_image_to_window(mlx, textureInfoArray[20].img, x , y);
		// mlx_image_to_window(mlx, textureInfoArray[21].img, x , y);
		// mlx_image_to_window(mlx, textureInfoArray[22].img, x , y);
		// mlx_image_to_window(mlx, textureInfoArray[23].img, x , y);
		// mlx_image_to_window(mlx, textureInfoArray[24].img, x , y);
		// mlx_image_to_window(mlx, textureInfoArray[25].img, x , y);
		// mlx_image_to_window(mlx, textureInfoArray[26].img, x , y);
		//mlx_close_window(mlx);
	}
}